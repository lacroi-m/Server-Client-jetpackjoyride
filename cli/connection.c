/*
** connection.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 13:56:34 2017 Maxime Lacroix
** Last update Fri Jul 14 17:00:03 2017 Maxime Lacroix
*/

#include "communication.h"

char	*hostname_to_ip(char *hostname)
{
  struct hostent *he;
  if (!(he = gethostbyname(hostname)))
    return (NULL);

  struct in_addr **addr_list;
  addr_list = (struct in_addr **)he->h_addr_list;
  if (!(*addr_list))
    return (NULL);

  return inet_ntoa(*addr_list[0]);
}


void	init_communication(unsigned short port, char *ip)
{
  struct sockaddr_in s_in;
  struct protoent    *pro;

  com = malloc(sizeof(t_com) * 2);
  if ((pro = getprotobyname("TCP")) == NULL)
    exit_error();
  if (!(com->com_fd = socket(AF_INET, SOCK_STREAM, pro->p_proto)))
    exit_error();
  bzero(&s_in, sizeof(struct sockaddr_in));
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(hostname_to_ip(ip));  
  if (connect(com->com_fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    exit_error();
}

int canReceive()
{
  fd_set rfds;
  struct timeval tv;
  int retval;

  FD_ZERO(&rfds);
  FD_SET(com->com_fd, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 100;
  retval = select(com->com_fd + 1, &rfds, NULL, NULL, &tv);
  
  if (retval == -1)
    exit_error();
  else if (retval)
    return (0);
  else
    return (-1);
  return (-1);
}

int	findreturn(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '\n')
	return (i);
    }
  return (i);
}

char	*receiveit(int isBlock)
{
  (void)isBlock;
  char	buf[256];
  char	*tmp;
  int	i;
  int	j;
  
  i = 0;
  bzero(&buf, 256);
  i = read(com->com_fd, &buf, 256);
  if (i > 0)
    {
      j = i;
      tmp = malloc(sizeof(char) * i + 1);
      tmp = strncpy(tmp, buf, i);
      while (!canReceive())
	{
	  bzero(&buf, 256);
	  i = i + read(com->com_fd, &buf, 256);
	  j = i - j;
	  tmp = realloc(tmp, sizeof(char) * j + 1);
	  tmp = strncat(tmp, buf, j);
	}
      tmp[i] = '\0';
      return (tmp);
    }
  return (NULL);
}

int	sendit(char *msg)
{
  if (my_strlen(msg) >= 256)
    return (-1);
  write(com->com_fd, &msg, my_strlen(msg));
  return (0);
}

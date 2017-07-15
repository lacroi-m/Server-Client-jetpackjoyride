/*
** connection.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 13:56:34 2017 Maxime Lacroix
** Last update Sat Jul 15 17:07:24 2017 Maxime Lacroix
*/

#include "communication.h"

int canReceive(int com_fd)
{
  fd_set rfds;
  struct timeval tv;
  int retval;

  FD_ZERO(&rfds);
  FD_SET(com_fd, &rfds);
  tv.tv_sec = 0;
  tv.tv_usec = 100;
  retval = select(com_fd + 1, &rfds, NULL, NULL, &tv);
  
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

char	*cutreturn(char *str)
{
  int	pos;
  char	*nstr;
  
  pos = -1;
  while (str[++pos] && str[pos] != '\n');
  nstr = malloc(sizeof(char) * pos + 1);
  nstr = strncat(nstr, str, pos);
  nstr[pos + 1] = '\0';

  return (nstr);
}

char	*receiveit(int isBlock, int com_fd)
{
  (void)isBlock;
  char	buf[256];
  char	*tmp;
  int	i;
  int	j;

  tmp = NULL;
  i = 0;
  bzero(&buf, 256);
  j = i;
  while (!canReceive(com_fd))
    {
      bzero(&buf, 256);
      i = i + read(com_fd, &buf, 255);
      j = i - j;
      if (tmp == NULL && i > 0)
	{
	  tmp = malloc(sizeof(char) * i + 1);
	  tmp = strncpy(tmp, buf, i);
	}
      else if (j > 0)
	{
	  tmp = realloc(tmp, sizeof(char) * j + 1);
	  tmp = strncat(tmp, buf, j);
	}
    }
  if (tmp == NULL)
    return (NULL);
  tmp[i] = '\0';
  return (cutreturn(tmp));
}

int	sendit(char *msg, int com_fd)
{
  if (my_strlen(msg) >= 256)
    return (-1);
  write(com_fd, &msg, my_strlen(msg) + 1);
  return (0);
}

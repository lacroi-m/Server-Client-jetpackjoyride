/*
** connection.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
**
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
**
** Started on  Thu Jul 13 13:56:34 2017 Maxime Lacroix
** Last update Sun Jul 16 19:37:32 2017 Maxime Lacroix
*/

#include "communication.h"
#include <sys/types.h>
#include <sys/socket.h>
int canReceive(int com_fd)
{
  (void) com_fd;
  /*
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
  return (-1);*/
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

char	*receiveit(int isBlock, int com_fd)
{
  (void)isBlock;
  char	buf[256];
  char *str;
  fd_set	fds;
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 1;
  memset(buf,0,256);
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  FD_SET(com_fd, &fds);
  
  printf("bfor select\n");
  if (select(com_fd + 1, &fds, NULL, NULL, &tv) == -1)
    exit_error();
  printf("after select\n");
  
  
  if (FD_ISSET(com_fd, &fds))
    {
      if (recv(com_fd, &buf, 256, 0) == -1)
	{
	  printf("error read\n");
	  exit_error();
	}
    }
  if (buf != NULL)
    {
      str = malloc(sizeof(char) * my_strlen(buf) + 1);
      str = strcpy(str, buf);
    }
  return (str);
}

int	sendit(char *msg, int com_fd)
{
  if (my_strlen(msg) >= 256)
    return (-1);
  write(com_fd, &msg, my_strlen(msg) + 1);
  return (0);
}

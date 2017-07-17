/*
** connection.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
**
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
**
** Started on  Thu Jul 13 13:56:34 2017 Maxime Lacroix
** Last update Mon Jul 17 12:16:01 2017 Maxime Lacroix
*/

#include "communication.h"
#include <sys/types.h>
#include <sys/socket.h>

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

void	my_select(int isBlock, int com_fd, fd_set *fds, struct timeval tv)
{
  if (isBlock == 0)
    if (select(com_fd + 1, fds, NULL, NULL, &tv) == -1)
      exit_error();
  if (isBlock != 0)
    if (select(com_fd + 1, fds, NULL, NULL, NULL) == -1)
      exit_error();
}

char	*receiveit(int isBlock, int com_fd)
{
  char		buf[256];
  char		*str;
  fd_set	fds;
  struct timeval tv;
  int		i;

  tv.tv_sec = 0;
  tv.tv_usec = 1;
  memset(buf,0,256);
  FD_ZERO(&fds);
  FD_SET(0, &fds);
  FD_SET(com_fd, &fds);
  my_select(isBlock, com_fd, &fds, tv);
  if (FD_ISSET(com_fd, &fds))
    if ((i = recv(com_fd, &buf, 256, 0)) == -1)
      exit_error();
  if (buf != NULL)
    {
      str = malloc(sizeof(char) * i + 1);
      str = strncpy(str, buf, i);
      str[i] = 0;
    }
  return (str);
}

int	sendit(int com_fd, char *msg)
{
  int	i;
  if ((i = dprintf(com_fd, msg)) == -1)
    return (-1);
  return (i);
}

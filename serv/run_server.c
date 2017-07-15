/*
** run_server.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Fri Jul 14 13:25:43 2017 dorian turba
** Last update Sat Jul 15 10:54:14 2017 dorian turba
*/

#include "serv.h"

int	get_fd_max(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write)
{
  int	fd_max;
  int	i;

  FD_ZERO(fd_read);
  FD_ZERO(fd_write);
  fd_max = 0;
  for (i = 0; i < MAX_FD; i++)
    {
      if (data_server->fd_type[i] != FD_FREE)
	{
	  FD_SET(i, fd_read);
	  FD_SET(i, fd_write);
	  fd_max = i;
	}
    }
  return (fd_max);
}

int	my_select(int fd_max, fd_set *fd_read, fd_set *fd_write)
{
  struct timeval	tv;

  tv.tv_sec = 20;
  tv.tv_usec = 0;
  if (select(fd_max + 1, fd_read, fd_write, NULL, &tv) == -1)
    return (error(SELECT));
  return (0);
}

void	my_isset(t_data_server *data_server, fd_set *fd_read, fd_set *fd_write)
{
  int	i;

  for (i = 0; i < MAX_FD; i++)
    {
      if (FD_ISSET(i, fd_read))
	data_server->fct_read[i](data_server, i);
      else if (FD_ISSET(i, fd_write))
	data_server->fct_write[i](data_server, i);
    }
}

int	run_server(t_data_server *data_server)
{
  fd_set	fd_write;
  fd_set	fd_read;
  int		fd_max;

  fd_max = get_fd_max(data_server, &fd_read, &fd_write);
  printf("fd max = %d\n", fd_max);
  if (my_select(fd_max, &fd_read, &fd_write) == 84)
    return (84);
  my_isset(data_server, &fd_read, &fd_write);
  return (0);
}

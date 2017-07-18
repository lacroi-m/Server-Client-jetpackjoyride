/*
** game.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 16:42:01 2017 dorian turba
** Last update Tue Jul 18 14:22:05 2017 dorian turba
*/

#include "serv.h"

int	all_ready(t_data_server *data_server)
{
  int	how_much;

  how_much = 0;
  for (int i = 0; i < MAX_FD; ++i)
    if (data_server->clients[i].fd)
      if (data_server->clients[i].is_ready)
	how_much += 1;
  if (how_much == 2)
    return (1);
  return (0);
}

void	start(t_data_server *data_server)
{
  for (int i = 0; i < MAX_FD; ++i)
    if (data_server->clients[i].fd)
      data_server->clients[i].msg = strdup("START");
}

void	reload(t_data_server *data_server)
{
  player_cmd(data_server);
  /*  for (int i = 0; i < MAX_FD; ++i)
    if (data_server->clients[i].fd)
      {
      }
  */
}

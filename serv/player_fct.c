/*
** player_fct.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Sun Jul 16 14:27:45 2017 dorian turba
** Last update Wed Jul 19 00:42:36 2017 dorian turba
*/

#include "serv.h"

void	id(t_data_server *data_server, int fd, int fire)
{
  (void)fire;
  data_server->clients[fd].msg = malloc(sizeof(char) * 5);
  sprintf(data_server->clients[fd].msg, "ID %d", data_server->clients[fd].id);
  printf("send : %s\n", data_server->clients[fd].msg);
}

void	map(t_data_server *data_server, int fd, int fire)
{
  (void)fire;
  data_server->clients[fd].msg =
    malloc(sizeof(char) * (50 + strlen(data_server->map)));
  //  printf("DEBUG1\n");
  sprintf(data_server->clients[fd].msg, "MAP %d %d %s",
	  data_server->width, data_server->height,
	  data_server->map);
  //  printf("DEBUG2\n");
  //  printf("send : %s", data_server->clients[fd].msg);
  //  printf("DEBUG3\n");
}

void	ready(t_data_server *data_server, int fd, int fire)
{
  (void)fire;
  data_server->clients[fd].is_ready = 1;
}

void	fire(t_data_server *data_server, int fd, int fire)
{
  if (fire)
    data_server->clients[fd].jet_on_fire = 1;
  else
    data_server->clients[fd].jet_on_fire = -1;
}

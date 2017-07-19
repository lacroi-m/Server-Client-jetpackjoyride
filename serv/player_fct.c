/*
** player_fct.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Sun Jul 16 14:27:45 2017 dorian turba
** Last update Wed Jul 19 23:14:50 2017 Maxime Lacroix
*/

#include "serv.h"

void	id(t_data_server *data_server, int fd, int fire)
{
  char	*tmp;

  (void)fire;
  tmp = malloc(sizeof(char) * 5);
  data_server->clients[fd].msg =
    realloc(data_server->clients[fd].msg, sizeof(char) *
	    (5 + strlen(data_server->clients[fd].msg)));
  sprintf(tmp, "ID %d\n", data_server->clients[fd].id);
  strcat(data_server->clients[fd].msg, tmp);
}

void	map(t_data_server *data_server, int fd, int fire)
{
  char	*tmp;

  (void)fire;
  tmp = malloc(sizeof(char) * (50 + strlen(data_server->map)));
  data_server->clients[fd].msg =
    realloc(data_server->clients[fd].msg, sizeof(char) *
	    (50 + strlen(data_server->map +
			 strlen(data_server->clients[fd].msg))));
  sprintf(tmp, "MAP %d %d %s\n", data_server->width, data_server->height,
	  data_server->map);
  strcat(data_server->clients[fd].msg, tmp);
  free(tmp);
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

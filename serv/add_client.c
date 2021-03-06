/*
** add_client.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Fri Jul 14 13:52:59 2017 dorian turba
** Last update Wed Jul 19 18:20:13 2017 dorian turba
*/

#include "serv.h"

void	init_client(t_client *client, int fd, t_data_server *data_server)
{
  client->msg = strdup("");
  client->fd = fd;
  client->pos_x = 0;
  client->pos_y = data_server->height / 2;
  client->speed = 0;
  client->coins = 0;
  client->is_ready = 0;
  client->jet_on_fire = 1;
  client->id = data_server->connected_player;
}

void	add_client(t_data_server *data_server, int s)
{
  int cs;
  struct sockaddr_in client_sin;
  unsigned int client_sin_len;
  t_client	*client;

  client_sin_len = sizeof(client_sin);
  if ((cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len)) == -1)
    {
      close(cs);
      exit(1);
    }
  if (++data_server->connected_player > 2)
    {
      (void)((data_server->connected_player -= 1) && (close(cs)));
      return;
    }
  data_server->fd_type[cs] = FD_CLIENT;
  data_server->fct_read[cs] = client_read;
  data_server->fct_write[cs] = client_write;
  client = &(data_server->clients[cs]);
  init_client(client, cs, data_server);
}

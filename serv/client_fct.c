/*
** client_fct.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Fri Jul 14 15:13:58 2017 dorian turba
** Last update Mon Jul 17 11:24:01 2017 dorian turba
*/

#include "serv.h"

void	make_msg(char *txt, t_client *client)
{
  char	*msg;

  msg = malloc(sizeof(char) * strlen(txt));
  sprintf(msg, "%s", txt);
  client->msg = strdup(msg);
  free(msg);
}

void	client_write(t_data_server *data_server, int fd)
{
  if (data_server->clients[fd].msg)
    {
      dprintf(fd, "%s\r\n", data_server->clients[fd].msg);
      free(data_server->clients[fd].msg);
    }
  data_server->clients[fd].msg = NULL;
}

void client_read(t_data_server *data_server, int fd)
{
  int r;
  char	buf[4096];

  r = read(fd, buf, 4096);
  if (r > 0)
    {
      buf[r - 1] = '\0';
      printf("Client command : %s\n", buf);
      manage_cmd_server(buf, data_server, fd);
    }
  else
    {
      printf("%d: Connection closed\n", fd);
      close(fd);
      data_server->fd_type[fd] = FD_FREE;
      data_server->connected_player -= 1;
    }
}


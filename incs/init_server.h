/*
** init_server.h<incs> for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/incs
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Thu Jul 13 10:34:46 2017 dorian turba
** Last update Mon Jul 17 18:50:29 2017 dorian turba
*/

#ifndef INIT_SERVER_H
# define INIT_SERVER_H

# define MAX_FD 255
# define FD_FREE 0
# define FD_CLIENT 1
# define FD_SERVER 2

typedef void(*fct)();

typedef struct	s_client
{
  char		*msg;
  int		fd;
  int		pos_x;
  int		pos_y;
  int		coins;
  int		speed;
  int		id;
  int		is_ready;
  int		jet_on_fire;
}		t_client;

typedef struct	s_data_server
{
  char			fd_type[MAX_FD];
  int			port;
  fct			fct_read[MAX_FD];
  fct			fct_write[MAX_FD];
  int			fd_server;
  int			client_nbr;
  t_client		clients[MAX_FD];
  int			width;
  int			height;
  int			start;
  char			*map;
  struct s_data_flags	*data_flags;
  int			connected_player;
}		t_data_server;

#endif /* !INIT_SERVER_H */

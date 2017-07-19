/*
** game.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 16:42:01 2017 dorian turba
** Last update Wed Jul 19 18:28:10 2017 dorian turba
*/

#include "serv.h"

int	all_ready(t_data_server *data_server)
{
  int	how_much;

  how_much = 0;
  FYN2
    if (data_server->clients[i].fd)
      if (data_server->clients[i].is_ready)
	how_much += 1;
  if (how_much == 2)
    return (1);
  return (0);
}

void	start(t_data_server *data_server)
{
  FYN2
    if (data_server->clients[i].fd)
      data_server->clients[i].msg = strdup("START\n");
}

void	init_game_data(t_data_server *d_s, t_game_data *g_d, int i)
{
  if (i == 0)
    {
      g_d->grav = d_s->data_flags->grav;
      g_d->win = 0;
      g_d->c1 = 0;
      g_d->c2 = 0;
      g_d->w1 = 0;
      g_d->w2 = 0;
    }
  else
    {
      g_d->x = &d_s->clients[i].pos_x;
      g_d->y = &d_s->clients[i].pos_y;
    }
}

void	reload(t_data_server *d_s)
{
  t_game_data	g_d;

  init_game_data(d_s, &g_d, 0);
  player_cmd(d_s);
  FYN2
    if (d_s->clients[i].fd)
      {
	init_game_data(d_s, &g_d, i);
	d_s->clients[i].speed +=
	  (sqrt(2 * (g_d.grav < 0 ? -g_d.grav : g_d.grav) * d_s->height)
	   / 120) * d_s->clients[i].jet_on_fire;
	(void)((*g_d.y += d_s->clients[i].speed) && (*g_d.x += 5.f / 60.f));
	if (*g_d.x + 1 > d_s->width)
	  {
	    g_d.c1 += d_s->clients[i].coins * (d_s->clients[i].id == 1);
	    g_d.c2 += d_s->clients[i].coins * (d_s->clients[i].id == 2);
	    g_d.win += d_s->clients[i].id;
	  }
	top_floor(d_s, i);
      }
  //coins(d_s, &g_d);
  wall(d_s, &g_d);
  if (g_d.win > 0)
    tell_winner(d_s, g_d.win, g_d.c1, g_d.c2);
}

/* void	coins(t_data_server d_s, int fd)
{
  float x;
  float y;

  x = d_s->clients[fd].pos_x;
  y = d_s->clients[fd].pos_y;
  for (int i = 0; i < 4; ++i)
    {
      if (d_s->map[(int)x * (i == 1 || i == 2) +
		   d_s->width * ((int)y * (i == 2 || i == 3))] == 'c')
	tell_winner(d_s, 3 - d_s->clients[fd].id, 0, 0);
    }  
    }*/

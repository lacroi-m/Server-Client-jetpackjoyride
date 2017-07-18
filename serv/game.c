/*
** game.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 16:42:01 2017 dorian turba
** Last update Wed Jul 19 01:19:24 2017 dorian turba
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
      data_server->clients[i].msg = strdup("START");
}

void	reload(t_data_server *d_s, int c1, int c2, float grav, int win)
{
  float *x;
  float *y;

  (void)((grav = d_s->data_flags->grav) && (win = 0));
  player_cmd(d_s);
  FYN2
    if (d_s->clients[i].fd)
      {
	(void)((x = &d_s->clients[i].pos_x) && (y = &d_s->clients[i].pos_y));
	printf("speed : %f\n", d_s->clients[i].speed);
	d_s->clients[i].speed += sqrt(2 * grav * d_s->height) / 120
	  * d_s->clients[i].jet_on_fire;
	(void)((*y += d_s->clients[i].speed) && (*x += 5.f / 60.f));
	if (*x + 1 > d_s->width)
	  {
	    c1 += d_s->clients[i].coins * (d_s->clients[i].id == 1);
	    c2 += d_s->clients[i].coins * (d_s->clients[i].id == 2);
	    win += d_s->clients[i].id;
	  }
	top_floor(d_s, i);
	wall(d_s, i);
	//coins(d_s, i);
      }
  if (win > 0)
    tell_winner(d_s, win, c1, c2);
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

/*
** ig_cmd.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 18:42:19 2017 dorian turba
** Last update Wed Jul 19 15:42:11 2017 dorian turba
*/

#include "serv.h"

int	nblen(int n)
{
  int	len;

  len = 1;
  while ((n / 10) > 0)
    {
      n = n / 10;
      ++len;
    }
  return (len);
}

void	player_cmd(t_data_server *d_s)
{
  char	*tmp;
  char	*tmp2;
  
  FYN2
    if (d_s->clients[i].fd)
      {
	tmp = malloc(sizeof(char) * 200);
	memset(tmp, 0, sizeof(char) * 200);
	tmp2 = malloc(sizeof(char) * 200);
	FYN3
	  if (d_s->clients[j].fd)
	    {
	      memset(tmp2, 0, sizeof(char) * 200);
	      sprintf(tmp2, "PLAYER %d %f %f %d\n", d_s->clients[j].id,
		      d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		      d_s->clients[j].coins);
		strcat(tmp, tmp2);
	    }
	d_s->clients[i].msg = realloc(d_s->clients[i].msg, sizeof(char)
				      * (strlen(tmp) +
					 strlen(d_s->clients[i].msg)));
	d_s->clients[i].msg = strcat(d_s->clients[i].msg, tmp);
	free(tmp);
	free(tmp2);
      }
}

void	wall(t_data_server *d_s, t_game_data *g_d)
{
  float x;
  float y;
  int	tmp;

  FYN2
    {
      tmp = 0;
      if (d_s->clients[i].fd)
	{
	  x = d_s->clients[i].pos_x;
	  y = d_s->clients[i].pos_y;
	  if (x <= d_s->width && y <= d_s->height)
	    if (d_s->map[(int)x + d_s->width * ((int)y)] == 'e')
	      tmp = 1;
	  if (x + 1 <= d_s->width && y <= d_s->height)
	    if (d_s->map[(int)x + 1 + d_s->width * ((int)y)] == 'e')
	      tmp = 1;
	  if (x <= d_s->width && y + 1 <= d_s->height)
	    if (d_s->map[(int)x + d_s->width * ((int)y + 1)] == 'e')
	      tmp = 1;
	  if (x + 1 <= d_s->width && y + 1 <= d_s->height)
	    if (d_s->map[(int)x + 1 + d_s->width * ((int)y + 1)] == 'e')
	      tmp = 1;
	  if (tmp == 1)
	    {
	      g_d->w1 = (d_s->clients[i].id == 2 ? 1 : g_d->w1);
	      g_d->w2 = (d_s->clients[i].id == 1 ? 2 : g_d->w2);
	    }
	}
    }
  if (g_d->w1 + g_d->w2 > 0)
    tell_winner(d_s, g_d->w1 + g_d->w2, g_d->c1, g_d->c2);
}

void	tell_winner(t_data_server *d_s, int result, int c1, int c2)
{
  FYN2
    {
      if (d_s->clients[i].fd)
	{
	  if (result == 3)
	    {
	      if (c1 == c2)
		sprintf(d_s->clients[i].msg, "FINISH -1\n");
	      else if (c1 > c2)
		sprintf(d_s->clients[i].msg, "FINISH %d\n", 1);
	      else
		sprintf(d_s->clients[i].msg, "FINISH %d\n", 2);
	    }
	  else
	    sprintf(d_s->clients[i].msg, "FINISH %d\n", result);
	}
    }
}

void	top_floor(t_data_server *d_s, int fd)
{
  float y;

  y = d_s->clients[fd].pos_y;
  if (y < 0)
    {
      d_s->clients[fd].pos_y = 0;
      d_s->clients[fd].speed = 0;
    }
  if (y + 1 > d_s->height)
    {
      d_s->clients[fd].pos_y = d_s->height -1;
      d_s->clients[fd].speed = 0;
    }
}

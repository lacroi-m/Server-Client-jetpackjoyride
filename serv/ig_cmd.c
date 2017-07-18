/*
** ig_cmd.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 18:42:19 2017 dorian turba
** Last update Tue Jul 18 22:39:43 2017 dorian turba
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
  
  tmp = malloc(sizeof(char) * 200);
  memset(tmp, 0, sizeof(char) * 200);
  tmp2 = malloc(sizeof(char) * 200);
  FYN2
    if (d_s->clients[i].fd)
      {
	FYN3
	  if (d_s->clients[j].fd)
	    {
	      memset(tmp2, 0, sizeof(char) * 200);
	      sprintf(tmp2, "PLAYER %d %f %f %d\n", d_s->clients[j].id,
		      d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		      d_s->clients[j].coins);
		strcat(tmp, tmp2);
	    }
	if (d_s->clients[i].msg != NULL)
	  free(d_s->clients[i].msg);
	d_s->clients[i].msg = strdup(tmp);
	//printf("Test : '%s'\n", d_s->clients[i].msg);
      }
  free(tmp);
  free(tmp2);
}

void	wall(t_data_server *d_s, int fd)
{
  float x;
  float y;

  x = d_s->clients[fd].pos_x;
  y = d_s->clients[fd].pos_y;
  for (int i = 0; i < 4; ++i)
    {
      if (d_s->map[(int)x * (i == 1 || i == 2) +
		   d_s->width * ((int)y * (i == 2 || i == 3))] == 'e')
	printf("MURMURMURMURMURMURMURMURMURMURMURMURMURMURMUR\n");
    }
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
		sprintf(d_s->clients[i].msg, "FINISH -1");
	      else if (c1 > c2)
		sprintf(d_s->clients[i].msg, "FINISH %d", 1);
	      else
		sprintf(d_s->clients[i].msg, "FINISH %d", 2);
	    }
	  else
	    sprintf(d_s->clients[i].msg, "FINISH %d", result);
	}
    }
}

void	top_floor(t_data_server *d_s, int fd)
{
  float y;

  y = d_s->clients[fd].pos_y;
  if (y < 0)
    d_s->clients[fd].pos_y = 0;
  if (y > d_s->height)
    d_s->clients[fd].pos_y = d_s->height -1;
}

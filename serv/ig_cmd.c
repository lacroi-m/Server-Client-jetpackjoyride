/*
** ig_cmd.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 18:42:19 2017 dorian turba
** Last update Mon Jul 17 21:36:35 2017 dorian turba
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
  tmp2 = malloc(sizeof(char) * 200);
  for (int i = 0; i < MAX_FD; ++i)
    if (d_s->clients[i].fd)
      {
	for (int j = 0; j < MAX_FD; ++j)
	  if (d_s->clients[j].fd)
	    {
	      printf("PLAYER %d %d %d %d\n", d_s->clients[j].id,
		     d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		     d_s->clients[j].coins);
	      sprintf(tmp2, "PLAYER %d %d %d %d\n", d_s->clients[j].id,
		      d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		      d_s->clients[j].coins);
	      strcat(tmp, tmp2);
	    }
	d_s->clients[i].msg = strdup(tmp);
      }
  free(tmp);
  free(tmp2);
}

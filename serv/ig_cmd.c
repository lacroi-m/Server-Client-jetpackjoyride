/*
** ig_cmd.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Mon Jul 17 18:42:19 2017 dorian turba
** Last update Tue Jul 18 14:06:37 2017 dorian turba
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
	      memset(tmp2, 0, sizeof(char) * strlen(tmp2));
	      printf("PLAYER %d %d %d %d\n", d_s->clients[j].id,
		     d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		     d_s->clients[j].coins);
	      sprintf(tmp2, "PLAYER %d %d %d %d\n", d_s->clients[j].id,
		      d_s->clients[j].pos_x, d_s->clients[j].pos_y,
		      d_s->clients[j].coins);
	      strcat(tmp, tmp2);
	    }
	if (d_s->clients[i].msg != NULL)
	  free(d_s->clients[i].msg);
	d_s->clients[i].msg = strdup(tmp);
	printf("Test : '%s'\n", d_s->clients[i].msg);
      }
  free(tmp);
  free(tmp2);
}

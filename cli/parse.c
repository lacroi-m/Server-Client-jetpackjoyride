/*
** parse.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Mon Jul 17 10:36:09 2017 Maxime Lacroix
** Last update Tue Jul 18 17:56:51 2017 Maxime Lacroix
*/

#include "cli.h"

int	add_to_id(char *msg, t_data *p)
{
  if (strncmp(msg, "ID ", 3) == 0)
    {
      if (msg[3 + 1] >= '0' && msg[3 + 1] <= '9')
	p->id = msg[3 + 1] - '0';
    }
  else
    return (-1);
  free(msg);
  return (0);
}

int	is_map(char *str)
{
  int	i;
  int	j;
  
  i = 0;
  j = 0;
  if (str == NULL)
    return (84);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == 'e' || str[i] == 'c'
	  || str[i] == '_')
	j++;
      i++;
    }
  if (i == j)
    return (0);
  return (84);
}

int	tab_size(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

void	malloc_map(t_data *p)
{
  int		k;

  k = -1;
  p->map = malloc(sizeof(char *) * (p->y + 2));
  while (++k < p->y)
    {
      p->map[k] = malloc(sizeof(char) * (p->x + 1));
      memset(p->map[k], 0, sizeof(char) * (p->x + 1));
    }
  p->map[k] = NULL;
}

int	add_to_map(char *msg, t_data *p)
{
  char		**tab;
  int		k;
  int		j;
  int		i;

  k = 0;
  i = 1;
  j = 3;
  tab = my_strd_to_wordtab(msg, " \n\0");
  if (tab_size(tab) > 3 && strncmp(msg, "MAP ", 3) == 0)
    {
      p->x = atoi(tab[1]);
      p->y = atoi(tab[2]);
      malloc_map(p);
      p->map[k] = strncpy(p->map[k], tab[j], p->x);
      while (my_strlen(p->map[k]) >= p->x && p->map[++k])
	{
	  tab[j] = memmove(tab[j], tab[j] + (p->x * i++), p->x);
	  p->map[k] = strncpy(p->map[k], tab[j], p->x);
	}
    }
  //  else if (is_map(tab[0]))
  //add_circular(tab, p);
  free_tab(tab);
  free(msg);
  return (0);
}

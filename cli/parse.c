/*
** parse.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Mon Jul 17 10:36:09 2017 Maxime Lacroix
** Last update Mon Jul 17 23:39:20 2017 Maxime Lacroix
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
  printf("is map == i = %d  && j = %d\n", i, j);
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

int	add_circular(char **tab, t_data *p)
{
  (void)tab;
  (void)p;
  /*  int	i;
  int	j;
  
  i = -1;
  j = 0;
  while (my_strlen(p->map[++i]) == p->x);
    if ((my_strlen(p->map[i]) + my_strlen(tab[j])) == p->x)
      p->map[i] = strcat(p->map[i], tab[j]);
  while (p->map[++i])
    {
      printf("maplen = %d\ttablen = %d\n", my_strlen(p->map[i]),my_strlen(tab[j]));
      if (my_strlen(p->map[i]) == 0)
	p->map[i] = strcpy(p->map[i], tab[j++]);
      else if ((my_strlen(p->map[i]) + my_strlen(tab[j++])) == p->x)
	p->map[i] = strcat(p->map[i], tab[j++]);
      else
	return (-1);
      //      j++;
    }*/
  return (0);
}

int	add_to_map(char *msg, t_data *p)
{
  char		**tab;
  int		k;
  int		j;

  k = -1;
  j = -1;
  tab = my_strd_to_wordtab(msg, " \n\0");
  if (tab_size(tab) > 3 && strncmp(msg, "MAP ", 3) == 0)
    {
      p->x = atoi(tab[1]);
      p->y = atoi(tab[2]);
      p->map = malloc(sizeof(char *) * (p->y + 1));
      while (++k < p->y)
	p->map[k] = malloc(sizeof(char) * (p->x + 1));
      p->map[k] = NULL;
      k = -1;
      j = 3;
      while (p->map[++k] && j < tab_size(tab))
	p->map[k] = strcpy(p->map[k], tab[j++]);
    }
  /*  for (int x = 0; x < tab_size(p->map); x++)
    printf("mapppy[%d] = '%s' && len = %d\n",x, p->map[x], my_strlen(p->map[x]));
  printf("tab[%d] = '%s'", j, tab[j]);
  while (tab[++j])
    if(is_map(tab[j]) == 0)
      {
<	printf("\n\nadd citcular\n\n");
	add_circular(tab, p);
      }
  printf("\n\nend citcular\n\n");
  //  printf("x = %d\ny = %d\n", p->x, p->y);
  for (int x = 0; x < tab_size(p->map); x++)
  printf("mapppy[%d] = '%s' && len = %d\n",x, p->map[x], my_strlen(p->map[x]));*/
  //  free(msg);
  return (0);
}

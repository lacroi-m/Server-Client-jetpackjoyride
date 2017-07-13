/*
** launcher.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 11:34:43 2017 Maxime Lacroix
** Last update Thu Jul 13 12:36:59 2017 Maxime Lacroix
*/

#include "cli.h"

char	*get_ip(char **av)
{
  int	x;

  x = 0;
  while (av[++x])
    if (strcmp(av[x], "-h") == 0 && x < 5 - 1)
      return (av[x + 1]);
  return (NULL);
}

int	get_port(char **av)
{
  int	x;

  x = 0;
  while (av[++x])
    if (strcmp(av[x], "-p") == 0 && x < 5 - 1)
      return (atoi(av[x + 1]));
  return (0);
}

void	init_struct(char *ip, int port)
{
  p = malloc(sizeof(t_data *));
  p->port = port;
  p->ip = ip;
}

int	launcher(char **av)
{  
  write (1, "You have launched\n", 18);
  init_struct(get_ip(av), get_port(av));
  write (1, "Struct inatisations\n", 20);
  printf("port = '%d'\nip = '%s'\n", p->port, p->ip);
  return (0);
}

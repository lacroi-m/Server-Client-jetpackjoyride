/*
** launcher.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 11:34:43 2017 Maxime Lacroix
** Last update Thu Jul 13 14:02:30 2017 Maxime Lacroix
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
  p = malloc(sizeof(t_data *) * 2);
  p->port = port;
  p->ip = malloc(sizeof(char) * (my_strlen(ip) + 1));
  p->ip = strcpy(p->ip, ip);
}

int	launcher(char **av)
{
  write (1, "Struct inatisation\n", 19);
  init_struct(get_ip(av), get_port(av));
  write (1, "You have  launched\n", 19);
  printf("port = '%d'\nip = '%s'\n", p->port, p->ip);
  communication();
  free_struct();
  return (0);
}

/*
** launcher.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 11:34:43 2017 Maxime Lacroix
** Last update Mon Jul 17 23:41:05 2017 Maxime Lacroix
*/

#include "cli.h"
#include "communication.h"

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

void	init_struct(char *ip, int port, t_data *p)
{
  p->port = port;
  //  printf("ip = %s size = %d\n", ip, my_strlen(ip));
  p->ip = malloc(sizeof(char) * (my_strlen(ip) + 1));
  p->ip = strcpy(p->ip, ip);
}

int	launcher(char **av)
{
  t_data  p;
  char	*msg;

  init_struct(get_ip(av), get_port(av), &p);
  init_communication(p.port, p.ip);
  sendit(com->com_fd, "ID\n");
  
  msg = receiveit(1, com->com_fd);
  add_to_id(msg, &p);
  sendit(com->com_fd, "MAP\n");
  msg = receiveit(1, com->com_fd);
  //  printf("map = %s\n", msg);
  add_to_map(msg, &p); 
  sendit(com->com_fd, "READY\n");
  while (42)
    {
      //      printf("waitin to receive\n");
      msg = receiveit(1, com->com_fd);
      add_to_map(msg, &p);
      //      printf("receiving %s\n", msg);
    }
  if (msg != NULL)
    free(msg);
  free_struct(&p);
  return (0);
}

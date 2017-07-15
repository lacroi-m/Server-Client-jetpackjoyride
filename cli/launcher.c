/*
** launcher.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 11:34:43 2017 Maxime Lacroix
** Last update Sat Jul 15 16:54:39 2017 Maxime Lacroix
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

void	init_struct(char *ip, int port)
{
  p = malloc(sizeof(t_data *) * 2);
  p->port = port;
  p->ip = malloc(sizeof(char) * (my_strlen(ip) + 1));
  p->ip = strcpy(p->ip, ip);
}

int	launcher(char **av)
{
  char	*msg;

  init_struct(get_ip(av), get_port(av));
  init_communication(p->port, p->ip);
  printf("trying to send 'ID'\n");
  if (sendit("ID", com->com_fd) == 0)
    {
      msg = receiveit(0, com->com_fd);
      //      msgb = cutreturn(msg)
      printf("receiving '%s'\n", msg);
      sendit("MAP", com->com_fd);
      printf("trying to send 'MAP'\n");
      if (msg != NULL)
	free(msg);
    }
  else
    printf("send 'ID' failed\n");
  free_struct();
  return (0);
}

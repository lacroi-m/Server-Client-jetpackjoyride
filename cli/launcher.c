/*
** launcher.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 11:34:43 2017 Maxime Lacroix
** Last update Sun Jul 16 18:02:03 2017 Maxime Lacroix
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
  int	i;
  i = 0;
  init_struct(get_ip(av), get_port(av));
  init_communication(p->port, p->ip);
  dprintf(com->com_fd, "ID\n");
  printf("reciving id ?\n");
  msg = receiveit(0, com->com_fd);
  printf("id = %s\n", msg);
  // add_to_id(msg);
  printf("Sending MAP\n");
  dprintf(com->com_fd, "MAP\n");
  printf("receiving Map ?\n");
  msg = receiveit(0, com->com_fd); 
  printf("map = %s\n", msg);
  //add_to_map(msg);
  printf("sending ready\n");
  //sendit("READY\n", com->com_fd);
  while (i < 3)
    {
      msg = receiveit(0, com->com_fd);
      printf("receiving %s\n", msg);
      i++;
    }
  dprintf(com->com_fd, "READY\n");
  while (1)
    {
      //      dprintf(com->com_fd, "READY\n");
      printf("waitin to receive\n");
      msg = receiveit(0, com->com_fd);
      printf("receiving %s\n", msg);
    }
  if (msg != NULL)
    free(msg);  
  //  }
  //x  else
  
  free_struct();
  return (0);
}

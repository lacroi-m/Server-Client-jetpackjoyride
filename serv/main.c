/*
** main.c for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 08:06:45 2017 Maxime Lacroix
** Last update Wed Jul 19 23:14:21 2017 Maxime Lacroix
*/

#include "serv.h"

static volatile int keep_running = 1;
char	*g_fmap;
char	*g_map;
t_data_server	*g_d_s;

void	int_handler(int dummy)
{
  (void)dummy;
  for (int i = 0; i < MAX_FD; ++i)
    if (g_d_s->clients[i].fd)
      close(g_d_s->clients[i].fd);
  close(g_d_s->fd_server);
  free(g_fmap);
  free(g_map);
  printf("ERROR\n");
  keep_running = 0;
}

int	init_server(t_data_server *data_serv, int fd, t_data_flags *data_flags)
{
  FYN2
    data_serv->fd_type[i] = FD_FREE;
  data_serv->fd_type[fd] = FD_SERVER;
  data_serv->fd_server = fd;
  data_serv->client_nbr = 2;
  data_serv->fct_read[fd] = add_client;
  data_serv->fct_write[fd] = NULL;
  if (fill_map(data_flags->map, data_serv) == 84)
    return (84);
  for (int i = 0; i < MAX_FD; ++i)
    data_serv->clients[i].fd = 0;
  data_serv->data_flags = data_flags;
  data_serv->connected_player = 0;
  data_serv->start = 0;
  return (0);
}

int		add_server(t_data_server *data_serv, t_data_flags *data_flags)
{
  int	fd;
  struct sockaddr_in	s_in;
  int			nbr;

  if ((nbr = 1) && (fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == -1)
    return (84);
  s_in.sin_family = AF_INET;
  s_in.sin_port = ntohs(data_flags->port);
  s_in.sin_addr.s_addr = htonl(INADDR_ANY);
  setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &nbr, sizeof(int));
  if (init_server(data_serv, fd, data_flags) == 84)
    return (84);
  if (bind(fd, (struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    {
      printf("error BIND\n");
      close(fd);
      return (84);
    }
  if (listen(fd, data_serv->client_nbr) == -1)
    {
      printf("error Listen\n");
      close(fd);
      return (84);
    }
  return (0);
}

int	game_cycle(t_data_server *data_server)
{
  clock_t	start_t;
  clock_t	end_t;

  start_t = clock();
  while (keep_running)
    {
      if (run_server(data_server) == 84)
	return (84);
      if (((end_t = clock()) - start_t) > (CLOCKS_PER_SEC / 60))
	{
	  if (all_ready(data_server))
	    {
	      if (!data_server->start)
		{
		  data_server->start = 1;
		  start(data_server);
		}
	      else
		reload(data_server);
	    }
	  start_t = clock();
	}
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_data_server	data_server;
  t_data_flags	data_flags;

  signal(SIGINT, int_handler);
  if (arg_check(ac, av, &data_flags) == 84)
    return (84);
  if (add_server(&data_server, &data_flags) == 84)
    return (84);
  (void)((g_fmap = data_flags.map) && (g_map = data_server.map));
  g_d_s = &data_server;
  if (game_cycle(&data_server) == 84)
    return (84);
  if (keep_running == 0)
    return (84);
  else
    {
      free(data_flags.map);
      free(data_server.map);
    }
  return (0);
}

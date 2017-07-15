/*
** main.c for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 08:06:45 2017 Maxime Lacroix
** Last update Sat Jul 15 16:01:33 2017 Maxime Lacroix
*/

#include "serv.h"

static volatile int keep_running = 1;

void	int_handler(int dummy)
{
  (void)dummy;
  printf("ERROR\n");
  keep_running = 0;
}

int	init_server(t_data_server *data_serv, int fd, t_data_flags *data_flags)
{
  data_serv->fd_type[fd] = FD_SERVER;
  data_serv->fd_server = fd;
  data_serv->client_nbr = 2;
  data_serv->fct_read[fd] = add_client;
  data_serv->fct_write[fd] = NULL;
  if (fill_map(data_flags->map, data_serv) == 84)
    return (84);
  data_serv->data_flags = data_flags;
  return (0);
}

int		add_server(t_data_server *data_serv, t_data_flags *data_flags)
{
  int	fd;
  //  struct protoent	*prot;
  struct sockaddr_in	s_in;
  //struct sockaddr_in    client;
  //  if ((prot = getprotobyname("TCP")) == NULL)
  //return (84);
  //socklen_t sin_size = sizeof(struct sockaddr_in);
  
  if ((fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP)) == -1)
    return (84);
  s_in.sin_family = AF_INET;
  s_in.sin_port = ntohs(4242);
  s_in.sin_addr.s_addr = htonl(INADDR_ANY);
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
  if (init_server(data_serv, fd, data_flags) == 84)
    return (84);
  return (0);
}

int		main(int ac, char **av)
{
  t_data_server	data_server;
  t_data_flags	data_flags;

  signal(SIGINT, int_handler);
  if (arg_check(ac, av, &data_flags) == 84)
    return (84);
  else
    {
      if (add_server(&data_server, &data_flags) == 84)
	return (84);
      while (keep_running)
	{
	  if (run_server(&data_server) == 84)
	    return (84);
	}
    }
  free(data_flags.map);
  free(data_server.map);
  if (keep_running == 0)
    return (84);
  return (0);
}

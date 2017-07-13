/*
** main.c for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 08:06:45 2017 Maxime Lacroix
** Last update Thu Jul 13 21:29:12 2017 dorian turba
*/

#include "serv.h"

int	check_map(char *map)
{
  for (unsigned int i = 0; i < strlen(map); ++i)
    if (map[i] != '_' && map[i] == 'c' && map[i] == 'e')
	return (error(MAP_INV));
  return (0);
}

int		fill_map(char *map_name, t_data_server *data_serv)
{
  char		*line;
  size_t	len;
  FILE		*stream;
  ssize_t	read;

  line = NULL;
  len = 0;
  stream = fopen(map_name, "r");
  data_serv->map = strdup("");
  if (stream == NULL)
    return (error(MAP_INV));
  while ((read = getline(&line, &len, stream)) != -1)
    {
      data_serv->map = realloc(data_serv->map, sizeof(char) *
			       (strlen(data_serv->map) + read + 1));
      data_serv->map = strcat(data_serv->map, line);
    }
  free(line);
  fclose(stream);
  return (0);
}

int	init_server(t_data_server *data_serv, int fd, t_data_flags *data_flags)
{
  data_serv->fd_type[fd] = FD_SERVER;
  data_serv->fd_server = fd;
  data_serv->client_nbr = 2;
  if (fill_map(data_flags->map, data_serv) == 84 ||
      check_map(data_serv->map) == 84)
    return (84);
  data_serv->data_flags = data_flags;
  return (0);
}

int		add_server(t_data_server *data_serv, t_data_flags *data_flags)
{
  int	fd;
  struct protoent	*prot;
  struct sockaddr_in	s_in;

  if ((prot = getprotobyname("TCP")) == NULL)
    return (84);
  if ((fd = socket(AF_INET, SOCK_STREAM, prot->p_proto)) == -1)
    return (84);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(data_flags->port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind(fd, (struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    close(fd);
  if (init_server(data_serv, fd, data_flags) == 84)
    return (84);
  return (0);
}

int		main(int ac, char **av)
{
  t_data_server	data_server;
  t_data_flags	data_flags;

  if (arg_check(ac, av, &data_flags) == 84)
    return (84);
  else
    {
      if (add_server(&data_server, &data_flags) == 84)
	return (84);
    }
  free(data_flags.map);
  free(data_server.map);
  return (0);
}

/*
** map.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Fri Jul 14 12:39:44 2017 dorian turba
** Last update Fri Jul 14 12:49:29 2017 dorian turba
*/

#include "serv.h"

int	check_map(char *map)
{
  for (unsigned int i = 0; i < strlen(map); ++i)
    if (map[i] != '_' && map[i] != 'c' && map[i] != 'e')
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
      if (check_map(line) == 84)
	return (84);
      data_serv->map = realloc(data_serv->map, sizeof(char) *
			       (strlen(data_serv->map) + read + 1));
      data_serv->map = strcat(data_serv->map, line);
    }
  free(line);
  fclose(stream);
  return (0);
}

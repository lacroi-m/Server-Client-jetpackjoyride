/*
** map.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Fri Jul 14 12:39:44 2017 dorian turba
** Last update Tue Jul 18 10:12:52 2017 dorian turba
*/

#include "serv.h"

int	check_map(char *map)
{
  for (unsigned int i = 0; i < strlen(map); ++i)
    if (map[i] != '_' && map[i] != 'c' && map[i] != 'e' && map[i] != '\n')
      return (error(MAP_INV));
  return (0);
}

int		fill_map(char *map_name, t_data_server *d_s)
{
  char		*line;
  size_t	len;
  FILE		*stream;
  ssize_t	r;
  int		i;

  line = NULL;
  len = i = 0;
  stream = fopen(map_name, "r");
  d_s->map = strdup("");
  if (stream == NULL)
    return (error(MAP_INV));
  while ((r = getline(&line, &len, stream)) != -1)
    {
      if (check_map(line) == 84)
	return (84);
      d_s->map = realloc(d_s->map, sizeof(char) * (strlen(d_s->map) + r + 1));
      d_s->map = strcat(d_s->map, my_strd_to_wordtab(line, "\n")[0]);
      (void)((d_s->width = r) && (++i));
    }
  d_s->height = i;
  free(line);
  fclose(stream);
  return (0);
}

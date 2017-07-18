/*
** tools.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 10:32:24 2017 Maxime Lacroix
** Last update Tue Jul 18 18:59:08 2017 Maxime Lacroix
*/

#include "cli.h"
#include "communication.h"

void	free_struct(t_data *p)
{
  if (p != NULL)
    {
      if (p->ip != NULL)
	free(p->ip);
      if (p->map != NULL)
	free_tab(p->map);
    }
  if (com != NULL)
    free(com);
}

int	is_numeric(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (i == my_strlen(str))
    return (0);
  return (84);
}

void	exit_error(t_data *p)
{
  free_struct(p);
  exit (my_putstr(2, "Erreur\n", 84));
}

int	my_strlen(char *str)
{
  int		i;

  i = -1;
  if (str == NULL)
    return (0);
  while (str[++i] != '\0' && str[i] != '\n' && str[i]);
  return (i);
}

int	my_putstr(int fd, char *str, int rvalue)
{
  write(fd, str, my_strlen(str) + 1);
  return (rvalue);
}

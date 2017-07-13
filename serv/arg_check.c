/*
** arg_check.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Thu Jul 13 16:34:14 2017 dorian turba
** Last update Thu Jul 13 18:42:44 2017 dorian turba
*/

#include "serv.h"

int	arg_check(int ac, char **av, t_data_flags *data_flags)
{
  int	checker;

  checker = 0;
  if (ac != 7)
    return (error(ARG_INV));
  else
    {
      for (int i = 1; i < ac; ++i)
	{
	  if (strcmp(av[i], "-p") == 0)
	    if (av[i + 1] && (data_flags->port = atoi(av[++i]) != 0))
	      checker += 1;
	  if (strcmp(av[i], "-g") == 0)
	    if (av[i + 1] && (data_flags->grav = atoi(av[++i]) != 0))
	      checker += 10;
	  if (strcmp(av[i], "-m") == 0)
	    if (av[i + 1] && (data_flags->map = strdup(av[++i])))
	      checker += 100;
	}
      if (checker != 111)
	return (error(ARG_INV));
    }
  return (0);
}

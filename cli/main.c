/*
** main.c for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/cli
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 08:06:13 2017 Maxime Lacroix
** Last update Tue Jul 18 20:26:12 2017 Maxime Lacroix
*/

#include "cli.h"

int	check_args(char **av)
{
  int		x;
  int		flag;

  flag = 0;
  x = 1;
  while (av[x])
    {
      if (strcmp(av[x], "-h") == 0 && x < 5 - 1)
	{
	  x++;
	  flag++;
	}
      else if (strcmp(av[x], "-p") == 0 && x < 5 - 1)
	{
	  x++;
	  if (is_numeric(av[x]) == 84)
	    return (84);
	  flag++;
	}
      x++;
    }
  if (flag == 2)
    return (0);
  return (84);
}

int	main(int ac, char **av)
{
  if (ac < 5 || ac > 5)
    return (my_putstr(2, "Arguments invalides\n", 84));
  else if (check_args(av) == 84)
    return (my_putstr(2, "Arguments invalides\n", 84));
  else
    return (launcher(av));
  return (0);
}

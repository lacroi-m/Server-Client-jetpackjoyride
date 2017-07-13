/*
** main.c for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 08:06:45 2017 Maxime Lacroix
** Last update Thu Jul 13 18:47:10 2017 dorian turba
*/

#include "serv.h"

int		main(int ac, char **av)
{
  //  t_data_server	data_server;
  t_data_flags	data_flags;
  //  clock_t	start_t;
  //  clock_t	end_t;

  //start_t = clock();
  if (arg_check(ac, av, &data_flags) == 84)
    {  printf("test fail\n");
      return (84);}
  else
    {
      printf("test\n");
      /*      add_server(&data_server, &data_flags);
      count_team_members(&data_server);
      while (42)
	{
	  end_t = clock();
	  timer = (double) (end_t - start_t) / CLOCKS_PER_SEC;
	  run_server(&data_server);
	}
	return (0);*/
    }
  free(data_flags.map);
  return (0);
}

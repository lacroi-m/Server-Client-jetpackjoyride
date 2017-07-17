/*
** free_tab.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Mon Jul 17 16:28:52 2017 Maxime Lacroix
** Last update Mon Jul 17 16:31:55 2017 Maxime Lacroix
*/
#include <stdlib.h>
#include <unistd.h>

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab != NULL)
    {
      while (tab[++i])
	free(tab[i]);
      free(tab);
    }
}

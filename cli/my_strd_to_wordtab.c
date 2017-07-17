/*
** my_strd_to_wordtab.c<serv> for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Sun Jul 16 14:03:10 2017 dorian turba
** Last update Mon Jul 17 16:00:57 2017 Maxime Lacroix
*/

#include "serv.h"

int	find_chara(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

int	my_countdword(char *str, char *delim)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    i++;
	  j++;
	}
    }
  return (j);
}

char	**my_putstr_indtab(char *str, char **tab, char *delim)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    {
	      tab[j][k] = str[i];
	      k++;
	      i++;
	    }
	  tab[j][k] = '\0';
	  k = 0;
	  j++;
	}
    }
  return (tab);
}

char	**my_countdchar(char *str, char **tab, char *delim)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '\0')
    {
      while (find_chara(delim, str[i]) == 1 && str[i] != '\0')
	i++;
      if (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	{
	  while (find_chara(delim, str[i]) == 0 && str[i] != '\0')
	    {
	      i++;
	      k++;
	    }
	  tab[j] = malloc((k + 1) * sizeof(char));
	  k = 0;
	  j++;
	}
    }
  tab[j] = NULL;
  return (tab);
}

char	**my_strd_to_wordtab(char *str, char *delim)
{
  int	i;
  char	**tab;

  if (str == NULL || str[0] == '\0')
    return (NULL);
  i = my_countdword(str, delim);
  tab = malloc((i + 1) * sizeof(*tab));
  tab = my_countdchar(str, tab, delim);
  tab = my_putstr_indtab(str, tab, delim);
  return (tab);
}

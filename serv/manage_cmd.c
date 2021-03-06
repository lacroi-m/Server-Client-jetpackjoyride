/*
** manage_cmd.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Sun Jul 16 13:24:57 2017 dorian turba
** Last update Mon Jul 17 15:36:16 2017 dorian turba
*/

#include "serv.h"

void	init_tab(t_cmdptr *cmd_tab)
{
  (cmd_tab[0].name = strdup("ID")) && (cmd_tab[0].fct_p = &id);
  (cmd_tab[1].name = strdup("MAP")) && (cmd_tab[1].fct_p = &map);
  (cmd_tab[2].name = strdup("READY")) && (cmd_tab[2].fct_p = &ready);
  (cmd_tab[3].name = strdup("FIRE")) && (cmd_tab[3].fct_p = &fire);
}

int	count(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      ++i;
    }
  return (i);
}

void		manage_cmd_server(char *buffer, t_data_server *data_server, int fd)
{
  char		**tab;
  int		i;
  t_cmdptr	cmd_tab[TOTAL_CMD];

  i = 0;
  if (buffer[0] == '\0' || buffer[0] == '\n')
    return;
  if (count(tab = my_strd_to_wordtab(buffer, "\n")) > 1)
    for (int i = 0; tab[i]; ++i)
      manage_cmd_server(tab[i], data_server, fd);
  else
    {
      tab = my_strd_to_wordtab(buffer, " ");
      init_tab(cmd_tab);
      while (i < TOTAL_CMD)
	{
	  if (tab[0] && strcmp(tab[0], cmd_tab[i].name) == 0)
	    {
	      if (tab[1])
		cmd_tab[i].fct_p(data_server, fd, atoi(tab[1]));
	      else
		cmd_tab[i].fct_p(data_server, fd, 0);
	      i = TOTAL_CMD;
	    }
	  i++;
	}
    }
}

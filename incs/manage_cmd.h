/*
** manage_cmd.h for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Sun Jul 16 13:54:25 2017 dorian turba
** Last update Mon Jul 17 15:25:42 2017 dorian turba
*/

#ifndef MANAGE_CMD_H
# define MANAGE_CMD_H

typedef struct	s_cmdptr
{
  char		*name;
  void		(*fct_p)(t_data_server *data_server, int fd, int fire);
}		t_cmdptr;

#endif /* !MANAGE_CMD_H */

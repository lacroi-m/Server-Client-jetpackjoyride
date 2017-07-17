/*
** serv.h for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/incs
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 09:44:49 2017 Maxime Lacroix
** Last update Mon Jul 17 10:38:48 2017 dorian turba
*/

#ifndef _SERV_H_
 #define _SERV_H_
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "err.h"
#include "init_server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <netdb.h>
#include <signal.h>
#include <ctype.h>

# define TOTAL_CMD 4

typedef struct	s_data_flags
{
  int		port;
  int		grav;
  char		*map;
}		t_data_flags;

typedef struct	s_cmdptr
{
  char		*name;
  void		(*fct_p)(t_data_server *data_server, int fd);
}		t_cmdptr;

int	error(char*);
int	arg_check(int, char**, t_data_flags*);
void	int_handler(int);
int	check_map(char*);
int	fill_map(char*, t_data_server*);
int	run_server(t_data_server*);
void	my_isset(t_data_server*, fd_set*, fd_set*);
int	my_select(int, fd_set*, fd_set*);
int	get_fd_max(t_data_server*, fd_set*, fd_set*);
void	init_client(t_client*, int, t_data_server*);
void	add_client(t_data_server*, int);
void	client_write(t_data_server*, int);
void	client_read(t_data_server*, int);
void	make_msg(char*, t_client*);
int	is_num(char*);
void	init_tab(t_cmdptr*);
void	manage_cmd_server(char*, t_data_server*, int);
int	find_chara(char*, char);
int	my_countdword(char*, char*);
char	**my_putstr_indtab(char*, char**, char*);
char	**my_countdchar(char*, char**, char*);
char	**my_strd_to_wordtab(char*, char*);
void	id(t_data_server*, int);
void	map(t_data_server*, int);
void	ready(t_data_server*, int);
void	fire(t_data_server*, int);

#endif /*_SERV_H_*/

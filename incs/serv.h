/*
** serv.h for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/incs
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 09:44:49 2017 Maxime Lacroix
** Last update Sat Jul 15 10:30:30 2017 dorian turba
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

typedef struct	s_data_flags
{
  int		port;
  int		grav;
  char		*map;
}		t_data_flags;

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
int	is_num(char *str)

#endif /*_SERV_H_*/

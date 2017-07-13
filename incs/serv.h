/*
** serv.h for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/incs
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 09:44:49 2017 Maxime Lacroix
** Last update Thu Jul 13 18:43:18 2017 dorian turba
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

typedef struct	s_map
{
  char		*map;
  int		width;
  int		height;
}		t_map;

typedef struct	s_data_flags
{
  int		port;
  int		grav;
  char		*map;
}		t_data_flags;

int	error(int);
int	arg_check(int, char**, t_data_flags*);

#endif /*_SERV_H_*/

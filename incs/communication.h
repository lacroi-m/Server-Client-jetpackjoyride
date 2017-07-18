/*
** communication.h for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 14:55:48 2017 Maxime Lacroix
** Last update Tue Jul 18 18:23:48 2017 Maxime Lacroix
*/

#ifndef _COMMUNICATION_H_
 #define _COMMUNICATION_H_
#include "cli.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
typedef struct	s_com
{
  int		com_fd;
}		t_com;

t_com		*com;

void		init_communication(unsigned short port, char *ip, t_data *p);
char		*receiveit(int isBlock, int com_fd, t_data *p);
int		sendit(int com_fd, char *msg);

#endif /*_COMMUNICATION_H_*/

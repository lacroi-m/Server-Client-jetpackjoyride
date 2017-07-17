/*
** communication.h for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 14:55:48 2017 Maxime Lacroix
** Last update Mon Jul 17 11:05:04 2017 Maxime Lacroix
*/

#ifndef _COMMUNICATION_H_
 #define _COMMUNICATION_H_

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

void		init_communication(unsigned short port, char *ip);
char		*receiveit(int isBlock, int com_fd);
int		sendit(int com_fd, char *msg);

void		exit_error();
int		my_strlen(char *str);

#endif /*_COMMUNICATION_H_*/

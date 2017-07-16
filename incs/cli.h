/*
** cli.h for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/incs
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 09:48:52 2017 Maxime Lacroix
** Last update Sun Jul 16 12:20:26 2017 Maxime Lacroix
*/

#ifndef _CLI_H_
 #define _CLI_H_
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct	s_data
{
  char		*ip;
  int		port;

  char		*id;
  int		x;
  int		y;
  int		score;
  
  int		width;
  int		height;
  char		*map;
}		t_data;

t_data        *p;

/*tools*/
void	free_struct();
int     is_numeric(char *str);
void    exit_error();
int     my_strlen(char *str);
int     my_putstr(int fd, char *str, int rvalue);


/*launcher*/
int	launcher();

/*connect*/
void	communication();
#endif /*_SERV_H_*/

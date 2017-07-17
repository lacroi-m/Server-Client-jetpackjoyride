/*
** cli.h for  in /home/lacroi_m/pisicne/jetpac2Tek3_2016/incs
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Thu Jul 13 09:48:52 2017 Maxime Lacroix
** Last update Mon Jul 17 16:30:15 2017 Maxime Lacroix
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

  int		id;
  int		x;
  int		y;
  int		score;
  
  int		width;
  int		height;
  char		**map;
  char		*crapmap;
}		t_data;


char	**my_strd_to_wordtab(char *str, char *del);
void	free_tab(char **tab);
/*tools*/
void	free_struct(t_data *p);
int     is_numeric(char *str);
void    exit_error(t_data *p);
int     my_strlen(char *str);
int     my_putstr(int fd, char *str, int rvalue);

/*parse*/
int	add_to_id(char *msg, t_data *p);
int	add_to_map(char *msg, t_data *p);

/*launcher*/
int	launcher();

/*connect*/
void	communication();
#endif /*_SERV_H_*/

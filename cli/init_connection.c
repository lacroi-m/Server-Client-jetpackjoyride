/*
** init_connection.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Sat Jul 15 16:56:39 2017 Maxime Lacroix
** Last update Tue Jul 18 18:58:09 2017 Maxime Lacroix
*/

#include "communication.h"

char    *hostname_to_ip(char *hostname)
{
  struct hostent *he;
  if (!(he = gethostbyname(hostname)))
    return (NULL);

  struct in_addr **addr_list;
  addr_list = (struct in_addr **)he->h_addr_list;
  if (!(*addr_list))
    return (NULL);

  return inet_ntoa(*addr_list[0]);
}


void    init_communication(unsigned short port, char *ip, t_data *p)
{
  struct sockaddr_in s_in;
  char		     *host_ip;
  com = malloc(sizeof(t_com));
  if (!(com->com_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
    exit_error(p);
  bzero(&s_in, sizeof(struct sockaddr_in));
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  if ((host_ip = hostname_to_ip(ip)) == NULL)
    exit_error(p);
  s_in.sin_addr.s_addr = inet_addr(host_ip);
  if (connect(com->com_fd, (struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    exit_error(p);
}

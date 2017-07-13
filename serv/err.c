/*
** err.c for jetpack2Tek3_2016 in /home/turba_d/projets/piscine_synth/jetpack2Tek3_2016/serv
** 
** Made by dorian turba
** Login   <turba_d@epitech.net>
** 
** Started on  Thu Jul 13 16:50:32 2017 dorian turba
** Last update Thu Jul 13 18:40:01 2017 dorian turba
*/

#include "serv.h"

int	error(int err_code)
{
  if (err_code == ARG_INV)
    printf("Arguments invalides\n");
  return (84);
}

/*
** game.c for  in /home/lacroi_m/pisicne/jetpack2Tek3_2016
** 
** Made by Maxime Lacroix
** Login   <lacroi_m@epitech.net>
** 
** Started on  Tue Jul 18 20:33:25 2017 Maxime Lacroix
** Last update Wed Jul 19 23:22:12 2017 Maxime Lacroix
*/

#include "cli.h"
#include "communication.h"

pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	*talking(t_data *p)
{
  (void)p;
  pthread_mutex_lock(&mutex);
  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
  return (NULL);
}

void	*loop(SDL_Surface *ecran, SDL_Surface *coin, SDL_Surface *wall,
	      SDL_Surface *fplayer, SDL_Surface *splayer, t_data *p)
{
  int	x;
  int	y;
  SDL_Event event;
  SDL_Rect coinpos;
  SDL_Rect wallpos;
  int continuer = 1;
  (void)fplayer;
  (void)splayer;

  while (continuer)
    {
      SDL_Flip(ecran);
      SDL_WaitEvent(&event);
      switch(event.type)
	{
	case SDL_KEYDOWN:
	  {
	    if (event.key.keysym.sym == SDLK_ESCAPE)
	      exit(0);
	    if (event.key.keysym.sym == SDLK_SPACE)
	      sendit(com->com_fd, "FIRE 1\n");
	  }
	case SDL_KEYUP:
	  {
	    if (event.key.keysym.sym == SDLK_SPACE)
	      sendit(com->com_fd, "FIRE 0\n");
	    if (event.key.keysym.sym == SDLK_ESCAPE)
	      exit(0);
	  }
	}
      y = -1;
      while (++y < p->y)
	{
	  x = -1;
	  while (++x < p->x)
	    {
	      if (p->map[y][x] == 'c')
		{
		  coinpos.x = x * 19;
		  coinpos.y = y * 19;
		  SDL_BlitSurface(coin, NULL, ecran, &coinpos);
		}
	      if (p->map[y][x] == 'e')
		{
		  wallpos.x = x * 19;
		  wallpos.y = y * 19;
		  SDL_BlitSurface(wall, NULL, ecran, &wallpos);
		}
	    }
	  SDL_Flip(ecran);
	}
    }
  pthread_mutex_unlock(&mutex);
  SDL_FreeSurface(coin);
  SDL_FreeSurface(wall);
  SDL_FreeSurface(ecran);
  SDL_Quit();
  pthread_exit(NULL);
  return (NULL);
}

void	*talking2(t_data *p)
{
  SDL_Surface *ecran = NULL;
  SDL_Surface *coin = NULL;
  SDL_Surface *wall = NULL;
  SDL_Surface *fplayer = NULL;
  SDL_Surface *splayer = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Jetpack", NULL);
  ecran = SDL_SetVideoMode(p->x * 19, p->y * 19, 32, SDL_HWSURFACE);
  coin = SDL_CreateRGBSurface(SDL_HWSURFACE, 19, 19, 32, 255, 255, 0, 0);
  wall = SDL_CreateRGBSurface(SDL_HWSURFACE, 19, 19, 32, 0, 255, 255, 0);
  fplayer = SDL_CreateRGBSurface(SDL_HWSURFACE, 19, 19, 32, 0, 255, 0, 0);
  splayer = SDL_CreateRGBSurface(SDL_HWSURFACE, 19, 19, 32, 255, 0, 0, 0);
  pthread_mutex_lock(&mutex);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 50));
  SDL_FillRect(coin, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_FillRect(wall, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_FillRect(fplayer, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_FillRect(splayer, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  return (loop(ecran, coin, wall, fplayer, splayer, p));
}

void	game(t_data *p)
{
  pthread_t th1;
  pthread_t th2;

  pthread_create(&th1, NULL, (void *)talking, p);
  pthread_create(&th2, NULL, (void *)talking2, p);
  pthread_join (th1, NULL);
  pthread_join (th2, NULL);
}

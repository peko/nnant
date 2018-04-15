#include <stdio.h>

#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>

#include "colony.h"
#include "ant.h"

#define WIDTH  320
#define HEIGHT 320

void colony_draw(SDL_Surface* screen, colony_t colony){
    for(size_t i=0; i<colony->ants.n; i++) {
        ant_t ant = colony->ants.a[i];
        unsigned int* p = screen->pixels + (ant->x + ant->y*WIDTH)*3;
        *p = (unsigned int)0xFFFFFF;
    }
}


int main(int argc, char** argv) {
    SDL_Event evt; 
    int i,j;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            return -1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(
      WIDTH, HEIGHT, 24, 
      SDL_SWSURFACE | SDL_DOUBLEBUF);

    if (screen == NULL) {
            return -1;
    }

    colony_t c = colony_new();
    for(size_t i=0; i <100; i++) {
        colony_add_ant(c);
    }

    while(1) {
        while(SDL_PollEvent(&evt)) {
          if(evt.type == SDL_QUIT) {
            goto finish;
          }
          if (evt.type == SDL_KEYUP && evt.key.keysym.sym == SDLK_ESCAPE) {
            goto finish;
          }
        }

        SDL_LockSurface(screen);
        //SDL_FillRect(screen, NULL, 0x000080); 
        colony_draw(screen, c);
        SDL_FreeSurface(screen);
        SDL_Flip(screen);
    }

finish:
    colony_free(c);

    SDL_FreeSurface(screen);
    SDL_Quit();

    return 0;
}

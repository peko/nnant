#include <stdio.h>

#include <SDL/SDL.h>

#include "colony.h"
#include "ant.h"


void draw_colony(SDL_Surface* screen, colony_t colony){
    for(size_t i=0; i<colony->ants.n; i++) {
        ant_t ant = colony->ants.a[i];
        unsigned int* p = screen->pixels + (ant->x + ant->y*WIDTH)*3;
        *p = (unsigned int) 0xFFFFFF;
    }
}

void update_colony(SDL_Surface* screen, colony_t colony){
    colony_update(colony, screen->pixels);
}

int main(int argc, char** argv) {

    SDL_Event evt; 
    int i,j;

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        return -1;
    }

    SDL_Surface* screen = SDL_SetVideoMode(
      WIDTH, HEIGHT, 24, 
      SDL_SWSURFACE | SDL_DOUBLEBUF);

    if(screen == NULL) {
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
        SDL_FillRect(screen, NULL, 0x000000);
        update_colony(screen, c);
        draw_colony(screen, c);
        SDL_FreeSurface(screen);
        SDL_Flip(screen);
    }

finish:
    colony_free(c);

    SDL_FreeSurface(screen);
    SDL_Quit();

    return 0;
}

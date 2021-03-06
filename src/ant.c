#include "ant.h"


ant_p ant_new(colony_p colony) {
    ant_p ant = calloc(1, sizeof(struct ant_t));
    ant->colony = colony;
    return ant;
}

void ant_free(ant_p ant) {
    free(ant);
}


void ant_set_pos(ant_p ant, int x, int y) {
    ant->x = x;
    ant->y = y;
}

//   0 1 2
//   3 4 5
//   6 7 8

void ant_update(ant_p ant) {
    // get env
    float* vision = world_get_env(ant);
    
    // think
    float* action;
    brain_update(ant->brain, vision, &action);
    
    // act
    /*
    float max = -1.0;
    int j = -1;
    for(int i=0; i<9; i++) {
        if(a[i] > max) j = i;
    }

    int x = ant->x;
    int y = ant->y;
    if (j/3==0) y--;
    if (j/3==2) y++;
    if (j%3==0) x--;
    if (j%3==2) x++;

    ant->x = x<0 ? x+WIDTH  : x>WIDTH  ? x%WIDTH  : x;
    ant->y = y<0 ? y+HEIGHT : y>HEIGHT ? y%HEIGHT : y;
    */
}


#include "ant.h"


ant_t ant_new(colony_t colony) {
    ant_t ant = calloc(1, sizeof(struct ant_t));
    ant->colony = colony;
    return ant;
}

void ant_free(ant_t ant) {
    free(ant);
}


void ant_set_pos(ant_t ant, int x, int y) {
    ant->x = x;
    ant->y = y;
}

void ant_update(ant_t ant) {

}


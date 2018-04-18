#include "types.h"

world_p world_new(size_t colonies, size_t ants) {
    world_p world = calloc(1, sizeof(struct world_t));
    kv_init(world->colonies);
    for(size_t i=0; i<colonies; i++) world_add_colony(world, ants);
    
    return world;
}

void world_free(world_p world) {
    // free each colony
    for(size_t i=0; i<world->colonies.n; i++)
        colony_free(world->colonies.a[i]);
    // destroy vector
    kv_destroy(world->colonies);
}

colony_p world_add_colony(world_p world, size_t ants) {
    colony_p colony = colony_new(world, ants);
    // create colony ants
    for(size_t i=0; i <ants; i++) colony_add_ant(colony);
    return colony;
}

void world_update(world_p world){
     // update each colony
    for(size_t i=0; i<world->colonies.n; i++)
        colony_update(world->colonies.a[i]);
}

void world_get_vision(ant_p ant) {

}

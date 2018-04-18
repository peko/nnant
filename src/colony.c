#include "colony.h"
#include "brain.h"
#include "ant.h"

// Constructor
colony_p colony_new(world_p world, size_t ants) {
    // allocate new colony
    colony_p colony = calloc(1, sizeof(struct colony_t));
    colony->world = world;
    // collective brain
    colony->brain = brain_new();
    
    // create ants
    for(size_t i=0; i<ants; i++) colony_add_ant(colony);
}

// Destructor
void colony_free(colony_p colony) {
    // Free all allocated ants
    for(size_t i=0; i<colony->ants.n; i++) {
        free(colony->ants.a[i]);
    }
    // Cleanup vector
    kv_destroy(colony->ants);

    brain_free(colony->brain);
    // Free colony itself
    free(colony);
}

// Add ant
ant_p colony_add_ant(colony_p colony) {
    // allocate new ant
    ant_p ant = ant_new(colony);
    ant_set_pos(ant, rand()%320, rand()%320);
    // push it to ants vector
    kv_push(ant_p, colony->ants, ant);
    return ant;
}

// Colony update
void colony_update(colony_p colony, unsigned char* world) {
    for(size_t i=0; i<colony->ants.n; i++) ant_update(colony->ants.a[i]);
}

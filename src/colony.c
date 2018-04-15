#include "colony.h"
#include "ant.h"

// Constructor
colony_t colony_new() {
    // allocate new colony
    colony_t colony = calloc(1, sizeof(struct colony_t));

    // node
    kad_node_t* n;
    n = kann_layer_input(81);
    n = kad_relu(kann_layer_dense(n, 32));
    n = kann_layer_cost(n, 9, KANN_C_CEM);
    colony->ann = kann_new(n, 0);
    kann_save("colony.kann", colony->ann);
    // initialize ants vector
    kv_init(colony->ants);
}

// Destructor
void colony_free(colony_t colony) {
    // Free all allocated ants
    for(size_t i=0; i<colony->ants.n; i++) {
        free(colony->ants.a[i]);
    }
    // Cleanup vector
    kv_destroy(colony->ants);
    // Free colony itself
    kann_delete(colony->ann);
    free(colony);
}

ant_t colony_add_ant(colony_t colony) {
    // allocate new ant
    ant_t ant = ant_new(colony);
    ant_set_pos(ant, rand()%320, rand()%320);
    // push it to ants vector
    kv_push(ant_t, colony->ants, ant);
    return ant;
}

void colony_update(colony_t colony) {
    for(size_t i=0; i<colony->ants.n; i++) {
        ant_update(colony->ants.a[i]);
    }
}

#include "types.h"

brain_p brain_new() {

    brain_p brain = calloc(1, sizeof(struct brain_t));
    
    // node
    kad_node_t* n;
    n = kann_layer_input(81);
    n = kad_relu(kann_layer_dense(n, 32));
    n = kann_layer_cost(n, 9, KANN_C_CEM);

    brain->ann = kann_new(n,0);
}

brain_p brain_load(const char* filename) {
    
}

void brain_save(const char* filename) {
    kann_save(fileneame, brain->ann);
}

void brain_free(brain_p brain) {
    kann_delete(brain->ann);
    free(brain);
}

void brain_update(brain_p brain, float* vision, float** action) {
    *action = kv_apply1(brain, vision);
}

void brain_mutate(brain_p brain) {}

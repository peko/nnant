#include "world.h"

int main(int argc, char** argv) {

    world_p world = world_new(2, 5); 
    for(int i=0; i<10; i++) {
        world_update(world);
    }
    world_free(world);

    return 0;
}

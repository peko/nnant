#include "types.h"

world_p world_new(size_t colonies, size_t ants);
void world_free(world_p world);

colony_p world_add_colony(size_t ants);
void world_update(world_p world);



#pragma once

#include "types.h"

ant_t ant_new(colony_t colony);
void ant_free(ant_t ant);

void ant_set_pos(ant_t ant, int x, int y);
void ant_update(ant_t ant, const float* y);


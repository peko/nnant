#pragma once

#include "types.h"

ant_p ant_new(colony_p colony);
void ant_free(ant_p ant);

void ant_set_pos(ant_p ant, int x, int y);
void ant_update(ant_p ant);


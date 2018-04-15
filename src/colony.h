#pragma once

#include "types.h"

colony_t colony_new();
void     colony_free(colony_t colony);

ant_t colony_add_ant(colony_t colony);

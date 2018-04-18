#pragma once

#include "types.h"

colony_p colony_new();
void     colony_free(colony_p colony);

ant_p colony_add_ant(colony_p colony);
void colony_update(colony_p colony, unsigned char* world);

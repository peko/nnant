#pragma once

#include <stdlib.h>

#include "kann.h"
#include "kvec.h"

typedef struct ant_t* ant_t;
typedef struct colony_t* colony_t;

typedef kvec_t(ant_t) ants_v;

typedef struct ant_t {
    colony_t colony;
    int health;
    int age;
    int x,y;
}* ant_t;

typedef struct colony_t {
    ants_v ants;
    kann_t* ann;
}* colony_t;

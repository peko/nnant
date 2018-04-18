#pragma once

#include <stdlib.h>

#include "kann.h"
#include "kvec.h"

#define WIDTH  320
#define HEIGHT 320

typedef struct ant_t    *ant_p;
typedef struct colony_t *colony_p;
typedef struct world_t  *world_p;
typedef struct brain_t  *brain_p;

typedef kvec_t(ant_p   ) ants_v;
typedef kvec_t(colony_p) colonies_v;

typedef struct ant_t {
    colony_p colony;
    float vision[81];
    float action[9];
    brain_p brain;
    int health;
    int age;
    int x,y;
}* ant_p;

typedef struct colony_t {
    world_p world;
    ants_v ants;
    brain_p brain;
}* colony_p;

typedef struct world_t {
    size_t w;
    size_t h;
    unsigned char* surface;
    colonies_v colonies;
}* world_p;

typedef struct brain_t {
    kann_t* cortex;
    // input 
    float*  perception;
    // output
    float*  reaction;
}* brain_p;

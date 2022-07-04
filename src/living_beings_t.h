#ifndef LIVING_BEINGS_H
#define LIVING_BEINGS_H

#include "GameObjects/Life.h"

typedef struct living_beings {
  Life * being;
  struct living_beings * next;
  struct living_beings * prev;
} living_beings_t;

#endif

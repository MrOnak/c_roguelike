#include "Generator.h"

long Generator::lastId = 0;

int Generator::getId() {
  lastId++;

  return lastId;
}

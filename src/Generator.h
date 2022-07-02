#ifndef GENERATOR_H
#define GENERATOR_H

#include <stdlib.h>

class Generator {
  public:
    static int getId();
  private:
    static long lastId;
    Generator();
};

#endif

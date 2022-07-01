#include "Timekeeper.h"

Timekeeper::Timekeeper() {
  currentTime = 0;
  actors = (living_beings *) malloc(sizeof(living_beings));
  last = actors;
}

void Timekeeper::update() {
  currentTime++;

  actors->being->act();
}

void Timekeeper::draw() {
  clear();
  actors->being->display();
}

long Timekeeper::getTime() {
  return currentTime;
}

bool Timekeeper::registerObject(Life& o) {
  last->being = &o;
  last->next = NULL;
  last->prev = NULL;

  return true;
}

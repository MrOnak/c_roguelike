#include "Timekeeper.h"

Timekeeper::Timekeeper() {
  currentTime = 0;
  delayBetweenActors = 100000;

  actors = (living_beings_t *) malloc(sizeof(living_beings_t));
  last = actors;
}

/**
 * calls act() on current actor and then
 * triggers a re-draw of all actors. This gives
 * a nice step-by-step look and feel
 */
void Timekeeper::update() {
  living_beings_t * current = actors;
  currentTime++;

  do {
    current->being->act();
    draw();

    current = current->next;
  } while(current->next != NULL);
}

void Timekeeper::draw() {
  living_beings_t * current = actors;

  clear();
  int i = 0;

  do {
    current->being->display();
    current = current->next;
    i++;
  } while(current->next != NULL);

  refresh();
  usleep(delayBetweenActors);
}

long Timekeeper::getTime() {
  return currentTime;
}

bool Timekeeper::registerObject(Life& o) {
  last->being = &o;
  // create next slot in the linked list and link it
  last->next = (living_beings_t *) malloc(sizeof(living_beings_t));
  last->next->next = NULL;
  last->next->prev = last;

  last = last->next;

  return true;
}

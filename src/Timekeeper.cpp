#include "Timekeeper.h"

Timekeeper::Timekeeper() {
  currentTime = 0;
  delayBetweenActors = 0.1;

  actors = (living_beings_t *) malloc(sizeof(living_beings_t));
  last = actors;
}

void Timekeeper::update() {
  living_beings_t * current = actors;
  currentTime++;

  do {
    current->being->act();
    current = current->next;
  } while(current->next != NULL);
}

void Timekeeper::draw() {
  living_beings_t * current = actors;

  clear();
  int i = 0;

  do {
    /*
    mvprintw(0, 0, "%d", i);
    mvprintw(0, 10, "%ld %c %d/%d",
      current->being->id,
      current->being->symbol,
      current->being->getPos().x, current->being->getPos().y
    );
    */

    current->being->display();
    current = current->next;

    refresh();
    sleep(delayBetweenActors);
    i++;
  } while(current->next != NULL);
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

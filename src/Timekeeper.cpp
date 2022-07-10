#include "Timekeeper.h"

Timekeeper::Timekeeper() {
  date = 0;
  time = 0;
}


long Timekeeper::getTime() {
  return time;
}

long Timekeeper::getDate() {
  return date;
}

void Timekeeper::update() {
  living_beings_t* pos = actors;
  living_beings_t* tmp = NULL;
  bool end = false;

  // internal timekeeping
  progressTime();
  // add energy to all entities in linked list
  distributeEnergy(1.0f);

  // trigger actions for all entities
  while (end == false) {
    if (pos->being->act()) {
      // re-sort entity based on new energy budget
      tmp = pos->next;
      //sortEntity(&actors, &pos);
      pos = tmp;
    } else {
      // move pointer to act upon next entity
      pos = pos->next;
    }

    end = (pos == NULL);
  }
}

void Timekeeper::setActors(living_beings_t* actorRef) {
  actors = actorRef;
}

void Timekeeper::progressTime() {
  time++;
  if (time == 86400) {date++;}
  time = time % 86400;
}

void Timekeeper::distributeEnergy(float e) {
  living_beings_t* pos = actors;

  int x = 1;
  do {
    // add energy to current entity
    pos->being->addEnergy(e);

    // move pointer to the next entity
    pos = pos->next;
  } while (pos != NULL);
}

void Timekeeper::sortEntity(struct living_beings** headRef, living_beings_t** entity) {
  living_beings_t *curr;
  living_beings_t *tmp = NULL;
  living_beings_t *old = NULL;

  // don't do anything if element is already at end of list
  if ((*entity)->next == NULL) {
    return;
  }
  // don't do anything if successor element already has lower energy
  if ((*entity)->next->being->getEnergy() < (*entity)->being->getEnergy()) {
    return;
  }

  // now we're sure we have an element that can move and does need moving
  for (curr = *headRef; curr != NULL; old = curr, curr = curr->next) {
    // identify element in list
    if (curr->being->getId() == (*entity)->being->getId()) {
      // remember element
      tmp = curr;
      // unlink it
      if (old == NULL) {
        // element is at start of list
        *headRef = curr->next;
        old = *headRef;
      } else {
        old->next = curr->next;
      }
    }

    // place element back in list
    if (tmp != NULL) {
      if (curr->next == NULL) {
        // end of list, just add
        curr->next = tmp;
        tmp->next = NULL;
        break;
      } else if (curr->next->being->getEnergy() < tmp->being->getEnergy()) {
        // add in front of entity with lower energy than self
        tmp->next = curr->next;
        curr->next = tmp;
        break;
      }
    }
  }
}

void Timekeeper::debugActorQueue(int y) {
  living_beings_t* pos = actors;

  do {
    mvprintw(y, 1, "%s %d\n", pos->being->debug(), (pos->next == NULL) ? 0 : 1);
    pos = pos->next;
    y++;
  } while (pos != NULL);

}

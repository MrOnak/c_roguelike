#include "Timekeeper.h"

long Timekeeper::date = 0;
long Timekeeper::time = 0;

Timekeeper::Timekeeper() {
}

long Timekeeper::getTime() {
  return time;
}

long Timekeeper::getDate() {
  return date;
}

/**
 * returns true if there are more entities further down the list
 * that need updating in this timestep
 */
bool Timekeeper::update() {
  living_beings_t* tmp = NULL;

  // trigger actions for all entities
  if (pos->being->act()) {
    // re-sort entity based on new energy budget
    tmp = pos->next;
    sortEntity();
    pos = tmp;
  } else {
    // move pointer to act upon next entity
    pos = pos->next;
  }

  return (pos != NULL);
}

void Timekeeper::progressTime() {
  time++;
  if (time == 86400) {date++;}
  time = time % 86400;

  // add energy to all entities in linked list
  distributeEnergy(1.0f);
  // reset position counter
  pos = *ObjectStore::getLife();
  Logger::debug("game time has stepped forward");
}

void Timekeeper::distributeEnergy(float e) {
  living_beings_t* pos = *ObjectStore::getLife();

  do {
    // add energy to current entity
    pos->being->addEnergy(e);

    // move pointer to the next entity
    pos = pos->next;
  } while (pos != NULL);
}

void Timekeeper::sortEntity() {
  living_beings_t **headRef = ObjectStore::getLife();
  living_beings_t *curr;
  living_beings_t *tmp = NULL;
  living_beings_t *old = NULL;

  // don't do anything if element is already at end of list
  if (pos->next == NULL) {
    return;
  }
  // don't do anything if successor element already has lower energy
  if (pos->next->being->getEnergy() < pos->being->getEnergy()) {
    return;
  }

  // now we're sure we have an element that can move and does need moving
  for (curr = *headRef; curr != NULL; old = curr, curr = curr->next) {
    // identify element in list
    if (curr->being->getId() == pos->being->getId()) {
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

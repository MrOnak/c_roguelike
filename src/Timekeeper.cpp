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
  bool acted = false;

  progressTime();
  distributeEnergy(1.0f);

  // rewind to beginning of linked list
  while (current->prev != NULL) {
    current = current->prev;
  }

  // trigger actions for all entities
  do {
    acted = current->being->act();
    if (acted) {
      // re-sort entity based on new energy budget
      sortEntity(current);
    } else {
      // move pointer to act upon next entity
      current = current->next;
    }
  } while (current->next != NULL);
}

void Timekeeper::setActors(living_beings_t* actor) {
  current = actor;
}

void Timekeeper::progressTime() {
  time++;
  if (time == 86400) {date++;}
  time = time % 86400;
}

void Timekeeper::distributeEnergy(float e) {
  living_beings_t* pos;

  do {
    // add energy to current entity
    current->being->addEnergy(e);
    // re-sort entity based on stored energy
    sortEntity(current);

    // move pointer to the next entity
    current = current->next;
  } while (current->next != NULL);
}

void Timekeeper::sortEntity(living_beings_t* entity) {
  living_beings_t* pos = entity;


  while (pos->next->being->getEnergy() >= entity->being->getEnergy()
    && pos->next != NULL) {
    pos = pos->next;
  }

  // un-link entity
  entity->prev->next = entity->next;
  entity->next->prev = entity->prev;

  // re-insert entity after pos
  entity->next = pos->next;
  pos->next = entity;
  entity->prev = pos;
  entity->next->prev = entity;
}

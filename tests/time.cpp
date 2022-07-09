#include <iostream>
#include <time.h>

using namespace std;


typedef struct being {
  int id;
  char symbol;
  int energy;
  int costFactor;
} being_t;

typedef struct living_beings {
  being_t* being;
  struct living_beings* next;
} life_t;

/**
 * debugs the whole queue
 */
void debugQueue(struct living_beings** headRef) {
   life_t* pos = *headRef;

  while (true) {
    printf("%d:%c(%d, %d) - ", pos->being->id, pos->being->symbol, pos->being->energy, pos->being->costFactor);

    if (pos->next == NULL) {
      break;
    } else {
      pos = pos->next;
    }
  }

  printf("\n");
}

/**
 * adds the given energy amount to all entities in the queue
 */
void distributeEnergy(struct living_beings** headRef, int e) {
  life_t* pos = *headRef;

  while (true) {
    pos->being->energy++;

    if (pos->next == NULL) {
      break;
    } else {
      pos = pos->next;
    }
  }
}

/**
 * pushes new entity in front of queue
 */
void push(struct living_beings** headRef, int id, char s, int e, int c) {
  life_t* newNode = new life_t;
  being_t* newBeing = new being_t;

  newBeing->id = id;
  newBeing->symbol = s;
  newBeing->energy = e;
  newBeing->costFactor = c;

  newNode->being = newBeing;
  newNode->next = (*headRef);
  (*headRef) = newNode;
}

bool shiftRight(struct living_beings** headRef, struct living_beings** element) {
  bool retval = false;
  life_t *curr;
  //life_t *tmp = NULL;
  life_t *old = NULL;

  // don't move right if element is at the end of the list
  if ((*element)->next == NULL) {
    return retval;
  }

  // find list item to move
  for (curr = *headRef; curr != NULL; old = curr, curr = curr->next) {
    if (curr->being->id == (*element)->being->id) {
      if (curr->next == NULL) {
        // only item in list
        return retval;
      }

      if (old == NULL) {
        // node is first in left, set head to jump over
        *headRef = curr->next;
        old = *headRef;

      } else {
        // matched node is in the middle, set next to jump over
        old->next = curr->next;
      }

      curr->next = curr->next->next;
      old->next = curr;
      retval = true;
      break;
    }
  }

  return retval;
}

/**
 * perform action as long as costFactor <= energyRequirement
 */
bool act(life_t** pos) {
  bool retval = false;

  if ((*pos)->being->energy > 0 && rand() % 2 == 0) {
    (*pos)->being->energy -= rand() % (*pos)->being->energy + 1;
    retval = true;
  }
  /*
  if ((*pos)->being->energy >= (*pos)->being->costFactor) {
    (*pos)->being->energy -= (*pos)->being->costFactor;
    retval = true;
  }
  */

  return retval;
}

/**
 * moves given entity in the queue so that it is behind all other
 * entities with higher energy than itself
 */
void sort(struct living_beings** headRef, life_t** element) {
  life_t *curr;
  life_t *tmp = NULL;
  life_t *old = NULL;

  // don't do anything if element is already at end of list
  if ((*element)->next == NULL) {
    return;
  }
  // don't do anything if successor element already has lower energy
  if ((*element)->next->being->energy < (*element)->being->energy) {
    return;
  }

  // now we're sure we have an element that can move and does need moving
  for (curr = *headRef; curr != NULL; old = curr, curr=curr->next) {
    // identify element in list
    if (curr->being->id == (*element)->being->id) {
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
      } else if (curr->next->being->energy < tmp->being->energy) {
        // add in front of entity with lower energy than self
        tmp->next = curr->next;
        curr->next = tmp;
        break;
      }
    }
  }
}

int main(int argc, char* argv[]) {
  life_t *start = NULL;
  life_t *pos = NULL;
  life_t *tmp = NULL;
  bool end = false;
  int actingCost;
  char c;

  // general initialization
  srand(time(NULL));

  // add entities to queue
  push(&start, 6, 'm', 0, 1);
  push(&start, 5, 'f', 0, 2);
  push(&start, 4, 's', 0, 3);
  push(&start, 3, 'm', 0, 1);
  push(&start, 2, 'f', 0, 2);
  push(&start, 1, 'm', 0, 1);

  pos = start;

  // debug initial queue
  debugQueue(&start);

  while (c != 'q') {
    // add energy to all entities
    distributeEnergy(&start, 1);
    printf("adding energy\n\n");
    // debug result
    debugQueue(&start);

    while (end == false) {
      printf("  #%d: ", pos->being->id);
      // act
      actingCost = pos->being->energy;
      if (act(&pos)) {
        actingCost -= pos->being->energy;
        printf("acted (energy: %d used; %d left)\n", actingCost, pos->being->energy);
        // re-sort entity
        tmp = pos->next;
        sort(&start, &pos);
        pos = tmp;

      } else {
        printf("idle\n");
        // entity didn't act, move pointer and act on next entity
        pos = pos->next;
      }

      // debug result
      debugQueue(&start);

      end = (pos == NULL);
    }

    // debug result
    printf("\nturn end queue state:\n");
    debugQueue(&start);

    // start queue from the top
    pos = start;
    c = getchar();
    end = false;
  }

  return EXIT_SUCCESS;
}

#include "LivingBeings.h"

/**
 * creates a new empty list
 */
living_beings_t* LivingBeings::newList() {
  living_beings_t *newNode = (living_beings_t *) malloc(sizeof(living_beings_t));
  newNode->being = NULL;
  newNode->next = NULL;
  return newNode;
}
living_beings_t* LivingBeings::newList(Life& element) {
  living_beings_t *newNode = (living_beings_t *) malloc(sizeof(living_beings_t));
  newNode->being = &element;
  newNode->next = NULL;
  return newNode;
}

/**
 * push element onto the beginning of the list
 */
void LivingBeings::push(struct living_beings** headRef, Life& element) {
  if ((*headRef) == NULL) {
    (*headRef) = LivingBeings::newList(element);
    return;
  }

  living_beings_t *newNode = (living_beings_t *) malloc(sizeof(living_beings_t));
  newNode->being = &element;
  newNode->next = (*headRef);

  (*headRef) = newNode;
}

/**
 * pop off the first element of the list
 */
Life* LivingBeings::pop(struct living_beings** headRef) {
  living_beings_t *first = (*headRef);
  (*headRef) = first->next;
  return first->being;
}

/**
 * non-destructively returns the nth Life in the list
 */
Life* LivingBeings::get(struct living_beings** headRef, int n) {
  living_beings_t *curr = *headRef;
  int i = 0;

  while (i < n) {
    if (curr->next != NULL) {
      curr = curr->next;
    }
    i++;
  }

  return curr->being;
}

/**
 * shift element one step further down / right the list
 */
void LivingBeings::shiftRight(struct living_beings** headRef, Life* element) {
  living_beings_t *curr;
  living_beings_t *old = NULL;
  living_beings_t *tmp = NULL;

  // find element in list
  for (curr = *headRef; curr != NULL; old = curr, curr = curr->next) {
    if (curr->being->getId() == element->getId()) {
      if (curr->next == NULL) {
        // don't move if element is already last in list
        break;

      } else if (old == NULL) {
        // flip head reference if it is first in list
        tmp = curr;
        *headRef = curr->next;
        old = *headRef;
        tmp->next = old->next;
        old->next = tmp;
        break;

      } else {
        // matched element is in list middle
        old->next = curr->next;
        curr->next = curr->next->next;
        old->next->next = curr;
        break;
      }
    }
  }
}

/**
 * shift element one step further up / left the list
 */
void LivingBeings::shiftLeft(struct living_beings** headRef, Life* element) {
  living_beings_t *curr;
  living_beings_t *old = NULL;
  living_beings_t *tmp = NULL;

  // find element in list
  for (curr = *headRef; curr->next != NULL; old = curr, curr = curr->next) {
    if (curr->next->being->getId() == element->getId()) {
      // element is second in list
      if (old == NULL) {
        tmp = curr->next;
        curr->next = tmp->next;
        tmp->next = curr;
        *headRef = tmp;
        break;
      }

      tmp = curr->next;
      curr->next = tmp->next;
      old->next = tmp;
      tmp->next = curr;
      break;
    }
  }
}

/**
 * inserts element after the given predecessor, if found
 */
bool LivingBeings::insertAfter(struct living_beings** headRef, Life& element, Life* predecessor) {
  bool retval = false;
  living_beings_t *newNode = (living_beings_t *) malloc(sizeof(living_beings_t));
  living_beings_t *curr;

  // find predecessor in list
  for (curr = *headRef; curr != NULL; curr = curr->next) {
    if (curr->being->getId() == predecessor->getId()) {
      retval = true;
      newNode->being = &element;
      newNode->next = curr->next;
      curr->next = newNode;

      break;
    }
  }

  return retval;
}

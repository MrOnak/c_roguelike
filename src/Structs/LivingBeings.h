#ifndef LIVING_BEINGS_H
#define LIVING_BEINGS_H

#include "../GameObjects/Life/Life.h"

/**
 * structure to hold a linked-list of instances of Life
 */
typedef struct living_beings {
  Life* being;
  struct living_beings* next;
} living_beings_t;

/**
 * collection of static methods to perform operations on a
 * linked-list of Life
 */
class LivingBeings {
  public:
    /**
     * creates a new empty list
     */
    static living_beings_t* newList();
    static living_beings_t* newList(Life& element);

    /**
     * push element onto the beginning of the list
     */
    static void push(struct living_beings** headRef, Life& element);

    /**
     * pop off the first element of the list
     */
    static Life* pop(struct living_beings** headRef);

    /**
     * non-destructively returns the nth Life in the list
     */
    static Life* get(struct living_beings** headRef, int n);

    /**
     * shift element one step further down / right the list
     */
    static void shiftRight(struct living_beings** headRef, Life* element);

    /**
     * shift element one step further up / left the list
     */
    static void shiftLeft(struct living_beings** headRef, Life* element);

    /**
     * inserts element after the given predecessor, if found
     */
    static bool insertAfter(struct living_beings** headRef, Life& element, Life* predecessor);
};
#endif

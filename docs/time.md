# time and event handling

## fundamentals
The game is fundamentally turn-based. Every living thing gets an action or several, the player controlled character is simply one of them. This includes plants which do grow (seeds turn into plants which produce fruits which are eaten by birds which propagate new seeds, ...).

Implementation idea: Characters have a different action speed, so a fast character might get an action more frequently than a slow one. Turn-based doesn't mean "all characters are in a fixed execution queue".

## tracking of time
The game-loop increases game time by a fixed amount, maybe a second of game time per game-loop. The game has a `long time` variable to track progession of time and another `long date` variable to track days and through that, seasons.

## algorithm to handle entity actions over time
Every `Life` has an `energy` account, and an internal `costFactor` constant.

The `Life.getEnergy()` method returns the amount of energy accumulated in `energy`.

Another method, `Life.addEnergy(int e)` adds a given amount to `energy`.

When `Life.act()` is called, it will internally query the behavor finite-state-machine to perform an action. That action will return a fixed `cost` to `Life.act()`. `Life.act()` will multiply `cost` with `costFactor` and substract the result from the `energy` budget.

Pseudo-implementation:
```
  bool Life.act() {
    bool acted = false;
    // determine what would be the next action and return its raw cost
    float cost = behavior.determineAction();
    // multiply raw cost with specific factor(s)
    cost = cost * costFactor;

    // enough stored energy to perform the action?
    if (energy >= cost) {
      acted = true;
      // substract energy cost and execute the action
      energy -= cost;
      behavior.executeAction();
    }

    return acted;
  }
```

This allows a single behavior state-machine or single state to be re-used across all sorts of life forms. The life form and effects on it ("ring of haste") determines how much energy the generic action will cost for this specific creature.

The game-loop works like this:
1. iterate through the whole queue and call `.addEnergy(n)` to add a fixed amount of energy to every `Life`, let's say n=1.
2. the whole queue is sorted by `.getEnergy()` so that the creatures with the highest energy accumulation are in front of the queue (_algorithmically steps 1 and 2 can probably be done in a single iteration_)
3. iterate through the queue again and execute `.act()` once per entity.
  1. if the entity performed an action, re-sort the entity further down the queue based on the new `.getEnergy()`
  2. if the entity didn't perform an action (and therefore `.getEnergy() is unchanged`) keep the entity at the current position in the queue but move the queue pointer to `current->next`

**Dry Run**:
Consider a queue where `creature(e, f)` is an entity with e `energy` and a `costFactor` of `f`.
The only available behavior for all entities is `walk` with a base cost of 1.

Initial queue: `mouse(0, 1) - frog(0, 1) - sloth(0, 3)`

1. // game-loop 1
2. add energy and re-sort: `mouse(1, 1) - frog(1, 1) - sloth(1, 3)`
3. act (mouse walks): `frog(1, 1) - sloth(1, 3) - mouse(0, 1)`
4. act (frog walks): `sloth(1, 3) - mouse(0, 1) - frog(0, 1)`
5. act (sloth cannot walk, not enough energy): `sloth(1, 3) - mouse(0, 1) - frog(0, 1)`
6. // game-loop 2
7. add energy and re-sort: `sloth(2, 3) - mouse(1, 1) - frog(1, 1)`
8. act (sloth cannot walk, not enough energy): `sloth(2, 3) - mouse(1, 1) - frog(1, 1)`
9. act (mouse walks): `sloth(2, 3) - frog(1, 1) - mouse(0, 1)`
10. act (frog walks): `sloth(2, 3) - mouse(0, 1) - frog(0, 1)`
11. // game-loop 3
12. add energy and re-sort: `sloth(3, 3) - mouse(1, 1) - frog(1, 1)`
13. act (sloth walks): `mouse(1, 1) - frog(1, 1) - sloth(0, 3)`
14. act (mouse walks): `frog(1, 1) - sloth(0, 3) - mouse(0, 1)`
15. act (frog walks): `sloth(0, 3) - mouse(0, 1) - frog(0, 1)`

**Observations** :
* The queueing makes sure that every entity will, eventually, perform an action.
* Entities with a low `costFactor` will act more frequently than those with a higher one.
* `costFactor` could be expanded into an internal function to take into account temporary effects (adrenaline, drugs, cybernetic implants, enchantments, spells) on a per-entity basis.
* danger: with added effects `costFactor` can potentially become zero or negative, leading to a creature that can stop time and act forever. _Temporarily this might be a desirable effect (think Matrix bullet-time)_
* `Life.act()` must return bool to determine whether or not an action was taken:
  *  The pointer in the game-loop would have to move forward to `current->next` when the `current->being` didn't perform an action because the entity mustn't be re-sorted to the back of the queue

**Another dry run with different values**

Consider a queue where `creature(e, f)` is an entity with e `energy` and a `costFactor` of `f`.
The only available behavior for all entities is `walk` with a base cost of 1.
The * character indicates the pointer in the queue after the step.

Initial queue: `dog(0, 3) - frog(0, 2) - mouse(0, 1)`
1. // loop 1
2. energize & sort: `* dog(1, 3) - frog(1, 2) - mouse(1, 1)`
3. act (dog can't): `dog(1, 3) - * frog(1, 2) - mouse(1, 1)`
4. act (frog can't): `dog(1, 3) - frog(1, 2) - * mouse(1, 1)`
5. act (mouse can): `dog(1, 3) - frog(1, 2) - * mouse(0, 1)`
5. act (mouse can't): `dog(1, 3) - frog(1, 2) - mouse(0, 1) - *`
6. // loop 2
7. energize & sort: `* dog(2, 3) - frog(2, 2) - mouse(1, 1)`
8. act (dog can't): `dog(2, 3) - * frog(2, 2) - mouse(1, 1)`
9. act (frog can): `dog(2, 3) - * mouse(1, 1) - frog(0, 2)`
10. act (mouse can): `dog(2, 3) - * frog(0, 2) - mouse(0, 1)`
11. act (frog can't): `dog(2, 3) - frog(0, 2) - * mouse(0, 1)`
12. act (mouse can't): `dog(2, 3) - frog(0, 2) - mouse(0, 1) - *`
13. // loop 3
14. energize & sort: `* dog(3, 3) - frog(1, 2) - mouse(1, 1)`
15. act (dog can): `* frog(1, 2) - mouse(1, 1) - dog(0, 3)`
16. act (frog can't): `frog(1, 2) - * mouse(1, 1) - dog(0, 3)`
17. act (mouse can): `frog(1, 2) - * dog(0, 3) - mouse(0, 1)`
18. act (dog can't): `frog(1, 2) - dog(0, 3) - * mouse(0, 1)`
19. act (mouse can't): `frog(1, 2) - dog(0, 3) - mouse(0, 1) - *`

**Observations**
* Mouse moves every game-loop, as it should
* Frog moves every 2 loops, dog moves every three loops
* entities get re-queried after they have been moved down the queue, as the pointer moves towards the end. This enables entities with low `costFactor` to act more often than slower ones.
* time still only progresses once per loop, so re-querying entities within a single loop is no issue.

# GameObject Properties
Musings on common properties of all the things in the game.

Class inheritance obviously does apply.

## GameObject
implemented:
* `long id` - automatically generated Id
* `struct pos` - x/y coordinates
* `char symbol` - visual representation

thoughts:
* `int weight` - weight in kg
* `int colorPair` - ncurses color pair index
* `char* name` - object name, might be changeable by the instance, for example a "seed" turning in to a "sappling" turning into a "tree".

## Life
implemented:
* `float energy` - energy counter. is filled with each game-loop and used up by actions
* `float costFactor` - energy modifier. influences how expensive actions are for a specific life form

thoughts:
* `class behaviour` - finite state machine
* `long birthdate` - nothing is eternal, keeping track of the age of a lifeform will be useful: natural death, plant growth, mobility modifiers, changes in behavioural capabilities.
* `float hunger` - the need to manage food consumption is tedious as a player but it is a good driver for urgency and prevents excessive delays. also, hunger might be a good motivator for the behaviour state machine -> hungry mice go foraging and help spread seeds.
* `class fov` - field of vision. I have previous experiences how to implement this but no concrete plan how to do it here. Might not be a property at all. **we might need an `animal` subclass, fov makes no sense for plants.**

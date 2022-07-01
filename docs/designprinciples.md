# Notes and fundamental design principles

## overview
This will be a turn-based game in the spirit of roguelikes. It will run in the command-line interface and require only a keyboard for control.

80x24 character terminals with color support will be sufficient.

As much of the content will be procedurally generated to keep the experience interesting for myself.

One game goal is to create a deep and complex world that is a joy to explore and interact with.

### setting
broadly speaking this will be a generic fantasy world with animals, several intelligent species and some sort of magic / spell-casting. That said, I don't see this limited to a Tolkin-esque world with elves and goblins. There is nothing that does prevent a sci-fi setting with high technology and space travel.

### NPCs
I want NPCs to be autonomous and as close to player characters as possible. There is no aim for true artificial intelligence but I the goal is that every NPC interacts with the environment: Mice forage for food, sleep and procreate. Foxes hunt mice. Intelligent races have homes, a society / group interactions of sorts and might expand their settlements.

At the base of NPC behavior will probably be finite state machines. I'll see how far I can push the concept for the more complex behaviors and interactions.

### time
The game will fundamentally turn-based. Every NPC will get an action or several, the player controlled character is simply one of them.

_Implementation idea_: Characters have a different action speed, so a fast character might get an action more frequently than a slow one. Turn-based doesn't mean "all characters are in a fixed execution queue".

## technical foundation
I'll keep dependencies to a minimum. This should be as much plain C and C++ as possible. C++ will be required since I cannot / don't want to work without classes and inheritance.

ncurses will be used to help me with fundamental screen control and simply because I want to learn it. ncurses is widely available so that will not hinder adaptability to other platforms.

I will develop as much code myself as possible since one major goal of this project is to learn C and I simply love developing algorithms and solving problems. That said, there is a high likelihood that I will make use of open source algorithms like perlin / simplex noise, A* pathfinding or a finite state machine.

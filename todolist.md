# immediate todo list

This includes anomalies and known defects as well as next steps. The list doesn't aim to be a roadmap nor does it aim for completeness. The purpose is to bridge over any longer implementation gaps.

* improve Logger to accept snprintf() raw parameters
* extend map walkability to take into account objects and lifeforms like trees that aren't passable
* use a config file
* test generic Makefile directives
* the usleep() call in the main game-loop could be moved to MapWindow.draw() in order to only cause a usleep() if the entity that moved is actually on the visible part of the screen. For that to work MapWindow needs to be able to find out which all GameObjects have been touched.
* line of sight
* field of vision
* behaviours as finite state-machines
* basic non-living objects
* inventory system
* interactions between instances Life

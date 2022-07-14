# immediate todo list

This includes anomalies and known defects as well as next steps. The list doesn't aim to be a roadmap nor does it aim for completeness. The purpose is to bridge over any longer implementation gaps.

* implement a logger with loglevels
* use a config file
* change map scrolling so that for large maps the player character moves off-center when near the edges of the map so that areas outside of the map are not shown, but instead more map remains visible.
* ensure that the player entity is always drawn last so that it is always visible
* test generic Makefile directives
* the usleep() call in the main game-loop could be moved to MapWindow.draw() in order to only cause a usleep() if the entity that moved is actually on the visible part of the screen. For that to work MapWindow needs to be able to find out which all GameObjects have been touched.
* line of sight
* field of vision
* behaviours as finite state-machines
* basic non-living objects
* basic plants (inheriting from Life)
* inventory system
* interactions between instances Life

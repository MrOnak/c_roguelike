# immediate todo list

This includes anomalies and known defects as well as next steps. The list doesn't aim to be a roadmap nor does it aim for completeness. The purpose is to bridge over any longer implementation gaps.

* the Timekeeper.update() loop or the Timekeeper.sortEntity() within that doesn't seem to re-sort the entities according to their remaining energy - this needs testing
* the main game loop isn't handling usleep() correctly, some entities seem to act() immediately, without delay
* the usleep() call in the main game-loop could be moved to MapWindow.draw() in order to only cause a usleep() if the entity that moved is actually on the visible part of the screen. For that to work MapWindow needs to be able to find out which all GameObjects have been touched.

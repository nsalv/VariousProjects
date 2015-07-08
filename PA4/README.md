Programming Assignment 4
------------------------

Due Date: July 16, 11:59pm (i.e. Thursday at midnight)

Create a directory PA4 in your sum15-GITNAME repo with the following programs:

* curlingsim.cpp 


curlingsim.cpp
--------------

Summary: write a C++ program that simulates 2D collisions in the context of the sport of curling.

Details:

The "simulation world" is a 5 m x 5 m patch of ice. You can either leave the ice blank (white) or for fun, draw a "curling house" in the center (see https://en.wikipedia.org/wiki/Curling#Curling_sheet)

Assume the curling stones have a diameter of 11.4 inches and are of equal mass.

When two curling stones collide, assume for now that the collision is perfectly elastic.

Your program should have three modes, controlled by the keyboard.

- random mode: create 10 stones at random but non-intersecting locations on the ice. The velocity of a new stone should have a random direction and a speed uniformly distributed between 0.2 m/s and 1.0 m/s. Whenever a stone leaves the patch, it is replaced by a new stone.

- test mode: create 2 stones, one placed exactly on the "button" and directed toward it at a speed of 1.0 m/s.
The moving stone should be placed so that it strikes a "random amount" of the stationary stone (somewhere between a direct blow and a complete miss)

- bounce mode: this is the same as random mode, but now the edge of the "world" is a boundary that the stones bounce off of. Stones cannot leave the world and so do not need to be replaced.

Your program should react to four key presses:
 
 - q : quit the game
 - r : enter random mode
 - b : enter bounce mode
 - t : enter test mode


You should use the SFML libraries to implement the game.

# MemoryMatch

Some of my college work in C++. The user decides to randomize a number board or not, then tries to match number pairs on it. Runs from Memory.cpp


________________________________________________________________________________
HOW TO PLAY:

For "y or n?" put either y or n to randomize number positions or not. Not randomizing is good for testing the game or seeing how the game works.

After the prompt will ask for a number pair, an X then a Y coordinate, which reveals the related position. 

Ensure to input a single number then *enter key* for the X then repeate for the Y coordinate. Y goes top to bottom 1-4, X goes left to right 1-4.

Two positions can be seen per try, 15 tries are given to match otherwise resulting in a loss. If the two positions are equal numbers, a match is achieved. Match them all to win.
  
________________________________________________________________________________
NOTE: The game should be very scalable, consider the following if this is desired>>
  
 1: The board size can be edited in MemoryBoard.h just change the ARRAYSIZE from 4.
  
 2: Tries can be edited in Memory.cpp change the tries variable from 15.
  

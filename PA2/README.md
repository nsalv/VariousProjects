Programming Assignment 2
========================

Due Date: June 18th 11:59pm (i.e. Thursday at midnight)

Create a directory PA2 in your sum15-GITNAME repo with the following
programs:

* validsudoku.cpp
* eightqueens.cpp


EXAMPLE input and output files are available in the directories:

- example_sudoku_inputs
- example_eight_queens_files

********

validsudoku.cpp
===============

Summary: test if a board is a "sudoku" board.

Details: 

Write a program that will read a "solved" (i.e. fully revealed) 
sudoku board and determine if the board has the appropriate
placement of nine unique symbols in each row, column, and box.

The symbols may be the usual digits (1 to 9) or any nine different
letters or numbers. For example the board might have "abcdefghi"
or "ABC123def" as its nine symbols.

The name of the input file is determined in one of two ways:

- read from the command line 
- if no value is provided, the default name is "sudokuboard.txt"


The program should output to standard output "valid" or "invalid"
and nothing else.

If the file cannot be opened or is otherwise not present, the output 
should be "invalid"


Example usage:
--------------
    > validsudoku 
    invalid
    > validsudoku mybadboard.txt
    invalid
    > validsudoku mygoodboard.txt
    valid
    > validsudoku bad_file_name.txt
    invalid

The file format is 9 characters per line, representing each row, as in:

    123789456
    789123456
    123456789
    234567891
    345678912
    456789123
    567891234
    678912345
    789123456

Note: this is not a valid sudoku board.

Example boards will be provided in the format expected. 

*******


eightqueens.cpp 
---------------

Summary: determine if a Chess situation is an eight queens puzzle solution.

Details:

Write a program that will read  Chess situations in a FEN format file
"attack.fen" (http://en.wikipedia.org/wiki/Forsyth-Edwards_Notation)
but which only contains white queens. The first field describes
the positions of the pieces on a 8x8 chess board.  The  last five
fields can be ignored, but they will always be "w - - 0 1"

Determine if the board describes a valid solution to the "Eight Queens Puzzle"
(http://en.wikipedia.org/wiki/Eight_queens_puzzle)

For each line (situation) in "attack.fen", create a file with the same data as 
"attack.fen" but with the phrase " 8 queens solution" appended to each line.
The output file should be called "attack.sol"

You do not have to perform error checking on the input: the file will only 
contain valid input, and only white queens.

Note: example input/output files will be provided for you to test your code on.


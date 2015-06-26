Programming Assignment 3
------------------------

Due Date: June 25th, 11:59pm (i.e. Thursday at midnight)

Create a directory PA3 in your sum15-GITNAME repo with the following
programs:

* tttwinner.cpp 
* twowords.cpp


EXAMPLE input and output files are available in the directories:

- example_ttt_files

The "enable1.txt" word list is also provided here in this directory.

********


tttwinner.cpp 
-------------

Summary: write A C++ program that reads tic-tac-toe  scenarios from a
file and determines the status of each game.

Details:

The data is in a file named "tictactoeboards.txt" 

Each line of the file represents a tic-tac-toe board, as follows:

    x represents x
    o represents o
    # represents an unplayed space

The first three characters are the top row, the next three the middle
row, and the last three are the bottom row.

So the line:

    xox#x#xox

represents the board

     x |  o  |  x  
       |     |      
    ---+-----+-----
       |  x  |
    ---+-----+----- 
       |     |  
     x |  o  |  x

The program should classify the board as one of the following:

- invalid 
- valid, tie game and no spaces left 
- valid, x has won
- valid, o has won 
- valid, game continues

The result of running the program should be the creation of a new file
"tttstatus.txt" which contains the original board data plus a space
and a letter indicating the status, one of  "i" for invalid, "x" for x
won, "o" for o win, "t" for tie game, or "c" for game continues.

The line in the output file for the above board should be

    xox#x#xox i


Note: a game can be invalid for many reasons, such as too many
winners, unbalanced number of x's and o's, etc. A valid game board is
one that can be arrived at by two players following the rules (but
possibly playing badly). 

Note especially the following rules: 

- x always plays first.
- no one can make additional x's or o's after one of the two players has won the game.

Do not "anticipate" tie games: a game is considered a tie only if all
the spaces are filled.

Note: example input/output files will be provided.

*******

twowords.cpp
------------

Summary: write a program to find all two word combinations from a word list

Details:

The program is designed to be a "helper/solver" for the app "Just 2 Words".

The program functions as follows: given a wordlist, a collection of letters, and 
the length of one of the words, find all possible two words "answers" that use
exactly the collection of letters given.

The default word list is "enable1.txt" (provided) and the default collection of 
letters aadekmmnortww. The default word length is 7.

Note: the program either uses all the defaults or all three parameters must be specified.

    > twowords
    sadness unfolds  
    > ./twowords enable1.txt testifythesis 6
    feisty theists
	heists testify
	shiest testify
	thesis testify

Note: "sadness unfolds" is not the correct default answer. That is for you to discover
with a working program.

Other specifications:

- the output can be in any order, and it can be shortest or longest word first
- if there is no match for any reason, the program should exit silently (and output nothing)
- you may use any of libraries in the standard library. 



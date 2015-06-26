Programming Assignment 1: EC327 Summer 2015
===========================================

Due Date: June 11th 11:59pm (ie. Thursday at midnight)

Create a directory PA1 in your sum15-GITNAME repo with the following programs:

* divisorsum.cpp
* happy.cpp
* perfect.cpp
* consecutive.cpp
* multibase.cpp
* binaryfinder.cpp

as described below.

In this first assignment, your programs will be graded on correctly
meeting the requirements (not on style or efficiency)

divisorsum.cpp
--------------

Write a C++ program divisorsum.cpp which prints the proper divisor sum
of the integers from 2 to 1000, inclusive, one value per line.

The proper divisors of an integer x are all positive divisors of x not including x itself.

Example: the proper divisor sum for 8 is 1+2+4 = 7.


happy.cpp
---------

Write a C++ program happy.cpp which prints the first 100,000 happy numbers.

The numbers should be printed 10 per line, with a single space between the values.

The first line of the output should be

    1 7 10 13 19 23 28 31 32 44

See http://en.wikipedia.org/wiki/Happy_number or http://mathworld.wolfram.com/HappyNumber.html
for the definition of a happy number.



perfect.cpp
-----------

Write a C++ program perfect.cpp that contains a function

    bool is_perfect (long int n) 

which returns true if n is a perfect number and false if it is not.

The program should continually ask for a number X from the console, and print "X is perfect" or "X is not perfect"

The program should exit if end-of-file is encountered, or 0 is entered, printing "Goodbye."


Example:
   

    >perfect
    Enter a number to test for perfectness: 28
    28 is perfect
    Enter a number to test for perfectness: 10000
    10000 is not perfect
    Enter a number to test for perfectness: 0
    Goodbye.
   

See http://en.wikipedia.org/wiki/Perfect_number for the definition.



consecutive.cpp
---------------

Write a C++ program that continuously reads 
integers from the console input (`cin`) until X consecutive integers are found, or the end-of-file is encountered. The program should work for any integer x greater than or equal to 2.


If X consecutive integers are found,
the program should print them, as follows:

    Sequence found: 15 16 17 18

and then quit.

If no sequence is found, the program should exit silently (i.e. print nothing).

The program should accept a single command line argument: the length X to stop on.

The program should exit with an error code if 

-- there is no sequence length specified
-- the value specified cannot be converted to an integer
-- the value is not an integer larger than 1


Clarifications
--------------

the program is run as follows:

    >consecutive 4

Suppose the input is 

    1 2 1
    1 6 7 8 10
    5 12 13 -8 14
    15 0 19 20 21 22 25
    (EOF)

(EOF) represents control-D

The integers read will be 1 2 1 1 6 7 8 10 5 12 13 -8 14 15 0 19 20 21 22

and then the program will stop, seeing the four 
consecutive integers 19 20 21 22 and 
will print

    Sequence found: 19 20 21 22




multibase.cpp
-------------

Write a C++ program multibase.cpp that will prompt the user for an integer Y, and
respond with all integers x such that  Y in base x is a palindromic number.

Only report the values x between 2 and Y, since all numbers Y are
palindromic in base x > Y.

A palindrome in base x reads the same forward and backwards.

Example:

    >multibase
    Enter the number to test for palindromicity: 456
    7
    23
    37
    56
    75
    113
    151
    227
    455    
    
This means that the number 456 is palindromic in base 7,23, ...,455.

For example 456 in base 227 is "22"

binaryfinder.cpp
----------------

Write a C++ program that will determine if a particular sequence of binary digits appears in a number.

The program accepts two numbers: the test number X and the test sequence Y. 
The test number X is entered in decimal, and the test sequence Y in binary.

Examples:
    
    >binaryfinder
    234 1001
    Sequence 1001 does not occur in 234.

    >binaryfinder
    20 101
    Sequence 101 occurs in 20.
   
    >binaryfinder
    -234 10021
    Number must be positive.
    Sequence must be binary.

Specifications:

* leading zeros in the binary sequence are ignored. For example, if X
  is 9 (1001) and Y is specified as "0100" the result will be
  "Sequence 100 occurs in 9."

* the first number entered must be positive. If it is not, print
  "Number must be positive."

* the second number must be positive. If it is not, print, "Sequence must be positive."

* the second number entered must be a valid binary number (only
  containing 1s and 0s). If it is not, print "Sequence must be
  binary."

Restrictions:

* you may not define any string or chr variables in your solution.


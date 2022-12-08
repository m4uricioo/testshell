 ## C - Simple Shell

# General
Who designed and implemented the original Unix operating system
Who wrote the first version of the UNIX shell

How does a shell work
What is the difference between a function and a system call
How to create processes
How does the shell use the PATH to find the programs
How to execute another program with the execve system call
How to suspend the execution of a process until one of its children terminates
 
 
 # General Requirements 
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line


A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarde

_________________________________________________________________________________________________________________________________

Simple Shell project
Introduction

This simple shell project is project. It consists of developing and making our own UNIX command interpreter (Shell).

What is a shell

The shell is an interface to the operating system. It acts as a command interpreter; 

it takes each commands and passes it to the operating system.

About this project
The objective of this project was to mirror how the real shell (sh) works using a custom version of almost every library function needed.
A simple shell version of the original one.

What our shell can handle:
-Executes any command with its arguments
-Executes any command with its arguments using relative or absolute routes
-Executes built-in commands
-Handles ';' command seperator
-Handles the "end of file" condition (Ctrl+D)
-Handles errors
-Handles the PATH
-Handles exit[arguments] built-in
-env built-in implemented
-Handles Ctrl+C
-Handles comments (#)
-Handles interactive mode
-Handles non-interactive mode

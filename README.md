# simple_shell
**simple shell (hsh)** is a command language interpreter that shall execute commands read from a command line string and the standard input.
**simple_shell** program was build using the C language, and was designed to interact with a linux distribution or unix like system that uses system calls and other commands found in the linux PATH.

## Table of contents
* Description
* Learning objectives
* What is the file structure
* How to install
* Functionalities
* Builtings
* Using example
* Bugs
* Authors

## Description
Simple shell (./hsh) is a command line interpreter inspirated in ./sh shell. 
It was created with system calls and standard function like 
` fork(), wait(), getline, stat, malloc, free, perror, and others. `
When a command is executed, the program will made the action that the user wish and will print the shell prompt again ($).


## Requeriments
Compiled with Ubuntu 14.04 LTS using flags `-Wall -Werror -Wextra and -pedantic.`


## Learning objectives
* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / “end-of-file”?

## What is the file structure
**AUTHORS** - this file contains a list of contributors of this project.
**executor.c** - this file perform operations of execute commands on simple_shell.
**holberton.h** - file contains all prototypes of functions that we used.
**main.c** - file contains the entry point to program.
**man_1_simple_shell** - this file
**_prompt.c** - file that contains the call to prompt and catch the user input.
**README.md** - file contains a brief description of how works the simple_shell.
**searchpath.c** - file used to find the valid path to commands that need to be executed.
**token.c** - file contains the routines to split the user input in commands.
**workfunctions.c** - file contains helper functions.
**workfunctions2.c** - file contains helper functions.


## How to install
1) Clone this repository using git clone: `git clone https://github.com/dfbq91/simple_shell`
2) Use cd to change directories into the repository simple _shell: `cd simple_shell`
3) Compile. We recommend use flags wall, werror, wextra and pedantic:` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `
4) Run the program. You can use interactive mode `./hsh` and type command, or non-interactive mode.
> example: `echo "ls" | ./hsh`


## Functionalities
- [x] ls
- [x] pwd
- [x] echo
- [x] cat


### Builtings
- [X] Don't have builting created.


## Using example
```
vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh
$ ls
AUTHORS  README.md  _prompt.c  executor.c  holberton.h  hsh  main.c  man_1_simple_shell  searchpath.c  token.c  workfunctions.c
$
$ ls -l
total 56
-rw-rw-r-- 1 vagrant vagrant   180 Nov 23 19:28 AUTHORS
-rw-rw-r-- 1 vagrant vagrant   823 Nov 23 19:28 README.md
-rw-rw-r-- 1 vagrant vagrant   670 Nov 23 19:28 _prompt.c
-rw-rw-r-- 1 vagrant vagrant   534 Nov 23 19:28 executor.c
-rw-rw-r-- 1 vagrant vagrant   577 Nov 23 19:28 holberton.h
-rwxrwxr-x 1 vagrant vagrant 13957 Nov 24 04:23 hsh
-rw-rw-r-- 1 vagrant vagrant   151 Nov 23 19:28 main.c
-rw-rw-r-- 1 vagrant vagrant   672 Nov 23 19:28 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   831 Nov 23 19:28 searchpath.c
-rw-rw-r-- 1 vagrant vagrant   892 Nov 23 19:28 token.c
-rw-rw-r-- 1 vagrant vagrant  2074 Nov 23 19:28 workfunctions.c
$

```
## How it works: flowchart
![flowchart_simple_shell](https://github.com/dfbq91/simple_shell/blob/master/simple_shell.png)

## Bugs
> We have some memory leaks on our project, and we have some functions that exceed the limit of lines.
## Authors
> Diego Betancourt -  Jackson Moreno

# simple_shell

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
Simple shell (./hsh) is a command line interpreter inspirated in ./sh shell. It was created with system calls and standard function like fork, wait, getline, wait, stat, malloc, free, perror, and others.
When a command is executed, the program will made the action that the user wish and will print the shell prompt again ($).

## Requeriments
Compiled with Ubuntu 14.04 LTS using flags -Wall -Werror -Wextra and -pedantic.

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
AUTHORS: List of the authors and contributors to this repository.
man_1_simple_shell - Manual page.
holberton.h - Header file.
workfunctions.c - Customized Functions called in other files.


## How to install
1) Clone this repository using git clone: git clone https://github.com/dfbq91/simple_shell
2) Use cd to change directories into the repository simple _shell: cd simple_shell
3) Compile. We recommend use flags wall, werror, wextra and pedantic: gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
4) Run the program. You can use interactive mode ./hsh and type command, or non-interactive mode, example: echo "ls" | ./hsh

## Functionalities

### Builtings

## Using example
`vagrant@vagrant-ubuntu-trusty-64:~/simple_shell$ ./hsh<br />
$ ls<br />
AUTHORS  README.md  _prompt.c  executor.c  holberton.h  hsh  main.c  man_1_simple_shell  searchpath.c  token.c  workfunctions.c<br />
$`<br />
`$ ls -l<br />
total 56<br />
-rw-rw-r-- 1 vagrant vagrant   180 Nov 23 19:28 AUTHORS  
-rw-rw-r-- 1 vagrant vagrant   823 Nov 23 19:28 README.md  
-rw-rw-r-- 1 vagrant vagrant   670 Nov 23 19:28 _prompt.c<br />
-rw-rw-r-- 1 vagrant vagrant   534 Nov 23 19:28 executor.c<br />
-rw-rw-r-- 1 vagrant vagrant   577 Nov 23 19:28 holberton.h<br />
-rwxrwxr-x 1 vagrant vagrant 13957 Nov 24 04:23 hsh<br />
-rw-rw-r-- 1 vagrant vagrant   151 Nov 23 19:28 main.c<br />
-rw-rw-r-- 1 vagrant vagrant   672 Nov 23 19:28 man_1_simple_shell<br />
-rw-rw-r-- 1 vagrant vagrant   831 Nov 23 19:28 searchpath.c<br />
-rw-rw-r-- 1 vagrant vagrant   892 Nov 23 19:28 token.c<br />
-rw-rw-r-- 1 vagrant vagrant  2074 Nov 23 19:28 workfunctions.c<br />  
$`<br />

## Bugs

## Authors
Diego Betancourt  
Jackson Moreno  

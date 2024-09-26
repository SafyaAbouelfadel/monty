# The Monty Language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (similar to Python). It uses a unique stack structure with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Byte Code Files

Files containing Monty byte codes typically have the `.m` extension. While most of the industry adheres to this convention, it is not required by the language specification. There is no more than one instruction per line. Any number of spaces may precede or follow the opcode and its argument:

```bash
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
```
You should compiled the files this way:
```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
Any output will be printed on stdout. Any error message will be printed on stderr

#Usage:
```bash
./monty <file>
```
Where file is the path to the file containing Monty byte code. If the user does not give any file or more than one argument to your program, print the error message:

#USAGE:
```bash
monty file
```
Followed by a new line, and exit with the status EXIT_FAILURE. If, for any reason, it’s not possible to open the file:
```bash
Error: Can't open file
```
Followed by a new line, and exit with the status EXIT_FAILURE, where is the name of the file. If the file contains an invalid instruction:
```bash
L<line_number>: unknown instruction
```
Followed by a new line, and exit with the status EXIT_FAILURE where is the line number where the instruction appears. Line numbers always start at 1. The monty program runs the bytecodes line by line and stop if either:

it executed properly every line of the file
it finds an error in the file
an error occured
If you can’t malloc anymore, print the error message:
```bash
Error: malloc failed
```
Followed by a new line, and exit with status EXIT_FAILURE. We used malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

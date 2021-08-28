## A Monty Interpreter written in C

Monty 0.98 is a scripting language that is first compiled into Monty byte codes.
It relies on a unique stack, with specific instructions to manipulate it.
 The goal of this project is to create an interpreter for Monty ByteCodes files.

     > Tip - Files containing Monty byte codes usually have the `.m` extension.
       Most of the industry uses this standard but it is not required by the
        specification of the language.

## Compilation & Output
Git clone this repository and compile the code this way:

   `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## Usage
`monty file`
      > where file is the path to the file containing Monty byte code

## Opcodes
* `push` adds an element to the stack.
* `pall` prints all the values on the stack, starting from the top of the stack.
* `pint` prints the value at the top of the stack, followed by a new line.
* `pop` removes the top element of the stack.
* `swap` swaps the top two elements of the stack.
* `add` adds the top two elements of the stack.

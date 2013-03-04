# minidc
======

## Modelled after the UNIX command line tool “dc”

Minidc is a reverse-polish desk calculator.   Minidc reads from the standard input.  All normal output is to standard output; all error output is to standard error.

A reverse-polish calculator stores numbers on a stack.  Entering a number pushes it on the stack. Arithmetic operations pop arguments off the stack and push the results.

To enter a number in Minidc, type the digits with an optional decimal point. To enter a negative number, begin the number with “_”.  “-” cannot be used for this, as it is the operator for subtraction instead.

## Specification
```
P 	Prints the value on the top of the stack, without altering the stack.
n 	Prints the value on the top of the stack, popping it off.
f 	Prints the entire contents of the stack without altering anything.
+ 	Pops two values off the stack, adds them, and pushes the result.
-  	Pops two values off the stack, subtracts the first one popped from the second one popped, and pushes the result.
* 	Pops two values, multiplies them, and pushes the result.
/ 	Pops two values, divides the second one popped from the first one popped, and pushes the result.
```

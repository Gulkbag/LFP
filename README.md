# What is LFP?
This is a lisp that i made just for the sake of learning, What does LFP stand for? "Lisp For Pussies",

Since this is not really a lisp nor a non lisp this is just a bang bang of all my thoughts,

Nor this language is made for people to actually program in it or anything else, it's full of bugs, and problems

# Getting Started
### Installation
There is no binary for this since it doesn't use many external libraries or anything
For Windows simply having Mingw on your system and running ``mingw32-make`` in the directory of the Makefile will do it and you will have the binary
For linux you will have to install the editline library, i don't know what package manager you are using so just search it up.
Then Replace the normal MakeFile with the simply named LinuxMakefile and proceed with the command ``make`` and kaboom you have a binary

### Using The Language
LFP Doesn't Compile at all, it all runs inside a REPL (Read Eval Print Loop), tho you can load external files for including libraries and such.
The Source code comes with the base library conventionally named ``std.lpsy`` which you can load from inside the REPL by using the ``load`` command

Followed by a C string of the file name so for the std library you will use ``load "std.lpsy"``

The Documentation is a work in progress and will be released as soon as possible but you are free to inspect the source code which is heavily documented

### Examples
```lisp
; Fibonacci
; For Conventions the STD library has a fibonnaci function but
; For example sake this is how to do it
(fun {fib n} {
  select
    { (== n 0) 0 }
    { (== n 1) 1 }
    { otherwise (+ (fib (- n 1)) (fib (- n 2))) }
})
```

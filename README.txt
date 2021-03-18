CS427-HW4
Benjamin Eavenson
March 2021

This archive contains source code for two programs:

mod-exp, which performs modular exponentiation.
miller-rabin, which performs the Miller-Rabin algorithm for testing primality.

To compile both programs, run `make` while in the same directory as the source code and makefile.
To compile a single program, run `make <program_name>` while in the same directory as the source code and makefile.
Running `make clean` while in the same directory as the compiled executables and makefile will delete the executables.


To use mod-exp, run it with the following command-line arguments:

./mod-exp -a <int> -b <int> -n <int>

Where the integers designated -a, -b, and -n represent a, b, and n respectively in the expression `a^b (mod n)`

The program will then calculate and print the value of a^b (mod n)


To use miller-rabin, run it with the following command-line arguments:

./miller-rabin -n <int> [-a <int> || -s <int>]

The integer designated by -n is the value to be tested for primality. 
If specified, the integer designated -a is a value greater than 1 and less than (n - 1), to be used as the base for the Miller-Rabin algorithm.
If specified, the integer designated -s is the quantity of random integers to be generated to be used as bases for the Miller-Rabin algorithm.

One of -a or -s must be supplied, but not both.

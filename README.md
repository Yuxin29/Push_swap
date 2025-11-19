# push_swap

**push_swap** is a sorting algorithm project built as part of the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations with the fewest moves possible. The program takes integers as input, validates them, and outputs a sequence of stack operations that will sort the numbers efficiently.  

## Features

- Input parsing and validation for integers  
- Handles duplicates and invalid inputs gracefully  
- Implements stack operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`  
- Optimized sorting algorithm based on stack size  
- Special strategies for small and large sets of numbers  
- Proper memory management and error handling  

## Program Rules
- Input is a list of integers separated by spaces as arguments  
- Only valid integers are accepted; duplicates cause an error  
- Operations must be printed in order to sort the stack  
- The goal is to minimize the number of operations  

Example:  
```
./push_swap 3 2 5 1 4
# The program will output a sequence of operations to sort the numbers
```

## Build & Run

1. Clone and change to the Push_swap directory
```
git clone https://github.com/Yuxin29/Push_swap.git
cd push_swap
```

2. Compile using the provided Makefile:
```
make        #Generates the executable push_swap
```
Other available make commands:
```
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile everything from scratch
```

3. Running the Program
```
./push_swap [numbers]
```
Example:
```
./push_swap 3 2 1 5 4
# The output will be a list of operations to sort the stack efficiently.
```


*This project has been created as part of the 42 curriculum by moalnajj, zabdulja.*

## Description

**Push_swap** push_swap is a C sorting project from the 42 curriculum. The program sorts a sequence of integers in ascending order using two stacks (a and b) and prints a sequence of stack operations to sort the numbers. The first supplied number is the top of stack a; stack b starts empty.

The goal is to generate a correct sequence with as few operations as practical. This implementation uses a singly linked list to represent each stack and supports four strategies: simple, medium, complex, and adaptive.

## Instructions
```bash
make        # Compiles all source files into Push_swap.a
make clean  # Removes object files (.o)
make fclean # Removes object files and Push_swap.a
make re     # Full recompilation
make bouns  # Compiles all bonus files into Push_swap.a
```


The library compiles with:
```
cc -Wall -Wextra -Werror
```

Below is how the arguments should be entered:
```
./push_swap 4 2 5 1 3
./push_swap --simple 4 2 5 1 3
./push_swap --medium 4 2 5 1 3
./push_swap --complex 4 2 5 1 3
./push_swap --adaptive 4 2 5 1 3
```

The strategy flags request the following sorting methods:

| Flag | Method | Target operation complexity |
| --- | --- | --- |
| `--simple` | Minimum extraction / selection-sort adaptation | O(n²) |
| `--medium` | Chunk-based sorting | O(n√n) |
| `--complex` | Binary LSD radix sort | O(n log n) |
| `--adaptive` | Chooses a method from the initial disorder | Depends on the Algorithm |
| No flag | Adaptive (default) | Depends on the Algorithm |

The project also implements a --bench option, intended to print statistics about the initial disorder, selected strategy, total moves, and move counts by instruction type:
```
./push_swap --complex --bench 4 2 5 1 3
```
Sorting instructions must go to standard output (stdout). Benchmark information must go to standard error (stderr) so it does not interfere with the instruction stream.
The repository includes a checker_linux binary. On a compatible Linux system, you can use
```
ARG="4 2 5 1 3"
./push_swap --complex $ARG | ./checker_linux $ARG
```
A successful sort should produce OK from the checker.

Count printed moves with:
```
ARG="4 2 5 1 3"
./push_swap --complex $ARG | wc -l
```
The source also contains an optional checker implementation (main_bouns.c and the _bouns.c operation files). Once its build target is configured, that executable reads stack operations from standard input and checks that a is sorted and b is empty.
## Resources
- [Selection sort](https://medium.com/karuna-sehgal/an-introduction-to-selection-sort-f27ae31317dc)
- [Chunk-Based size](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)
- [Radix sort](https://www.youtube.com/watch?v=XiuSW_mEn7g)
- [Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Slides For the Data structure and algorithm](https://drive.google.com/drive/folders/1wGLKg0ZWaXxGxPmOLreXgsOy1PWC86Eu)

## AI usage
AI was used to organize the README.md file and also we used it to test if there are some edge cases we missed or didn't handle, Also Ai was used to make the sure the sorting algorithms were safe in terms of time complexity for each sorting algorithm.

## Additional Sections

`Sorting algorithms`
1. Simple — Selection sort (minimum extraction)
Finds the smallest number in stack a, moves it to stack b, and repeats. The numbers are then moved back to a in sorted order.
2. Medium — Chunk sort
Divides ranked numbers into moving chunks, pushes matching numbers from a to b, then moves the largest remaining numbers back to a.
3. Complex — Binary radix sort
Sorts ranked numbers bit by bit. For each bit, it pushes numbers with a 0 bit to b, rotates numbers with a 1 bit in a, then moves everything back to a.
4. Adaptive — Disorder-based selection
Measures how unsorted the input is and chooses Simple, Medium, or Complex accordingly.
Benchmark targets
The subject defines the following performance targets for random inputs

| Input size | Minimum passing target | Good | Excellent |
| --- | ---: | ---: | ---: |
| 100 numbers | Fewer than 2,000 operations | Fewer than 1,500 | Fewer than 700 |
| 500 numbers | Fewer than 12,000 operations | Fewer than 8,000 | Fewer than 5,500 |


`Stack operations`
| Operation | Effect |
| --- | --- |
| `sa` | Swap the top two elements of stack `a` |
| `sb` | Swap the top two elements of stack `b` |
| `ss` | Perform `sa` and `sb` together |
| `pa` | Push the top element of `b` onto `a` |
| `pb` | Push the top element of `a` onto `b` |
| `ra` | Rotate `a`: move the top element to the bottom |
| `rb` | Rotate `b`: move the top element to the bottom |
| `rr` | Perform `ra` and `rb` together |
| `rra` | Reverse-rotate `a`: move the bottom element to the top |
| `rrb` | Reverse-rotate `b`: move the bottom element to the top |
| `rrr` | Perform `rra` and `rrb` together |

`Data structure`
Each stack is represented as a singly linked list of nodes containing:
- value: the original integer;
- next: a pointer to the following node;
- index: the value's rank in ascending order (only used by medium and complex algorithms).    
As example, the input 40 10 90 20 has ranks 2 0 3 1. Ranking normalizes arbitrary signed values to integers from 0 through n - 1.


`
`Team contribution`
```
moalnajj: Designed the functions to fill the stack and to check for duplicates in the inputs and handled all possible edge cases with making sure the work flow is correct and no leaks, also designed the functions that handle the operations as well as handling how the program deal with the flags and did the bench function and i helped zaid to debug his algorthims and to make it better,and finally I did the cheacker.

zabdulja: Designed the 3 sorting algorithms tested them and made sure that the performence meets the requirements of the project as defined in the en.subject.pdf, also helped moalnajj in checking the project in trems of logical errors and some constraints that the subject stated. 
```
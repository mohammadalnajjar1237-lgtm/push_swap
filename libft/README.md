*This project has been created as part of the 42 curriculum by <moalnajj>*
# Libft
## Description
This project focuses on building a library in C containg important functions the we would use in upcomming projects,they focus on memory manipulation, string manipulation, and allocating memory as well
as linked list management and more.

## Instructions
This project was compiled and tested by cc compiler with the following flags (-Wall -Wextra -Werror).
To compile the code, run make in the terminal. This will create a library called libft.a then u can use any of the functions in main.c file and compile it with the libft.a to execute.

## Resources
I relied in understanding memory manipulation on youtube videos(Codevault channel),I used AI to give me edge cases so i can test my code on them,this procsess was done nearly in every part of this project, and i often used it to understand more about the function that I'am trying to implement,just in some functions.

## Addtional sections

## Detailed description
*Character Checks & Conversions (<ctype.h>)*
ft_isalpha: Checks if a character is alphabetic (A-Z or a-z).
ft_isdigit: Checks if a character is a digit (0-9).
ft_isalnum: Checks if a character is alphanumeric (a letter or a digit).
ft_isascii: Checks if a character fits into the ASCII character set (0–127).
ft_isprint: Checks if a character is printable (including spaces).
ft_toupper: Converts a lowercase letter to uppercase.
ft_tolower: Converts an uppercase letter to lowercase.

*String Manipulation (<string.h>)*
ft_strlen: Calculates the exact length of a null-terminated string.
ft_strlcpy: Copies a string to a specific size buffer safely, ensuring null-termination.
ft_strlcat: Appends a string onto another safely up to a specified total buffer size.
ft_strchr: Locates the first occurrence of a specific character in a string.
ft_strrchr: Locates the last occurrence of a specific character in a string.
ft_strncmp: Compares two strings up to a specific number of characters.
ft_strnstr: Locates a substring inside a main string within a length limit

*Memory Management (<string.h> & <stdlib.h>)*
ft_memset: Fills a specific block of memory with a chosen constant byte.
ft_bzero: Erases data by writing zeros (\0) into a block of memory.
ft_memcpy: Copies a block of data from a source address to a destination address.
ft_memmove: Safely copies data between memory blocks, handles overlapping zones seamlessly.
ft_memchr: Searches for a specific byte within a given memory block.
ft_memcmp: Compares two distinct memory areas byte-by-byte.
ft_calloc: Allocates zeroed-out heap memory for an array of elements.
ft_strdup: Duplicates an existing string into freshly allocated memory.

*Data Conversion (<stdlib.h>)*
ft_atoi: Converts a numeric string into an equivalent integer value.

*Advanced String Utilities*
ft_substr: Extracts a smaller substring from a primary string starting from a specified index.
ft_strjoin: Concatenates two strings together into a brand-new allocated string.
ft_strtrim: Trims specific leading and trailing characters out of a string.
ft_split: Splits a single string into a 2D array of strings using a delimiter character.
ft_itoa: Converts an integer number into its equivalent string representation.
ft_strmapi: Creates a new string by modifying every character of an input string via a mapping function pointer.
ft_striteri: Mutates a string in place by passing its indices and characters directly into a function pointer.

*File Descriptor Outputs (Printing)*
ft_putchar_fd: Outputs a single character to a specified file descriptor (e.g., standard output, error).
ft_putstr_fd: Outputs an entire string to a specified file descriptor.
ft_putendl_fd: Outputs a string to a file descriptor, followed immediately by a newline character.
ft_putnbr_fd: Outputs a signed integer value directly to a specified file descrip

*Linked List Manipulation*
ft_lstnew: Allocates and initializes a brand-new individual node element.
ft_lstadd_front: Prepends an existing node directly to the beginning of a list.
ft_lstsize: Traverses a list to count its total number of nodes.
ft_lstlast: Traverses to find and return the absolute last node of a list.
ft_lstadd_back: Appends a node directly onto the very end of a list.
ft_lstdelone: Deletes a targeted node and frees its internal content via a custom function.
ft_lstclear: Clears, deletes, and completely frees an entire list from a given node onward.
ft_lstiter: Iterates through a list, executing a specific function pointer on every node's content.
ft_lstmap: Transforms a list into a brand-new list by running each node's content through a function pointer.

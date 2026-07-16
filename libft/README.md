*This project has been created as part of the 42 curriculum by ssokhats*

# Description

Libft is a foundational project in the 42 curriculum. The goal of this project is to code a C library consolidating numerous general-purpose functions that will be heavily relied upon in future programs. By reimplementing standard C library (`libc`) functions and creating additional utilities for string manipulation, memory management, and linked lists, this project builds a deep understanding of standard algorithms and memory allocation in C.

# Instructions

The project includes a `Makefile` that complies with the required standards. It compiles the source `.c` files into a static library `libft.a` using `cc` with the flags `-Wall -Wextra -Werror`.

To compile the library, simply run:
```bash
make
```
Available make rules:

`make` or `make all`: Compiles the library `libft.a`.

`make clean`: Removes all generated object (`.o`) files.

`make fclean`: Removes object files and the `libft.a` library.

`make re`: Performs a `fclean` followed by an `all`.

## Usage

To use this library in your projects, include the header file in your C files:
```C
#include "libft.h"
```

Then compile your program linking the library:
```bash
cc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program_name
```

# Detailed Description of Functions

## Part 1: Libc Functions

These functions are reimplementations of the standard C library functions. They have the same prototypes and behaviors as the originals, prefixed with ft_.

| Function name | Function description|
|:--------------|:--------------------|
| ft_isalpha	| Checks for an alphabetic character.|
| ft_isdigit	| Checks for a digit (0 through 9).  |
| ft_isalnum	| Checks for an alphanumeric character.|
| ft_isascii	| Checks whether c is a 7-bit unsigned char value that fits into the ASCII character set.|
| ft_isprint	| Checks for any printable character including space.|
| ft_strlen		| Calculates the length of the string s. |
| ft_memset		| Fills the first n bytes of the memory area pointed to by s with the constant byte c.|
| ft_bzero		| Erases the data in the n bytes of the memory starting at the location pointed to by s.|
| ft_memcpy		| Copies n bytes from memory area src to memory area dest.|
| ft_memmove	| Copies n bytes from memory area src to memory area dest, handling overlapping memory blocks.|
| ft_strlcpy	| Size-bounded string copying.|
| ft_strlcat	| Size-bounded string concatenation.|
| ft_toupper	| Converts a lowercase letter to uppercase.|
| ft_tolower	| Converts an uppercase letter to lowercase.|
| ft_strchr		| Returns a pointer to the first occurrence of the character c in the string s.|
| ft_strrchr	| Returns a pointer to the last occurrence of the character c in the string s.|
| ft_strncmp	| Compares the two strings s1 and s2 up to n bytes.|
| ft_memchr		| Scans the initial n bytes of the memory area pointed to by s for the first instance of c.|
| ft_memcmp		| Compares memory areas s1 and s2 up to n bytes.|
| ft_strnstr	| Locates the first occurrence of the null-terminated string big in the string little, where not more than len characters are searched.|
| ft_atoi		| Converts the initial portion of the string pointed to by nptr to int.|
| ft_calloc		| Allocates memory for an array of nmemb elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero.|
| ft_strdup		| Returns a pointer to a new string which is a duplicate of the string s. Memory is allocated with malloc.|

## Part 2: Additional Functions

These are utility functions that are either not included in the libc, or exist in a different form.

| Function name	| Function description|
|:--------------|:--------------------|
| ft_substr		| Allocates and returns a substring from the string 's'. The substring begins at index 'start' and is of maximum size 'len'.|
| ft_strjoin	| Allocates and returns a new string, which is the result of the concatenation of 's1' and 's2'.|
| ft_strtrim	| Allocates and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string.|
| ft_split		| Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter.|
| ft_itoa		| Allocates and returns a string representing the integer received as an argument.|
| ft_strmapi	| Applies the function 'f' to each character of the string 's', and passing its index as first argument to create a new string resulting from successive applications of 'f'.|
| ft_striteri	| Applies the function 'f' on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to 'f' to be modified if necessary.|
| ft_putchar_fd	| Outputs the character 'c' to the given file descriptor.|
| ft_putstr_fd	| Outputs the string 's' to the given file descriptor.|
| ft_putendl_fd	| Outputs the string 's' to the given file descriptor followed by a newline.|
| ft_putnbr_fd	| Outputs the integer 'n' to the given file descriptor.|



## Part 3: Linked List Functions

| Function name		| Function description|
|:------------------|:--------------------|
| ft_lstnew			| Allocates and returns a new node. The member variable 'content' is initialized with the value of the parameter 'content'.|
| ft_lstadd_front	| Adds the node 'new' at the beginning of the list.|
| ft_lstsize		| Counts the number of nodes in a list.|
| ft_lstlast		| Returns the last node of the list.|
| ft_lstadd_back	| Adds the node 'new' at the end of the list.|
| ft_lstdelone		| Takes as a parameter a node and frees the memory of the node’s content using the function 'del' given as a parameter and free the node.|
| ft_lstclear		| Deletes and frees the given node and every successor of that node, using the function 'del' and free(3).|
| ft_lstiter		| Iterates the list 'lst' and applies the function 'f' on the content of each node.|
| ft_lstmap			| Iterates the list 'lst' and applies the function 'f' on the content of each node. Creates a new list resulting of the successive applications of the function 'f'.|

# Resources

Manual, students advices and [libftTester](https://github.com/Tripouille/libftTester) - for tests.

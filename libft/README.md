
*This project has been created as part of the 42 curriculum by rzenteno.*
# libft



## Description

**libft** is a comprehensive C library containing a collection of utility functions that replicate and extend the functionality of the standard C library (libc). This project serves as the foundation for future 42 projects and is designed to deepen understanding of fundamental C programming concepts including memory management, string manipulation, and data structures.

The library is organized into three main components:
- **Part 1**: Reimplementation of essential libc functions
- **Part 2**: Additional utility functions for string and memory operations
- **Part 3**: Linked list manipulation functions

## Instructions

### Compilation

To compile the library:

```bash
make
```

This will create `libft.a` at the root of the project.

Available make rules:
- `make` or `make all`: Compiles the library
- `make clean`: Removes all object files
- `make fclean`: Removes object files and the library
- `make re`: Recompiles the entire library

### Usage

To use libft in your projects:

1. Copy `libft.a` and `libft.h` to your project directory
2. Include the header in your source files:
   ```c
   #include "libft.h"
   ```
3. Compile with the library:
   ```bash
   cc -Wall -Wextra -Werror my_file.c libft.a -o my_program
   ```

## Library Overview

### Part 1: Libc Functions

Character classification and type checking functions that return 1 if true, 0 if false:
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`

String functions:
- `ft_strlen`: Calculate string length
- `ft_strchr`, `ft_strrchr`: Locate characters in a string
- `ft_strncmp`: Compare strings (n characters)
- `ft_strnstr`: Locate substring within a string
- `ft_strlcpy`, `ft_strlcat`: Safe string copying and concatenation

Memory functions:
- `ft_memset`: Fill memory with a constant byte
- `ft_bzero`: Clear memory (set to zero)
- `ft_memcpy`, `ft_memmove`: Copy memory blocks
- `ft_memchr`: Locate byte in memory
- `ft_memcmp`: Compare memory blocks
- `ft_calloc`: Allocate and zero-initialize memory
- `ft_strdup`: Duplicate a string

Conversion functions:
- `ft_atoi`: Convert string to integer

### Part 2: Additional Functions

String manipulation:
- `ft_substr`: Extract substring from a string
- `ft_strjoin`: Concatenate two strings
- `ft_strtrim`: Remove characters from beginning and end of string
- `ft_split`: Split string by delimiter into array
- `ft_itoa`: Convert integer to string representation
- `ft_strmapi`: Apply function to each character and create new string
- `ft_striteri`: Apply function to each character (with index)

File descriptor output (formatted print functions):
- `ft_putchar_fd`: Output single character to file descriptor
- `ft_putstr_fd`: Output string to file descriptor
- `ft_putendl_fd`: Output string with newline to file descriptor
- `ft_putnbr_fd`: Output integer to file descriptor

### Part 3: Linked List Functions

All functions operate on the `t_list` structure:
```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

Basic operations:
- `ft_lstnew`: Create a new node
- `ft_lstadd_front`: Add node at beginning of list
- `ft_lstadd_back`: Add node at end of list
- `ft_lstsize`: Count nodes in list
- `ft_lstlast`: Get last node in list

Manipulation:
- `ft_lstdelone`: Delete single node
- `ft_lstclear`: Delete entire list
- `ft_lstiter`: Apply function to each node's content
- `ft_lstmap`: Apply function to each node and create new list

## Compilation Flags

All code is compiled with the required flags:
- `-Wall`: Enable all warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors

## Technical Notes

- The library uses `malloc` and `free` for dynamic memory management
- All memory allocations are properly freed to prevent memory leaks
- No global variables are used (as per 42 Norm requirements)
- Helper functions are declared as `static` to limit scope
- The library adheres to the 42 Coding Norm

## Resources

### C Standard Library Documentation
- [man pages online](https://linux.die.net/man/) - System call and library documentation
- [cppreference C reference](https://en.cppreference.com/w/c) - Comprehensive C reference
- [C99 Standard](https://www.open-std.org/jtc1/sc22/wg14/) - Official C language standard

### Linked Lists & Data Structures
- [GeeksforGeeks: Linked Lists](https://www.geeksforgeeks.org/linked-list-set-1-introduction/) - Comprehensive linked list tutorials
- [Visualgo](https://visualgo.net/en) - Data structure visualizations

### Memory Management in C
- [Dynamic Memory](https://www.cprogramming.com/tutorial/memory_management.html) - malloc, free, and memory management best practices
- [Memory Leaks](https://valgrind.org/) - Valgrind tool for detecting memory issues

### 42 School
- [42 Norm](https://github.com/42School/42cursus-libft) - Official norm reference

## AI Usage

During the development of this project, AI assistance was utilized in the following areas:

**Where AI was used:**
- Clarifying function specifications and man page interpretations for tricky functions like `ft_strlcpy`, `strlcat`, and `ft_split`
- Debugging edge cases (empty strings, NULL pointers, buffer overflow scenarios)
- Understanding linked list pointer manipulation concepts
- Memory management validation and leak prevention strategies

**Where AI was NOT used:**
- Implementation of core logic (manually coded all functions)
- Problem-solving approach and algorithm design
- Testing and validation of correctness

The AI served as a reference and clarification tool rather than a code-generation tool, allowing for deeper understanding through independent implementation.

---

*Last updated: May 2026*

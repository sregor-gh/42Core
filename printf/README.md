*This project has been created as part of the 42 curriculum by rzenteno.*

# ft_printf

A reimplementation of the standard C `printf` function, developed as an educational project for the 42 School curriculum.

## 📋 Description

`ft_printf` is a library that reproduces the behavior of the standard C `printf` function, allowing you to print text with different format specifiers. This project emphasizes understanding:

- **Variadic Functions**: Using `stdarg.h` to handle variable arguments
- **Data Manipulation**: Conversion and formatting of different data types
- **Memory Management**: Safe handling of pointers and strings
- **Recursion**: Number decomposition and numeric conversions
- **Output Management**: Controlled writing through `write()`

## ⚙️ Supported Format Specifiers

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string of characters |
| `%p` | Prints a pointer in hexadecimal format (0x...) |
| `%d` | Prints a decimal number (base 10) |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned number (base 10) |
| `%x` | Prints a number in hexadecimal (base 16) lowercase |
| `%X` | Prints a number in hexadecimal (base 16) uppercase |
| `%%` | Prints a percent sign (%) |

## 🏗️ Project Structure

```
ft_printf.h       - Header file with function prototypes
ft_printf.c       - Main ft_printf function and specifier dispatcher
utils.c           - Helper functions for conversion and output
Makefile          - Build script
```

### Main Functions

- **`ft_printf()`**: Main function that parses the format and manages variadic arguments
- **`ft_putchar()`**: Writes a character to stdout
- **`ft_putstr()`**: Writes a complete string to stdout
- **`ft_putnbr()`**: Converts an integer to string and prints it (recursively)
- **`ft_unsigned()`**: Handles unsigned numbers
- **`ft_hex()`**: Converts numbers to hexadecimal representation

## 🔧 Compilation and Usage

### Build the library

```bash
make
```

Generates `libftprintf.a`, a static library ready to be linked.

### Compile and link in your project

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, your number is: %d\n", "world", 42);
    return (0);
}
```

Compile:
```bash
gcc -Wall -Wextra -Werror -o program program.c libftprintf.a
```

### Clean compiled files

```bash
make clean    # Removes .o files
make fclean   # Removes .o files and the library
make re       # Recompiles from scratch
```

## 📚 Key Concepts Implemented

### 1. Variadic Functions
The function uses `va_list`, `va_start()`, and `va_arg()` to access arguments unknown at compile time, allowing passing an arbitrary number of parameters.

### 2. Format Parsing
The parser traverses the format string character by character, detecting specifiers (`%x`) and dispatching to specialized functions.

### 3. Numeric Conversion
Integer numbers are converted to their base 10 or 16 representations using recursion and modulo operations.

### 4. Pointer Handling
Implements the ability to print memory addresses in hexadecimal format, with special treatment for the NULL pointer.

## 🤖 AI Usage in Development

### Consolidation of Essential Concepts

AI served as a fundamental educational tool to break down complex ideas:

- **Variadic Functions**: AI explained how `va_list` and its macros work internally, helping understand why `va_arg()` needs to know the data type
- **Recursion in Numeric Conversion**: Used to visualize the flow of calls when decomposing numbers and how the stack manages digit accumulation
- **Hexadecimal and Number Bases**: Facilitated understanding of modulo and division operations to extract digits in different bases
- **Format Buffer Management**: Helped clarify why a moving pointer is needed in the format string and how the character count is tracked

### Iterative Guidance During Implementation

- **Edge Case Identification**: AI suggested critical validations (such as NULL in strings, null pointers, negative numbers)
- **Code Structure**: Guided the separation of responsibilities between the main function and helper functions
- **Conceptual Debugging**: When unexpected behaviors arose, AI helped trace the logic without providing direct solutions, promoting learning
- **Approach Validation**: Confirmed that using recursion for `ft_putnbr()` is a valid pattern in this context, though alternatives exist

### Reinforcement of Best Practices

AI reinforced 42 School principles:
- Compact and focused functions
- Correct use of pointers
- Safe memory handling
- Readable code without unnecessary abstractions

## 📝 Notes

- The project complies with **Norminette** (maximum 25 lines per function)
- Does not use external functions beyond the essentials (`write()`, `stdarg.h`)
- Designed as an educational exercise in the 42 curriculum

## 👤 Author

**rzenteno** - 42 School (2026)

---

*This project was developed as part of the 42 School curriculum, emphasizing a deep understanding of fundamental C concepts and the ability to reimplement standard functions from scratch.*

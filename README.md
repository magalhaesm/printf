# ft_printf

![42 Badge](https://img.shields.io/badge/42-São_Paulo-87CEEB)
![License](https://img.shields.io/badge/license-GNU_GPL_v3-green)

> Because ft_putnbr() and ft_putstr() aren't enough

A reimplementation of the printf function from the C standard library as part of the 42 school curriculum.

This project is part of the Common Core curriculum at 42 School. The goal is to recreate the functionality of the standard C library function `printf()` to deepen understanding of variadic functions, string parsing, and formatted output in C.

## Table of Contents

- [Overview](#overview)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Supported Flags](#supported-flags)
- [How to Use](#how-to-use)
- [Implementation Details](#implementation-details)
- [Examples](#examples)
- [License](#license)

## Overview

This project involves coding a library that contains a customized version of the `printf()` function, called `ft_printf()`. The function is designed to mimic the original `printf()` function but with a limited set of format specifiers and capabilities.

The `ft_printf()` function formats and prints its arguments, following format specifier strings that start with `%` to indicate that formatting will take place.

As specified in the 42 project brief, this implementation:
- Does not implement the buffer management of the original printf()
- Supports a specific set of conversions: cspdiuxX%
- Provides flag handling for advanced formatting

## Supported Format Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a void pointer in hexadecimal format |
| `%d` | Prints a decimal number (base 10) |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal number (base 10) |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a percent sign |

## Supported Flags

The library also handles various flags to modify how values are printed:

| Flag | Description |
|------|-------------|
| `-` | Left-justify within the given field width |
| `0` | Left-pads the number with zeroes instead of spaces when padding is specified |
| `.` | Precision that indicates minimum number of digits to be printed |
| `+` | Forces to precede the result with a plus or minus sign |
| ` ` | (Space) If no sign is going to be written, a blank space is inserted before the value |
| `#` | Alternate form - adds prefix 0x or 0X for hexadecimal values |
| Width | Minimum number of characters to output |

## How to Use

### Compilation

```bash
git clone https://github.com/magalhaesm/printf.git
cd ft_printf
make
```

This will generate a library file `libftprintf.a` that you can link to your C projects.

### Integration

When compiling your projects, link with the `ft_printf` library:

```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf -I include/
```

### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    return (0);
}
```

## Implementation Details

The implementation is structured into several components:

- **Parser**: Analyzes the format string and interprets format specifiers
- **Printer**: Handles the output of formatted data
- **Type-specific handlers**: Separate functions for each format specifier

Unlike the original `printf()`, this implementation does not use buffer management, making it more straightforward but potentially less efficient for multiple outputs.

## Examples

```c
// Basic string and character
ft_printf("Character: %c\n", 'A');
ft_printf("String: %s\n", "Hello, 42!");

// Numbers in different formats
ft_printf("Decimal: %d\n", 42);
ft_printf("Hexadecimal (lowercase): %x\n", 42);
ft_printf("Hexadecimal (uppercase): %X\n", 42);

// Pointers
int num = 42;
ft_printf("Pointer: %p\n", &num);

// Using flags
ft_printf("Zero-padded: %05d\n", 42);
ft_printf("Left-justified: %-10s\n", "Left");
ft_printf("Precision: %.3d\n", 42);
ft_printf("With sign: %+d\n", 42);
ft_printf("With space: % d\n", 42);
ft_printf("With alternate form: %#x\n", 42);
```

## License

This project is licensed under the GNU General Public License v3 - see the LICENSE file for details.

---

© 2022 mdias-ma - This project is released under the GNU GPL v3 license.

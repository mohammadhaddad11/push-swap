*This activity has been created as part of the 42 curriculum by mhaddad.*

# ft_printf

## Description
This project recreates the basic behavior of the C standard library `printf` function.  
The goal is to understand formatted output and variadic functions in C.

## Instructions

### Compilation
```bash
make
```

### Usage
Include the header in your project:
```bash
#include "ft_printf.h"
```
Compile with:
```bash
gcc main.c libftprintf.a
```
## Supported conversions

| Specifier | Description                  |
|----------|------------------------------|
| `%c`     | Character                    |
| `%s`     | String                       |
| `%p`     | Pointer                      |
| `%d`     | Signed decimal integer       |
| `%i`     | Signed decimal integer       |
| `%u`     | Unsigned decimal integer     |
| `%x`     | Hexadecimal (lowercase)      |
| `%X`     | Hexadecimal (uppercase)      |
| `%%`     | Percent sign                 |
## Algorithm and Data Structure
The ft_printf function parses the format string character by character.

Normal characters are printed directly.

When % is encountered, the following character determines the conversion type.

Variable arguments are handled using va_list, va_start, va_arg, and va_end.

The function parses the format string character by character.
When % is found, the corresponding conversion is handled using va_list.

Each format is implemented in a separate helper function.
No complex data structures are used
## Resources
man printf

man stdarg

GNU C Library documentation

42 intra resources and subject PDF

### AI Usage
AI tools were used only for:

Clarifying concepts related to va_list

Understanding edge cases of the original printf

All the code logic, structure, and implementation were written and adapted manually.

Notes

This project helped me better understand:

Variadic functions

Memory-safe string handling

Code organization in C

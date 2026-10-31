*42 curriculum utility · mhaddad*

# ft_dprintf — descriptor-aware formatting

This dependency formats values into text on a caller-selected file descriptor.
Push_swap uses it to write benchmark diagnostics to **stderr**, while its stack
operations continue writing a replayable instruction stream to **stdout**.
Choosing the output channel is the practical reason for this formatter variant.

## Build and call

Requirements: a C compiler, Make, and `ar`. From this directory:

```sh
make
```

The archive keeps its historical name, `libftprintf.a`. Include
[`ft_dprintf.h`](ft_dprintf.h) and link the archive after the client objects.
The parent Makefile performs this automatically. `clean`, `fclean`, and `re`
are also available.

```c
#include "ft_dprintf.h"

int main(void)
{
    ft_dprintf(2, "operations: %u\n", 42u);
    return 0;
}
```

Save that client as `/tmp/dprintf-demo.c`, then compile from this directory:

```sh
cc -Wall -Wextra -Werror -I. /tmp/dprintf-demo.c libftprintf.a -o /tmp/dprintf-demo
/tmp/dprintf-demo 2> /tmp/dprintf-output.txt
```

`/tmp/dprintf-output.txt` contains `operations: 42` followed by newline;
the call itself sends no output to stdout.

## How a formatted message reaches the descriptor

[`ft_dprintf(int fd, const char *format, ...)`](ft_dprintf.c) initializes a
`va_list` and walks the format string. Literal characters go to
`ft_print_char(fd, c)`. At `%`, it dispatches the next character through
`ft_formats(fd, &args, conversion)`, which retrieves the next argument using
`va_arg`. Passing the address of the list allows the dispatcher to advance
the caller's variadic state.

The destination is passed through **every helper**, ending in `write(fd, ...)`.
Decimal and hexadecimal routines recursively emit high-order digits before
the last digit. Strings are emitted a byte at a time. No heap-allocated output
buffer is built.

| Conversion | Behavior |
| --- | --- |
| `%c`, `%s` | Character/string; NULL strings produce `(null)` |
| `%d`, `%i`, `%u` | Signed or unsigned decimal |
| `%x`, `%X` | Lowercase/uppercase hexadecimal |
| `%p` | `0x` hexadecimal pointer representation; zero produces `(nil)` |
| `%%` | Literal percent, consuming no argument |

The return is an accumulated helper count on normal output paths. It is not
a reliable libc-style error contract: string writes ignore per-byte failures,
and failures in other helpers are added rather than consistently propagated.

## Integration and limits

The public entry point and helper signatures differ from standalone ft_printf,
which always writes to stdout. Replacing one directory with the other can
break compilation or route diagnostics into the sorting stream.

Width, precision, flags, length modifiers, and floating-point conversions are
not implemented. Unknown conversions emit nothing; NULL formats and a lone
trailing `%` are not safely handled. `%p` retrieves `unsigned long`, so the
pointer behavior depends on the platform ABI.

The dependency build and parent benchmark channel separation were checked.
This is a compact output layer for the project, not a fully conforming libc
`dprintf` implementation.

## Resources

- Manual pages: `dprintf(3)`, `printf(3)`, `stdarg(3)`, `write(2)`
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/html_node/)
- 42 intra resources and project subject recorded in the original README

## AI Usage

The original disclosure records AI explanations of `va_list` and libc
`dprintf` edge cases, while attributing implementation work to the author.
AI assisted this documentation and example review; no formatter source was
changed for the README.

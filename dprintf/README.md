*42 curriculum utility · mhaddad*

# ft_dprintf (push_swap dependency)

A small variadic formatter that writes to a chosen file descriptor. `push_swap` uses it for diagnostic and benchmark output without mixing that output into its instruction stream.

## Instructions

Requires a C compiler, Make, and `ar`. From this directory:

```sh
make
```

The Makefile produces `libftprintf.a`. Include `ft_dprintf.h` when using the library from C code, and link the archive after your object files. The entry point is `ft_dprintf(int fd, const char *format, ...)`.

## Implementation

The formatter scans the format string and dispatches supported conversions using `va_list`, `va_start`, `va_arg`, and `va_end`. Numeric values are converted by recursive helper functions; output is written to the requested descriptor.

Supported specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.

This is a focused utility for the parent project, not a complete replacement for every libc formatting feature. Formatting flags, width, and precision are absent; write failures are not consistently propagated. Its entry point and helper signatures differ from the standalone `ft_printf` version.

## Resources

- Manual pages: `dprintf(3)`, `printf(3)`, `stdarg(3)`, `write(2)`
- [GNU C Library documentation](https://www.gnu.org/software/libc/manual/html_node/)
- 42 intra resources and the project subject, as recorded in the original README

## AI Usage

Earlier documentation records AI help with `va_list` concepts and libc `dprintf` edge cases, while attributing the implementation to manual work. This refresh used AI-assisted documentation review; the formatter implementation was not changed.

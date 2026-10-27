*42 curriculum formatter dependency by mhaddad.*

# ft_dprintf

Descriptor-aware formatting used by push_swap to send benchmark diagnostics to
stderr while keeping the sorting instruction stream on stdout.

## Instructions

The parent Makefile builds this dependency automatically. Running `make` here
creates **`libftprintf.a`**; the archive retains its historical name. Include
`ft_dprintf.h` and link the archive after the calling object files.

```c
ft_dprintf(2, "operations: %u\n", 42u);
```

## Technical Implementation

`ft_dprintf(int fd, const char *format, ...)` scans the format and dispatches
`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, and `%` conversions. Helpers receive the
destination descriptor; integer conversion is recursive and output is
unbuffered. This is not a full formatting-flags/width/precision implementation,
and write failures are not consistently propagated.

Do not substitute the standalone `ft_printf` directory: its entry point and
helper signatures differ. The parent benchmark checks verified output-channel
separation, not complete formatter equivalence to libc.

## Resources and AI Usage

See `stdarg(3)`, `write(2)`, and the [parent documentation](../README.md).
AI assisted this dependency's documentation review; the implementation was
preserved.

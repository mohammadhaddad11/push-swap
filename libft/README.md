*42 curriculum utilities · mhaddad*

# libft (push_swap dependency)

This directory contains the C utility functions compiled specifically for `push_swap`. It is **not** a Git submodule and should be kept with the main project.

## Description

The library provides character checks, memory/string operations, allocations, file-descriptor helpers, and singly linked-list utilities through `libft.h`. This copy includes project-specific adaptations, so it should not be automatically overwritten with another `libft` version.

## Instructions

Requires a C compiler, Make, and `ar`. From this directory:

```sh
make
make clean
make fclean
```

`make` builds `libft.a`, including list functions. Running `make` from the parent `push-swap/` directory builds this dependency automatically.

## Design Notes

Functions prefixed with `ft_` implement commonly used C operations. Allocating helpers transfer ownership to their callers; callers are responsible for freeing returned memory. For `ft_split`, free each token and then the pointer array. Linked-list functions use callbacks where content cleanup is needed.

Unlike standalone libft, **`ft_atoi` returns `long`** in this copy. The parent uses it to check the `int` range before narrowing, but very long digit strings can still overflow the accumulator.

The parent project contains the sorting implementation and its own [README](../README.md).

## Resources

- C/POSIX manual pages: `malloc(3)`, `calloc(3)`, `memcpy(3)`, `memmove(3)`, `strdup(3)`, `strlen(3)`, `write(2)`
- [Makefile Tutorial](https://makefiletutorial.com/#why-do-makefiles-exist)
- [C structs and code organization](https://www.w3schools.com/c/c_structs.php)
- Linked-list visualization tutorials, as recorded in the original learning resources
- [libftTester](https://github.com/Tripouille/libftTester), an optional external tester; not rerun for this refresh
- [42 School context](https://en.wikipedia.org/wiki/42_(school))

## AI Usage

The earlier dependency README records AI support for documentation, explanations, style refactoring, and debugging/review. This refresh used AI-assisted documentation review; the existing dependency source remains unchanged.

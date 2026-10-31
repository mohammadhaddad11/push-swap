*42 curriculum utilities · mhaddad*

# libft — the push_swap utility layer

This bundled static library supplies operations that push_swap needs before
it can sort: split argument strings, recognize digits, convert numbers, allocate
and initialize memory, and clean up temporary values. It also retains the
general-purpose character, string, descriptor-output, and singly linked-list
functions from the library project.

It is built alongside push_swap because its interface includes a project-specific
integer conversion. It is an ordinary source directory, not a Git submodule.

## Build and integrate

Requirements: a C compiler, Make, and `ar`. From this directory:

```sh
make
```

This creates `libft.a`; the [parent Makefile](../Makefile) invokes this build
automatically and links the archive after its object files. `clean`, `fclean`,
and `re` remove objects, remove the archive, and rebuild respectively. Linked-list
functions are included in the normal build, without a separate bonus target.

Clients use [`libft.h`](libft.h), but should not substitute the standalone
library header without checking the conversion signature below.

## The important parsing difference: `long ft_atoi`

Here [`ft_atoi`](ft_atoi.c) returns `long`, while standalone libft returns `int`.
It skips leading C whitespace, handles one sign, and accumulates decimal digits
until a nondigit. It does not itself reject trailing text or enforce the
push_swap integer range.

The parent combines helpers into a stricter pipeline:

```text
"3 -2 7" → ft_split(..., ' ') → digit/sign validation
         → long conversion → int range check → duplicate check → stack nodes
```

Keeping conversion wider than the destination permits rejecting ordinary
out-of-`int` values before narrowing. This is still not arbitrary-length-safe
conversion: enough digits can overflow `long` before the parent can inspect
the result. The separate token validator is essential because `ft_atoi` alone
does not provide a full success/error result.

## Ownership during parsing

[`ft_split`](ft_split.c) counts delimiter-separated words, allocates a
NULL-terminated pointer array, and allocates each word using `ft_substr`.
Repeated spaces do not create empty words. On partial allocation failure,
previous words and the array are released.

The caller owns the successful result. In push_swap, the parent finishes
creating nodes, then frees **each word and the array**; the nodes contain
converted integer values, not borrowed addresses in those word allocations.

Other allocating helpers such as `ft_strdup`, `ft_strjoin`, and `ft_strtrim`
also transfer a new allocation to the caller. This `ft_strjoin` leaves both
input strings owned by their original callers; it is different from the
ownership-consuming helper in get_next_line.

## Lists, memory, and output helpers

Raw memory routines operate on byte counts. `ft_memmove` chooses copy direction
for overlap; `ft_calloc` checks the allocation multiplication and zeroes memory.
String helpers use NUL termination and generally assume valid input buffers.

The generic `t_list` stores `void *content` and `next`. It is **not** push_swap's
`t_node`, which also holds ranks and previous links. List deletion uses a caller
callback to free contents separately from nodes; list mapping allocates new
nodes and cleans a partial result if node construction fails. Repeated append
walks can make mapping quadratic.

The descriptor-output helpers accept a destination FD but return no detailed
I/O status. The parent uses the separate formatter for structured benchmark
messages.

## Scope and limitations

The dependency build and the parent's representative sorting runs passed.
That is not complete validation of every retained library routine. The
unterminated-destination issue in `ft_strlcat` and terminating-match issue in
`ft_strnstr` remain in these copies; the parent does not use them as a general
proof of memory safety. Match each helper's ownership and valid-input contract
when reusing it elsewhere.

## Resources

- C/POSIX manuals: `malloc(3)`, `calloc(3)`, `memcpy(3)`, `memmove(3)`, `strdup(3)`, `strlen(3)`, `write(2)`
- [Makefile Tutorial](https://makefiletutorial.com/#why-do-makefiles-exist)
- [C structs and organization](https://www.w3schools.com/c/c_structs.php)
- Linked-list visualization tutorials recorded in the original learning resources
- [libftTester](https://github.com/Tripouille/libftTester), optional external tests
- [42 School context](https://en.wikipedia.org/wiki/42_(school))

## AI Usage

The earlier disclosure records AI support for explanations, documentation,
style refactoring, and debugging/review. AI assisted this README and verification
of the parent workflow. The dependency implementation is retained.

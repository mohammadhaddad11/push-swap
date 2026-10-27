*42 curriculum dependency by mhaddad.*

# libft — push_swap variant

This bundled C utility library is built by the parent Makefile and linked into
`push_swap`. It contains memory/string helpers, descriptor output, allocating
string operations, and singly linked lists. Run `make` here to build `libft.a`;
`clean`, `fclean`, and `re` are available. List functions are included normally.

## Interface and ownership

Unlike the standalone library, **`ft_atoi` returns `long`** in this version.
push_swap uses that result to reject values outside the `int` range before
narrowing. Preserve this header/implementation pair. Very long digit strings
can still overflow `long`, as recorded in the [project verification](../README.md#verification-and-limitations).

Allocated strings belong to the caller. Free each `ft_split` token and then its
pointer array. List content ownership is controlled by the deletion callback.
The standalone library's known string-routine limitations also apply to these
unchanged copies; only the parent program's exercised paths were verified here.

## Resources and AI Usage

Consult Linux manual pages for the corresponding memory/string interfaces and
the [parent README](../README.md) for build checks, authorship, and AI disclosure.
This dependency README was revised with AI-assisted source review; its source
was retained rather than replaced by the standalone library.

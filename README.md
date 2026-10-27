*This project was created as part of the 42 curriculum by mhaddad and aselfrie.*

# push_swap

## Description

Sort distinct signed integers using two stacks and a restricted instruction
set. The program prints instructions rather than the sorted numbers. This
implementation explores several sorting strategies, rank normalization, and
adaptive selection based on the initial inversion ratio.

## Instructions

Requirements: a C compiler, Make, and `ar`. The required library sources are
included; no submodules or external sorting dependencies are needed.

```sh
git clone git@github.com:mohammadhaddad11/push-swap.git
cd push-swap
make
./push_swap 3 2 1
./push_swap --medium "8 3 7 1 6 2 5 4"
./push_swap --bench --adaptive 8 3 7 1 6 2 5 4
python3 tests/verify.py
```

`make clean`, `make fclean`, and `make re` clean objects, remove the executable
and dependency archives, and rebuild respectively. Numeric arguments may be
individual tokens or quoted groups separated by literal spaces. Duplicates,
malformed numbers, and values outside the `int` range print `Error` to stderr.
No arguments succeeds silently. Flags without numbers are rejected. Empty
groups may be skipped when other valid numbers exist. Sorted input emits no
sorting instructions. The last recognized strategy flag wins.

### Instructions emitted

| Instruction | Meaning |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two elements of A, B, or both |
| `pa`, `pb` | Move the top element to A or B |
| `ra`, `rb`, `rr` | Move the top element to the bottom of A, B, or both |
| `rra`, `rrb`, `rrr` | Move the bottom element to the top of A, B, or both |

`--bench` sends disorder, strategy labels, totals, and operation counters to
stderr, leaving stdout available for a checker. Combined operations count once.

## Technical Implementation

Nodes are doubly linked and store the original value and a normalized rank.
Stack structures hold size, top, and tail fields. Ranking counts the smaller
values for each node, producing indexes `0..n-1`. Validation rejects duplicate
values before sorting. Error paths release the token arrays and stacks.

The bundled [`libft`](libft/README.md) deliberately uses a `long`-returning
`ft_atoi`, unlike the standalone libft interface. [`dprintf`](dprintf/README.md)
provides descriptor-aware formatting for benchmark diagnostics. Replacing either
dependency with a similarly named library can break the interface.

## Algorithms and Data Structures

| Mode | Implemented strategy |
| --- | --- |
| `--simple` | Rotate each next minimum rank into position, push it to B, tiny-sort the last three, then restore B |
| `--medium` | Push increasing rank windows of width `ceil(sqrt(n))` to B; restore maximum ranks first |
| `--complex` | Binary least-significant-bit radix sort on ranks: zero bits to B, one bits rotated through A, then restore B |
| Default / `--adaptive` | Select the strategy from the inversion ratio; inputs of at most five use the small-sort path |

For larger adaptive inputs, disorder is inverted pairs divided by all position
pairs. Below `0.20` selects selection; from `0.20` to below `0.50` selects chunks;
otherwise radix is selected. This is a heuristic, not an optimality guarantee.

Preprocessing is quadratic. Rotations traverse the linked list despite the
stored tail field. Thus the printed `O(n²)`, `O(n√n)`, and `O(n log n)` strategy
labels are not end-to-end runtime guarantees. Small adaptive runs may also
display the disorder-class label rather than their actual tiny-sort path.

## Design Decisions and Source Reconciliation

Instruction generation is separated from parsing and benchmark reporting.
Normalized nonnegative ranks let radix sorting handle negative input values
without adding sign-specific sorting logic.

The publication merge adopts the local chunk-window counting correction,
allocation-failure cleanup in `main`, adaptive routing, and contributor details.
The remote `src/algorithms/algorithms.c` already contains the same tiny-sort and
selection bodies as local `simple_sort.c`, so its established Makefile path is
retained. Its older `low_disorder_sort` helper remains available in the source
but is not selected by the current controller. The remote radix size guard is
also retained. No new sorting algorithm was introduced.

## Verification and Limitations

On Fedora, 2026-10-27, `make re` passed with `-Wall -Wextra -Werror`.
[`tests/verify.py`](tests/verify.py) passed **685 process checks**, independently
interpreting every emitted instruction. Coverage includes all permutations of
sizes 1–5 in four modes, seeded larger inputs, sorted/reversed/nearly sorted
inputs, quoted groups, integer boundaries, and input-error behavior.

One seeded sample per size produced the following operation counts. These are
reproducible observations, not averages or grading guarantees:

| Size | Adaptive | Simple | Medium | Complex |
| --- | ---: | ---: | ---: | ---: |
| 6 | 29 | 12 | 18 | 29 |
| 20 | 160 | 80 | 88 | 160 |
| 100 | 1084 | 1446 | 815 | 1084 |
| 500 | 7890 | 32388 | 7890 | 6784 |

**Known input limitation:** a Clang UBSan probe with a very long numeric token,
such as `999999999999999999999999999999999`, detects signed `long` overflow in
the bundled `ft_atoi` before the range check. Ordinary out-of-`int` bounds were
rejected in the checks; arbitrary-length numeric parsing is not overflow-safe.
The original parsing code is preserved. No full memory-leak certification or
official 42 evaluation is claimed.

## Contributors

The existing local documentation attributes main flow, parsing/validation,
disorder routing, benchmarking, and integration cleanup to **mhaddad**; sorting
strategies, stack operations, and node utilities to **aselfrie**. Source headers
and existing credits are retained.

## Resources

- [Radix sorting](https://en.wikipedia.org/wiki/Radix_sort).
- [Inversions](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)).
- [VisuAlgo](https://visualgo.net/en) for data-structure visualization.
- Documentation presentation informed by [oweidat05/push-swap-42](https://github.com/oweidat05/push-swap-42) and [AhmadNajiKam/Push_Swap](https://github.com/AhmadNajiKam/Push_Swap); their algorithms and performance claims were not imported.

## AI Usage

The existing README records AI support for documentation, clarity review, and
testing suggestions. This publication additionally used an AI assistant for
source comparison, documentation, and an independent operation-stream checker.
The sorting implementation remains the team's work; verification findings are
reported without silently repairing the original algorithms.

*This project was created as part of the 42 curriculum by mhaddad and aselfrie.*

# push_swap

`push_swap` finds a sequence of restricted stack instructions that sorts a list
of distinct integers. It does not print the sorted list: its output is a small
program that a checker could replay using stacks A and B.

The challenge is to reach ascending order in A with B empty, while keeping the
instruction count low. This implementation offers selection, chunk, and binary
radix strategies plus an adaptive path for different initial disorder levels.

## Build and run

Requirements: a C compiler, Make, and `ar`. Both dependency libraries are included.

```sh
git clone git@github.com:mohammadhaddad11/push-swap.git
cd push-swap
make
./push_swap 3 2 1
```

The last command prints:

```text
ra
sa
```

With the top shown on the left, that means:

```text
A: [3, 2, 1]  B: []
ra
A: [2, 1, 3]  B: []
sa
A: [1, 2, 3]  B: []
```

Quoted groups are accepted too: `./push_swap "3 2 1"`. Recognized strategy
options are `--simple`, `--medium`, `--complex`, and `--adaptive`; the last
recognized strategy option wins. With no strategy option, adaptive behavior is selected.
`make clean`, `make fclean`, and `make re` clean objects, remove the executable
and dependency archives, and rebuild respectively.

## What an instruction is allowed to do

| Instruction | Effect |
| --- | --- |
| `sa`, `sb` | Exchange the top two nodes of A or B |
| `ss` | Apply both swaps, emitted as one instruction |
| `pa`, `pb` | Move the top node to A or B, respectively |
| `ra`, `rb` | Move the top node to the bottom of A or B |
| `rr` | Rotate both stacks as one instruction |
| `rra`, `rrb` | Move the bottom node to the top of A or B |
| `rrr` | Reverse-rotate both as one instruction |

Sorting strategies call these operations instead of writing an already sorted
array back into the stack. The operation wrappers relink nodes, emit the name
to stdout, and increment counters; combined operations count once.

## From arguments to ranked stacks

```text
arguments → recognize flags → split/validate numbers → build A
    → measure disorder → assign ranks → choose strategy → emit operations
```

[`parse_flags`](src/utils/parse.c) identifies modes independently of their
position among arguments. The [number-building code](src/utils/push_swap_utils.c)
skips recognized flags and splits other arguments on literal spaces. Each token
must contain optional sign plus digits; conversion uses the bundled
`long`-returning `ft_atoi` before an `INT_MIN`/`INT_MAX` check. Existing nodes
are scanned to reject duplicates.

The [`t_node` representation](push_swap.h) stores an original `int value`,
normalized `index`, and next/previous links. Each stack stores size, top, and
a tail field. Sorting works primarily by traversal and relinking; rotations
still walk to the end rather than relying on a maintained constant-time tail.

[`node_index`](src/utils/node_utils.c) counts the values smaller than each
node's value. Thus `[-10, 50, 3]` becomes ranks `[0, 2, 1]`. This preserves
ordering while making the radix algorithm independent of negative signs and
the magnitudes of the input values.

An already sorted stack skips sorting. No arguments succeeds silently;
flags without numbers are rejected. Empty/space-only groups may be skipped
when other valid numeric arguments exist. Invalid tokens, duplicates, and
ordinary out-of-`int` values print `Error` to stderr and exit with failure.

## Sorting strategies in the current source

### Small inputs and selection — `--simple`

The [controller](src/push_swap.c) swaps two reversed values directly and uses
`tiny_sort` for three. The latter compares the three ranks and chooses a short
combination of swap/rotation operations.

For more values, [`selection_sort`](src/algorithms/algorithms.c) repeatedly finds
the next minimum rank, brings it to the top using a forward or reverse rotation,
and pushes it to B. Once three remain in A, it tiny-sorts them, then pushes
everything back. Minimum ranks were pushed in increasing order, so restoring
B leaves the overall result ascending.

`--simple` uses this path; default/adaptive also use small sorting for at most
five values before consulting disorder thresholds.

### Increasing rank thresholds — `--medium`

[`chunk_sort`](src/algorithms/chunk_sort.c) chooses a chunk width equal to the
smallest integer whose square reaches the input size. It begins with threshold
`width - 1`. While scanning A, it pushes a top rank at or below the threshold
to B; otherwise it rotates A. The threshold increases between scan rounds.

The scan counter counts **both pushes and rotations**, and its round length
uses the current threshold. It is not a strict “push exactly one full chunk”
loop. Once A is empty, the second phase repeatedly brings B's largest remaining
rank to the top and pushes it to A. Restoring descending ranks to the top
builds A in ascending order.

### Binary least-significant-bit sorting — `--complex`

[`radix_sort`](src/algorithms/radix_sort.c) determines the bits needed for the
largest rank. For each bit, it processes the current stack size: a zero bit
causes `pb`, a one bit causes `ra`. It restores B to A after the pass, then
advances to the next bit, stopping early if A is sorted.

Using normalized nonnegative ranks lets the same bit test handle inputs such
as `-100`, `0`, and `500` without a separate signed-number partition.

### Disorder-based choice — default / `--adaptive`

[`disorder_calc`](src/disorder.c) visits every pair of positions and counts an
inversion when the earlier value is larger. The ratio is inverted pairs over
all position pairs: sorted order is 0; reverse order is 1.

For inputs larger than five:

| Initial ratio | Selected path |
| --- | --- |
| Below `0.20` | `low_disorder_sort` |
| `0.20` to below `0.50` | Chunk sort |
| `0.50` or higher | Radix sort |

The [low-disorder pass](src/algorithms/algorithms.c) performs at most the
initial stack size in swap/rotate iterations, swapping an out-of-order top
pair, then rotating. It aligns rank zero at the top afterward. If A is still
unsorted, it switches to chunk sort rather than assuming the limited pass
was sufficient. This fallback is part of the current adaptive implementation.

## Benchmarking without corrupting the instruction stream

```sh
./push_swap --bench --adaptive 8 3 7 1 6 2 5 4 > operations.txt 2> benchmark.txt
```

[`bench`](src/bench.c) reports initial disorder, a strategy label, total
operations, and individual counters to stderr using
[`ft_dprintf`](dprintf/README.md). Stdout therefore remains replayable.

Labels such as `O(n²)` and `O(n log n)` are not verified whole-program runtime
bounds. Duplicate detection, ranking, and inversion counting already use
repeated/nested scans; rotations also traverse linked lists. Small adaptive
inputs can display a disorder-class label even though the controller used
tiny sorting. Instruction count, diagnostic label, and actual execution time
are different measurements.

## Dependencies, checks, and limitations

[`libft`](libft/README.md) supplies allocation/string/parsing helpers; its
`ft_atoi` interface differs from standalone libft. The FD-aware formatter also
has different signatures from standalone ft_printf. They are ordinary included
source directories, not submodules.

The current strict build passed, and output streams from all four modes were
independently replayed for representative small, low/medium/high-disorder, and
50-value inputs. Those checks support the examples, not optimality or complete
performance guarantees.

Very long numeric tokens can overflow the parser's `long` accumulator before
the range check. Literal-space splitting is not arbitrary-whitespace parsing,
and allocation/error handling is not an exhaustive failure-safe framework.
The program demonstrates parsing, pointer-based data structures, rank-based
sorting, algorithm selection, and separation of functional output from metrics.

## Contributors

The project credits **mhaddad** and **aselfrie**. Existing source headers and
their attribution are retained.

## Resources

- 42 project subject, campus guidelines, and evaluation guidelines
- Data structures and algorithms university coursework, recorded in the original resources
- [C reference](https://en.cppreference.com/w/c)
- [Sorting overview](https://www.youtube.com/watch?v=rbbTd-gkajw)
- [Push Swap walkthrough](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s)
- [Additional tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk)

## AI Usage

Existing documentation records assistance with README structure, clarity, and
testing/validation. AI assisted this explanation and representative output
checks. The algorithms described here are those in the current project source.

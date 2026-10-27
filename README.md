*This project was created as part of the 42 curriculum by mhaddad and aselfrie.*

# push_swap

Sort integers using two stacks and a limited instruction set. Instead of printing sorted numbers, the program prints the operations needed to sort them.

## Description

`push_swap` begins with input values on stack A and an empty stack B. Its goal is to leave A sorted and B empty while minimizing the number of instructions.

| Instructions | Action |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the top two values of A, B, or both |
| `pa`, `pb` | Move the top value to A or B, respectively |
| `ra`, `rb`, `rr` | Rotate the top value to the bottom of A, B, or both |
| `rra`, `rrb`, `rrr` | Move the bottom value to the top of A, B, or both |

## Instructions

Requirements: C compiler, Make, and `ar` for the bundled libraries.

```sh
git clone git@github.com:mohammadhaddad11/push-swap.git
cd push-swap
make
./push_swap 3 2 1
./push_swap --bench --adaptive 8 3 7 1 6 2 5 4
```

Supported options:

| Mode | Approach |
| --- | --- |
| `--simple` | Selection-based extraction and tiny sorting |
| `--medium` | Chunk-based sorting |
| `--complex` | Binary radix sorting on normalized indexes |
| `--adaptive` | Selects a strategy using the initial disorder ratio |
| `--bench` | Sends operation statistics to `stderr` |

With no mode option, adaptive selection is used. Already sorted input emits no operations. Invalid or duplicate input produces `Error` on standard error. Quoted space-separated input is also accepted. Running with no arguments succeeds silently; options without numbers are rejected.

## Algorithms and Design Decisions

**Index normalization:** values are ranked from `0` to `n - 1`, so the sorting strategies operate on relative order rather than magnitudes.

**Selection:** move small values to B, sort the small remaining set in A, then restore them.

**Chunking:** increase a rank threshold while scanning A and pushing eligible values to B, then restore larger ranks first. The current inner loop counts both pushes and rotations; it does not count only successful pushes.

**Radix:** examine ranking bits from least to most significant, pushing zeros to B and rotating ones within A.

**Adaptive:** for inputs larger than five, disorder below `0.20` selects `low_disorder_sort`; below `0.50` selects chunks; otherwise radix is used. The low-disorder pass swaps adjacent out-of-order top values while rotating, aligns rank zero, and falls back to chunk sorting if A is still unsorted. Inputs of at most five use the small-sort path. This describes the current source after the earlier sorting update was reverted; no reverted code is restored by this README refresh.

Complexity labels used by the benchmark describe the sorting strategies, not a formal end-to-end runtime bound for the whole executable. Ranking and inversion counting are quadratic, and rotations traverse lists. Adaptive selection is a heuristic, not a guarantee of optimal operation count.

## Project Structure and Limitations

- `src/`: parsing, operations, algorithms, and benchmark output
- [`libft/`](libft/README.md): the project's bundled C utility library
- [`dprintf/`](dprintf/README.md): descriptor-aware formatted output used by the program

The bundled libraries are maintained with this project because they have project-specific behavior and must not be casually replaced with the standalone `libft` or `ft_printf` repositories. The `long`-returning integer parser can overflow on extremely long numeric tokens before the `int` range check; arbitrary-length parsing is not overflow-safe.

This refresh does not restore the reverted test harness or reuse its results as verification of this source version.

## Contributors

The existing project documentation credits **mhaddad** and **aselfrie**. Their attribution and source headers are preserved.

## Resources

- 42 project subject, campus project guidelines, and evaluation guidelines
- Data structures and algorithms university coursework, as recorded in the original README
- [C programming reference](https://en.cppreference.com/w/c)
- [Sorting algorithms overview](https://www.youtube.com/watch?v=rbbTd-gkajw)
- [Push Swap walkthrough](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s)
- [Additional Push Swap tutorial](https://www.youtube.com/watch?v=wRvipSG4Mmk)

## AI Usage

Earlier documentation records assistance with README structure, clarity review, and testing/validation. This refresh used AI-assisted documentation and source review only. No algorithm, test, or build file was changed, and no historical verification result is presented as a fresh full-suite run.

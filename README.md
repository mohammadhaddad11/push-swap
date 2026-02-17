*This activity has been created as part of the 42 curriculum by mhaddad.*

# push_swap

## Description
`push_swap` sorts integers using two stacks (`a` and `b`) and a limited instruction set (`sa`, `pb`, `ra`, etc.).  
The goal is to produce a valid sorting sequence with as few operations as possible.

This implementation includes:
- Fixed strategies: `--simple`, `--medium`, `--complex`
- Adaptive strategy: `--adaptive` (or default mode when no strategy flag is provided)
- Optional benchmark output: `--bench` (printed to `stderr`)

## Instructions
### Compilation
```bash
make
```

### Run
```bash
./push_swap [--bench] [--adaptive|--simple|--medium|--complex] <numbers...>
```

Examples:
```bash
./push_swap 3 2 1
./push_swap --simple 4 2 1 3
./push_swap --medium 5 1 4 2 3
./push_swap --complex 8 3 7 1 6 2 5 4
./push_swap --bench --adaptive 8 3 7 1 6 2 5 4
```

### Behavior and errors
- If input is invalid (non-integer, overflow, duplicate), the program prints `Error` to `stderr` and exits.
- If the input is already sorted or has fewer than 2 values, no operations are printed.
- Bench mode prints disorder, selected strategy, total operations, and per-operation counters to `stderr`.

## Resources
- 42 subject and project guidelines (official campus material)
- Big-O notation basics: https://en.wikipedia.org/wiki/Big_O_notation
- Radix sort overview: https://en.wikipedia.org/wiki/Radix_sort
- Inversion count concept (disorder metric basis): https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)

### AI usage
AI assistance was used for:
- README wording and structure
- Explaining/validating complexity arguments
- Reviewing benchmark text clarity

AI was not used to generate the project architecture from scratch; implementation decisions and code integration were done manually in the project codebase.

## Algorithms and justification
This project selects among multiple strategies to balance operation count across different input patterns.

### 1) `--simple` (selection-based extraction)
Approach:
- Repeatedly rotate stack `a` to bring the next minimum index to top
- Push it to `b` with `pb`
- Sort remaining 3 values with `tiny_sort`
- Push everything back to `a` with `pa`

Why:
- Deterministic and easy to reason about
- Strong baseline for small or educational test cases

Complexity:
- Time: `O(n^2)` (repeated scans/rotations for each next minimum)
- Extra space: `O(1)` beyond stack nodes

### 2) `--medium` (chunk partitioning)
Approach:
- Compute `chunk_count ~= sqrt(n)` and chunk size from input length
- Move values from `a` to `b` in index windows (chunks)
- Rebuild `a` by repeatedly pulling the current maximum from `b`

Why:
- Reduces random movement compared with full selection-style passes
- Good middle-ground for moderate input sizes

Complexity:
- Target behavior: around `O(n * sqrt(n))` in this implementation model

### 3) `--complex` (radix on normalized indexes)
Approach:
- Normalize values to rank indexes (`0..n-1`)
- For each bit, push bit-`0` values to `b` and rotate bit-`1` in `a`
- Move all values back from `b` to `a` after each bit round

Why:
- Stable and predictable for large random sets
- Usually best scaling among included strategies

Complexity:
- Time: `O(n log n)` in this project model (`log n` bit rounds over `n` items)

### 4) Adaptive mode (`--adaptive` or default)
Approach:
- Compute disorder before sorting:
  - `disorder = inversions / total_pairs`
- Thresholds:
  - low: `< 0.20` -> near-order pass (`low_disorder_sort`), then fallback if needed
  - medium: `< 0.50` -> `chunk_sort`
  - high: `>= 0.50` -> `radix_sort`

Why:
- Inputs are not all equally difficult; one static algorithm is often suboptimal
- Early disorder estimation chooses a strategy that better fits the current permutation

Complexity:
- Selection overhead: `O(n^2)` for exact inversion-ratio calculation
- Sorting phase then follows chosen strategy (`O(n)`, `O(n*sqrt(n))`, or `O(n log n)` model in this code)

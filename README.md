*This activity has been created as part of the 42 curriculum by mhaddad, aselfrie.*

# push_swap

## Description
`push_swap` is a 42 algorithm project: sort a list of integers using two stacks (`a` and `b`) and only the allowed stack instructions.

The objective is to output a valid sequence of operations with the lowest possible number of actions.

This implementation provides:
- Fixed modes: `--simple`, `--medium`, `--complex`
- Adaptive mode: `--adaptive` (also used by default when no mode flag is provided)
- Benchmark mode: `--bench` (stats printed to `stderr`)

Allowed operations in the project:

| Code | Action |
|---|---|
| `sa`, `sb`, `ss` | swap top elements |
| `pa`, `pb` | push top element between stacks |
| `ra`, `rb`, `rr` | rotate (top to bottom) |
| `rra`, `rrb`, `rrr` | reverse rotate (bottom to top) |

## Instructions
### Compilation
```bash
make
```

### Execution
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

Input rules and behavior:
- Invalid input (non-integer token, overflow, duplicates, or no numbers) prints `Error` to `stderr` and exits.
- If input is already sorted, the program prints no operations.
- `--bench` prints initial disorder, selected strategy class, total operation count, and per-operation counters.

## Project-Specific Notes
- Stack parsing accepts quoted groups too (example: `./push_swap "3 2 1"`), because arguments are split internally before validation.
- Index normalization is done by `node_index()` before sorting logic starts.
- Mode dispatch in this codebase:
- `--simple` -> `selection_sort` (with `tiny_sort` for small cases)
- `--medium` -> `chunk_sort`
- `--complex` -> `radix_sort`
- `--adaptive` or no mode flag -> `disorder_check`
- Adaptive thresholds in this project are hardcoded as:
- `< 0.20` low disorder, `< 0.50` medium disorder, otherwise high disorder.
- Low-disorder path has a safety fallback: if not fully sorted after `low_disorder_sort`, it promotes to `chunk_sort`.
- Bench output labels are exactly:
- `Simple O(n^2)`, `Medium O(n√n)`, `Complex O(n log n)`
- `Adaptive O(n^2)`, `Adaptive O(n√n)`, `Adaptive O(n log n)`

## Resources
Classic references:
- 42 subject and campus project guidelines
- Data structures and algorithms course (university coursework)
- Sorting algorithms fundamentals: https://www.youtube.com/watch?v=rbbTd-gkajw&pp=ygUPc29ydCBhbGdvcml0aG0g
- Push swap tutorials:
	- https://www.youtube.com/watch?v=OaG81sDEpVk&t=2945s&pp=ygUMcHVzaCBzd2FwIDQy
	- https://www.youtube.com/watch?v=wRvipSG4Mmk

Assistance used for this project:
- README documentation structure and wording
- Clarity and consistency review
- Testing and validation

## Algorithms and Justification
This project uses several strategies because input disorder and size vary a lot; one static strategy is usually not optimal.

### 1. `--simple` (selection extraction + tiny sort)
Flow:
- Repeatedly bring the next smallest indexed node to top of `a`
- Push it to `b` with `pb`
- Sort the remaining 3 nodes in `a` with `tiny_sort`
- Push everything back to `a` with `pa`

Why:
- Straightforward and deterministic
- Good for small inputs and for validating correctness quickly

Complexity target:
- `O(n^2)`

### 2. `--medium` (chunk-based partitioning)
Flow:
- Use chunk range close to `sqrt(n)`
- Push values from `a` to `b` by index windows
- Rebuild `a` by pulling highest indexes first from `b`

Why:
- Reduces unnecessary rotations compared to pure selection-style passes
- Good middle ground for medium disorder / medium input sizes

Complexity target:
- Around `O(n * sqrt(n))` in this model

### 3. `--complex` (binary radix on normalized indexes)
Flow:
- Normalize values to indexes `0..n-1`
- Process bits from least significant to most significant
- For each bit: `pb` when bit is `0`, `ra` when bit is `1`
- Move all elements back from `b` to `a` after each pass

Why:
- Predictable behavior on large random inputs
- Reliable operation counts for high-disorder cases

Complexity target:
- `O(n log n)` in this implementation model

### 4. Adaptive mode (`--adaptive` or default)
Flow:
- Compute initial disorder using inversion ratio: `disorder = inversions / total_pairs`
- Route to:
- `disorder < 0.20` -> low-disorder pass (`low_disorder_sort`)
- `0.20 <= disorder < 0.50` -> chunk sort
- `disorder >= 0.50` -> radix sort
- If low-disorder pass is not enough, it promotes to chunk sort in the same run

Why:
- Matches algorithm cost to the observed input pattern
- Keeps small/near-sorted inputs cheap while preserving scalability

Complexity targets by adaptive branch:
- Low: near-linear pass in practice (`O(n)` target)
- Medium: chunk behavior (`O(n * sqrt(n))`)
- High: radix behavior (`O(n log n)`)

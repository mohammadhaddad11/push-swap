"""Check instruction streams with an independent two-list interpreter."""
import itertools
from pathlib import Path
import random
import subprocess

ROOT = Path(__file__).resolve().parents[1]
PROGRAM = ROOT / "push_swap"
MODES = ("--adaptive", "--simple", "--medium", "--complex")


def replay(values: list[int], operations: list[str]) -> None:
    a, b = list(values), []

    def swap(stack):
        if len(stack) > 1:
            stack[0], stack[1] = stack[1], stack[0]

    def rotate(stack):
        if stack:
            stack.append(stack.pop(0))

    def reverse(stack):
        if stack:
            stack.insert(0, stack.pop())

    for operation in operations:
        if operation in ("sa", "ss"):
            swap(a)
        if operation in ("sb", "ss"):
            swap(b)
        if operation == "pa" and b:
            a.insert(0, b.pop(0))
        if operation == "pb" and a:
            b.insert(0, a.pop(0))
        if operation in ("ra", "rr"):
            rotate(a)
        if operation in ("rb", "rr"):
            rotate(b)
        if operation in ("rra", "rrr"):
            reverse(a)
        if operation in ("rrb", "rrr"):
            reverse(b)
        assert operation in {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"}, operation
    assert a == sorted(values) and not b, (values, a, b)


def check(values: list[int], mode: str, quoted=False, bench=False) -> int:
    args = [" ".join(map(str, values))] if quoted else list(map(str, values))
    result = subprocess.run([str(PROGRAM), mode, *(["--bench"] if bench else []), *args], capture_output=True, text=True, timeout=30)
    assert result.returncode == 0, (mode, values, result.stderr)
    operations = result.stdout.splitlines()
    replay(values, operations)
    if not bench:
        assert result.stderr == "", result.stderr
    return len(operations)


def main():
    count = 0
    for size in range(1, 6):
        for values in itertools.permutations(range(size)):
            for mode in MODES:
                check(list(values), mode)
                count += 1
    rng = random.Random(42)
    benchmark = {}
    for size in (6, 20, 100, 500):
        values = rng.sample(range(-100000, 100000), size)
        for mode in MODES:
            benchmark[f"{size}:{mode}"] = check(values, mode, bench=True)
            count += 1
        for values in (list(range(size)), list(reversed(range(size))), [1, 0, *range(2, size)]):
            for mode in MODES:
                check(values, mode)
                count += 1
    check([2147483647, -2147483648, 0, -1], "--adaptive", quoted=True)
    count += 1
    for args in (["1", "1"], ["2147483648"], ["-2147483649"], ["+"], ["abc"], ["--adaptive"], [""]):
        result = subprocess.run([str(PROGRAM), *args], capture_output=True, text=True, timeout=3)
        assert result.returncode != 0 and result.stderr == "Error\n" and not result.stdout, (args, result)
        count += 1
    result = subprocess.run([str(PROGRAM)], capture_output=True, text=True)
    assert result.returncode == 0 and not result.stdout and not result.stderr
    count += 1
    print(f"PASS: {count} process checks; all instruction streams sort correctly")
    print("Seed-42 sample operation counts (one sample per size, not averages):")
    for key, value in benchmark.items():
        print(key, value)


if __name__ == "__main__":
    main()

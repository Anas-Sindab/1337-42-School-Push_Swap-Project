
# push_swap — two stacks, many constraints, one objective

[![1337](https://img.shields.io/badge/1337-000000?style=for-the-badge&logoColor=white)](https://www.1337.ma/)
[![UM6P](https://img.shields.io/badge/UM6P-C1392B?style=for-the-badge)](https://um6p.ma/)
[![42 Badge](https://img.shields.io/badge/push__swap-00babc?style=for-the-badge&logo=42)](https://42.fr) [![Makefile](https://img.shields.io/badge/Makefile-2C2D30?style=for-the-badge)](https://www.gnu.org/software/make/) [![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.kernel.org/) [![C](https://img.shields.io/badge/programming-00599C?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))

Short: design a program that sorts integers using two stacks and a minimal set of allowed operations, printing a sequence of operations that will sort the stack with as few moves as possible.

— Why this project matters

- Teaches algorithm design under constraints (minimizing operations rather than time)
- Strengthens C fundamentals (linked lists, pointers, memory management)
- Encourages test-driven development using a separate `checker` utility

--------------------------------------------------------------------------------

## Quick highlights

- Robust input parsing and duplicate detection
- Optimal small-element handlers (2–5 elements)
- Indexed normalization and chunking strategies for medium sizes
- Scalable index-based strategy for larger inputs for predictable behavior
- Bonus `checker` program to validate any printed operation sequence

--------------------------------------------------------------------------------

## Project goals

1. Produce a valid, move-efficient sequence of stack operations to sort any valid input list.
2. Keep the code modular and easy to reason about.
3. Provide a `checker` for automatic validation of solutions.

--------------------------------------------------------------------------------

## Allowed operations (what you may print)

| Command | Effect |
|---------|--------|
| `sa` / `sb` | swap the first two elements of stack a / stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` / `pb` | push top from b to a / a to b |
| `ra` / `rb` | rotate (top becomes bottom) |
| `rr` | `ra` and `rb` |
| `rra` / `rrb` | reverse rotate (bottom becomes top) |
| `rrr` | `rra` and `rrb` |

--------------------------------------------------------------------------------

## Implementation notes — what's under the hood

- Input is parsed and validated in `src/push_swap_files/push_swap_parser.c` (duplicates and invalid numbers yield `Error`).
- Stacks are implemented as linked lists with helpers in `src/push_swap_files/push_swap_nodes.c`.
- Elementary moves are implemented in `src/push_swap_files/push_swap_moves.c` and print names of operations.
- Small-input sorts are handled in `src/push_swap_files/push_swap_small_sorts.c` with specific minimal sequences.
- Move-selection strategies live in `src/push_swap_files/push_swap_algo_*.c`.

Algorithmic approaches used:
- 2–3 elements: deterministic minimal sequences.
- 4–5 elements: insertion-like method finding minimal rotations and pushes.
- Medium inputs: index normalization followed by chunking to move index ranges to `b`, then reintegrate with cost-aware rotations.
- Large inputs: scalable index-based strategies (e.g., larger chunks or multi-pass chunking) for predictable results.

The chosen mix seeks a practical balance: small inputs get near-optimal sequences while larger inputs prioritize stable, maintainable strategies.

--------------------------------------------------------------------------------

## Build & run

Compile the binary:

```bash
make
```

Run `push_swap` on a list of integers:

./push_swap 3 2 5 1 4
# prints operation list to stdout
```

Build and run the bonus `checker`:

```bash
make bonus
./push_swap 3 2 1 | ./checker 3 2 1
# prints OK if sorted correctly, KO otherwise
```

Notes:
- Input must contain only valid integers and no repeated values.
- The program prints `Error` to `stderr` and exits non-zero for invalid input.

--------------------------------------------------------------------------------

## Examples

## Project layout (short)

```
push_swap/
├── LICENSE
├── Makefile
├── README.md
├── bonus/
│   ├── checker_program.c
│   └── get_next_line.c
├── includes/
│   ├── ft_printf.h
│   ├── get_next_line.h
│   ├── helper_functions.h
│   └── push_swap_header_file.h
└── src/
    ├── ft_printf_files/
    │   ├── ft_printf.c
    │   ├── ptr_check_ft_printf.c
    │   ├── putchar_ft_printf.c
    │   ├── puthex_ft_printf.c
    │   ├── putnbr_ft_printf.c
    │   ├── putptr_ft_printf.c
    │   ├── putsigned_ft_printf.c
    │   └── putstr_ft_printf.c
    ├── helper_functions/
    │   ├── ft_append.c
    │   ├── ft_atoi.c
    │   ├── ft_split.c
    │   ├── ft_strchr.c
    │   ├── ft_strdup.c
    │   ├── ft_strlen.c
    │   └── ft_substr.c
    └── push_swap_files/
        ├── push_swap_algo_count_moves.c
        ├── push_swap_algo_entry.c
        ├── push_swap_algo_set_targets.c
        ├── push_swap_algo_start_moves.c
        ├── push_swap_dup_check_build_stack.c
        ├── push_swap_index_nodes.c
        ├── push_swap_more_moves.c
        ├── push_swap_moves.c
        ├── push_swap_nodes.c
        ├── push_swap_parser.c
        ├── push_swap_small_sorts.c
        └── push_swap.c
```
- Use scripted or random inputs to compare move counts across strategies.
- Test edge cases: sorted input, reversed input, single element, duplicate detection.
- If measuring move-efficiency, run many random cases and collect averages per strategy.

--------------------------------------------------------------------------------

## Project layout (abridged)

```
push_swap/
├── Makefile
├── includes/
│   ├── push_swap_header_file.h
│   └── helper headers
├── src/
│   └── push_swap_files/
│       ├── push_swap.c
│       ├── push_swap_parser.c
│       ├── push_swap_nodes.c
│       ├── push_swap_moves.c
│       ├── push_swap_small_sorts.c
│       └── push_swap_algo_*.c
└── bonus/
    └── checker_program.c
```

--------------------------------------------------------------------------------

## Learning outcomes

- Algorithmic strategies (chunking, cost calculations)
- Linked-list and pointer manipulation in C
- Robust input validation and error handling
- Designing a checker utility to verify correctness

--------------------------------------------------------------------------------

## Contributing & contact

Suggestions, bug reports, or improvements are welcome — open an issue or reach out to `anasinda`.

---

**Author:** Anas Sindab (`anasinda`) — GitHub: @Anas-Sindab

**License:** See `LICENSE` at repository root.
*This project has been created as part of the 42 curriculum by anasinda.*

# push_swap

**Short description**: A small C program that sorts integers using two stacks and a restricted set of operations. The goal is to produce an efficient (as few operations as possible) sequence that sorts the input numbers.

---

## Description

The `push_swap` project implements an algorithm that sorts a list of distinct integers using only two stacks (commonly named `a` and `b`) and a limited set of operations (push, swap, rotate, reverse-rotate). This is an algorithmic challenge from the 42 curriculum focusing on algorithm design, minimization of moves, and code quality.

Key points:
- Input: a list of integers passed as command-line arguments.
- Output: a sequence of operations printed to `stdout` that, when applied to the initial stack, results in a sorted stack.
- Bonus: a `checker` program (in `bonus/`) that validates whether the operations sort the stack correctly.

---

## Instructions

### Compilation

Standard build:

```bash
make
```

Build the bonus checker program:

```bash
make bonus
```

Clean build artifacts:

```bash
make fclean
```

### Running `push_swap`

Basic usage:

```bash
./push_swap <list of integers>
# e.g.
./push_swap 3 2 5 1 4
```

This prints a newline-separated list of operations to `stdout` (e.g., `sa`, `pb`, `ra`, ...).

To validate the output using the bonus `checker` program:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Notes:
- Inputs must be valid integers and there must be no duplicates.
- The project adheres to the 42 coding standards (Norminette) and uses the provided `Makefile`.

---

## Usage examples

- Minimal example:

```bash
./push_swap 2 1
# output: sa
```

- Pipe to checker for verification:

```bash
./push_swap 5 2 3 1 4 | ./checker 5 2 3 1 4
# output: OK  (or KO when incorrect)
```

---

## Features & Implementation Notes

- Implementation in C using only allowed functions and libraries.
- Focus on minimizing the number of operations.
- Includes a variety of sorting strategies depending on input size (small sorts for few elements, more advanced strategies for larger sets).
- Proper input validation and error handling.

---

### Algorithm choices & implementation details

- **2–3 elements:** hand-crafted minimal sequences (swap/rotate) to guarantee the fewest operations.
- **4–5 elements:** an insertion-style approach that finds minimal rotations and pushes to place elements efficiently.
- **Medium inputs:** values are indexed (0..N-1) to simplify comparisons. The implementation commonly uses chunking (splitting the index range into blocks and moving blocks to `b`) and cost-computation to choose the cheapest rotations in both stacks when moving elements back to `a`.
- **Large inputs:** scalable index-based strategies (chunking and cost-aware reintegration) are used for predictable, scalable behavior when move-count optimality is less critical than consistency and performance.

These strategies balance move minimization and implementation complexity: small inputs receive near-optimal move sequences, while larger inputs use scalable strategies that keep move counts reasonable and the code maintainable.

---

## Resources

- 42 School project subject and internal documentation.
- C Standard Library documentation (man pages).
- Articles and tutorials about stack-based sorting and greedy algorithms.
- Helpful references on sorting algorithms and algorithm analysis.
- Videos on Youtube that try to explain the algorithms.
- Forums that expand on said algorithms like Turk, Chunking, etc...
- Fellow peers that implemented it in the past.

### AI Usage

No AI was used to write or modify production code, algorithms, or the logic of this project. AI tools (for example, ChatGPT, Claude, Deepseek, etc...) were used only as a learning aid to explain complex topics and to help draft or polish documentation. They did not produce working code.

---

## Tests & Validation

- Use `./push_swap` with different inputs and pipe the output to `./checker` to validate correctness.
- Test edge cases: already-sorted inputs, reversed inputs, repeated numbers (should be rejected), and invalid arguments.

---

## License

See the `LICENSE` file at the repository root.

---



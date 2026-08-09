*This project has been created as part of the 42 curriculum by ssokhats, esyaman.*

# Push_swap

## Description

**Push_swap** is an algorithmic group project in the 42 curriculum designed to explore algorithmic complexity (time and space) and sorting efficiency under tight operational constraints. 

The goal is to sort a stack of integers in ascending order using two stacks (`a` and `b`) and a restricted set of allowed stack operations (swaps, pushes, and rotations). Rather than relying solely on a single static sorting algorithm, this implementation calculates input disorder metrics at runtime and dynamically selects or allows manual selection of four distinct complexity strategies.

### Allowed Operations
- **`sa` / `sb` / `ss`**: Swap the top two elements of stack `a`, stack `b`, or both simultaneously.
- **`pa` / `pb`**: Push the top element from one stack onto the other.
- **`ra` / `rb` / `rr`**: Rotate all elements up by one position (top element becomes the bottom).
- **`rra` / `rrb` / `rrr`**: Reverse rotate all elements down by one position (bottom element becomes the top).

---

## Technical & Algorithmic Strategy Choices

To satisfy the complexity requirements of the subject, the binary embeds four distinct sorting strategies selectable via flags:

### 1. Simple Strategy ($O(n^2)$) — `--simple`
- **Internal Method**: Selection Sort Adaptation.
- **Mechanism**: Iteratively locates the minimum element in stack `a`, rotates it to the top using the shortest rotational path (`ra` or `rra`), and pushes it to stack `b`. Once `a` is emptied or reduced to a base size, elements are pushed back to `a`.
- **Complexity**: $O(n^2)$ operations in worst and average cases.

### 2. Medium Strategy ($O(n\sqrt{n})$) — `--medium`
- **Internal Method**: Chunk Sort Adaptation.
- **Mechanism**: Divides the range of sorted indices into $\lfloor\sqrt{n}\rfloor$ discrete chunks. Pushes values to stack `b` based on whether their index falls within the active chunk range, maintaining partial relative ordering in `b` using smart rotations (`rb`). Finally, elements are pushed back to `a` in strict descending order.
- **Complexity**: $O(n\sqrt{n})$ operations on average with $O(n)$ space for indexed indexing.

### 3. Complex Strategy ($O(n \log n)$) — `--complex`
- **Internal Method**: Quick Sort Adaptation (Pivot Partitioning).
- **Mechanism**: Selects a pivot value (e.g., median or element value) and partitions stack a by pushing elements smaller than the pivot to stack b (pb) while retaining larger elements in a using rotations (ra). Recursively splits both stacks into smaller partitions until base cases are reached, then merges elements back into a using precise pushes (pa).
- **Complexity**: $O(n \log n)$ operation upper bound on average across all configurations, using $O(\log n)$ recursive stack space.

### 4. Custom Adaptive Strategy — `--adaptive` (Default)
The adaptive engine evaluates the structural **disorder metric** ($D$) of input stack `a` prior to executing any moves:

$$\text{Disorder } (D) = \frac{\text{Number of inverted pairs}}{\text{Total unique pairs}} = \frac{\sum_{i < j} \mathbb{I}(a[i] > a[j])}{\frac{n(n-1)}{2}}$$

- **Rationale & Thresholds**:
  - **Low Disorder ($D < 0.2$)**: Uses an optimized $O(n^2)$ Selection sort algorithm. When an array is nearly sorted, adaptive local swaps and linear passes produce minimal operation counts.
  - **Medium Disorder ($0.2 \le D < 0.5$)**: Uses the $O(n\sqrt{n})$ Chunk-based algorithm to balance chunk management overhead and rotational cost.
  - **High Disorder ($D \ge 0.5$)**: Uses the $O(n \log n)$ Complex algorithm Quick Sort to ensure strict, bounded performance when the stack is heavily inverted or randomized.

---

## Division of Work

| Teammate (`login`) | Responsibilities & Contributions |
| :--- | :--- |
| **`ssokhats`** | - `stack_creation.c`<br> - `flags_check.c`<br> - `flattern_args.c`<br> - `normalisation.c`<br> - `input_check.c` (is_unique, is_allnum)<br> - `utils.c` (print_bench)<br> - `ps_rules_handling.c`<br> - `disorder_metric.c`<br> - Bonus optimizations |
| **`esyaman`** | - `input_check.c` (is_in_range)<br> - `utils.c` (`ft_atol`)<br> - `ps_rules.c`<br> - `list_operations.c`<br> - generate_disorder(python script)<br> - Full implementation of `bonus/*`
| **`both`** | - All sorting algorithms in `src/sorting_algorithms/`<br> - `main.c`<br> - `Makefile`<br> - `include/push_swap.h`<br> - Code review and bug fixing.

---

## Instructions

### Compilation

Compile the main program using `make`:

```bash
# Compile the main push_swap program
make

# Clean object files
make clean

# Full clean (remove binaries and objects)
make fclean

# Recompile everything
make re
```

# Execution & Usage

```bash
# Default adaptive execution
./push_swap 4 67 3 87 23

# Explicit strategy selection
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1

# Benchmark mode (metrics sent to stderr, operations sent to stdout)
./push_swap --bench 4 67 3 87 23
```

## Bonus: Checker

The bonus program `checker` reads a sequence of push_swap operations from standard input and verifies whether they correctly sort the provided stack.

### Bonus compilation

```bash
# Compile the bonus checker program
make bonus

# Clean bonus object files
make bonus-clean

# Full bonus clean, remove binary and bonus objects
make bonus-fclean

# Rebuild bonus
make bonus-re
```

### Bonus usage

- Run with the same argument format as `push_swap`
- Operations are read from `stdin` as newline-separated rules
- Prints `OK` if the stack is sorted and stack `b` is empty after applying all moves
- Prints `KO` if the result is not sorted or stack `b` is non-empty
- Prints `Error` if any invalid operation is encountered

### Example

```bash
# Run checker using move list from a file
./checker 3 2 1 < moves.txt

# Run checker interactively or via pipe
echo -e "pb\nsa\npa" | ./checker 3 2 1
```

# Resources

* Big-O Notation and Complexity Analysis for Stack-based Sorting.
* YouTube (algorithms explanations).

### AI usage:

AI was used to help explain and understand the different sorting algorithms out there and to help in research implementations. AI also assisted with drafting and refining this README to better match the project requirements.

# generate_disorder.py 

Script for generating disordered list of numbers.
```python
import sys
import random

def compute_disorder(a):
    """Calculates exact disorder fraction matching your formula."""
    mistakes = 0
    total_pairs = 0
    n = len(a)
    for i in range(n):
        for j in range(i + 1, n):
            total_pairs += 1
            if a[i] > a[j]:
                mistakes += 1
    return mistakes / total_pairs if total_pairs > 0 else 0.0

def generate_exact_disorder(n, target_disorder):
    if n <= 1:
        return list(range(1, n + 1))

    total_pairs = (n * (n - 1)) // 2
    target_inversions = round(target_disorder * total_pairs)

    # If target is <= 0.5, start sorted (0 inversions) and add inversions
    if target_inversions <= total_pairs // 2:
        a = list(range(1, n + 1))
        swaps_needed = target_inversions
        valid_indices = {i for i in range(n - 1) if a[i] < a[i + 1]}
        
        for _ in range(swaps_needed):
            i = random.choice(tuple(valid_indices))
            a[i], a[i + 1] = a[i + 1], a[i]
            
            # Update affected adjacent pairs
            for idx in (i - 1, i, i + 1):
                if 0 <= idx < n - 1:
                    if a[idx] < a[idx + 1]:
                        valid_indices.add(idx)
                    else:
                        valid_indices.discard(idx)

    # If target is > 0.5, start reverse-sorted (max inversions) and remove inversions
    else:
        a = list(range(n, 0, -1))
        swaps_needed = total_pairs - target_inversions
        valid_indices = {i for i in range(n - 1) if a[i] > a[i + 1]}
        
        for _ in range(swaps_needed):
            i = random.choice(tuple(valid_indices))
            a[i], a[i + 1] = a[i + 1], a[i]
            
            for idx in (i - 1, i, i + 1):
                if 0 <= idx < n - 1:
                    if a[idx] > a[idx + 1]:
                        valid_indices.add(idx)
                    else:
                        valid_indices.discard(idx)

    return a

if __name__ == "__main__":
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    disorder = float(sys.argv[2]) if len(sys.argv) > 2 else 0.3
    disorder = max(0.0, min(1.0, disorder))

    numbers = generate_exact_disorder(count, disorder)

    # Output straight to terminal (clean for piping)
    for num in numbers:
        print(num)
```

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
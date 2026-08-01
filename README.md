# push_swap

- (Done) Disorder metric
- (Done) Linked lists creation
- (Done) Import Libft
- (Done) Rules creation
- (Done) Rules implementation
- Reading arguments (flags, input stdin) - Reading done but flags doesn't do enithing yet
- The standart output strategy needs to be changed, now each time we implement some of the rules it prints the rule immidiatelly, has to be one string with all rules we used and to print the whole string at once if needed. REDO: make a linked list of operations.
- Add ft_printf and modify it to take fd to make it possible to print in stderr.

- ### Algorithm implementation:
  1. (Done) Simple algorithm (O(n2));
  2. (Done) Medium algorithm (O(n√n));
  3. (Done) Complex algorithm (O(n log n))
  4. Adaptive algorithm

- (2/3 done) Checker for inputs (allowed inputs etc)
- Checker for output (bonus)





# 16/07/2026
- Added int	stack_size(t_stack *lst) to get size of the stack (number of numbers). To be used for implementation in e.g. disorder_metric.

cc push_swap.c src/*.c src/sorting_algorithms/*.c libft/libft.a
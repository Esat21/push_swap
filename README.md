# push_swap

- (Done) Disorder metric
- (Done) Linked lists creation
- (Done) Import Libft
- (Done) Rules creation
- (Done) Rules implementation
- (Done) Reading arguments (flags, input stdin)
- Add ft_printf and modify it to take fd to make it possible to print in stderr.

- ### Algorithm implementation:
  1. (Done) Simple algorithm (O(n2));
  2. (Done) Medium algorithm (O(n√n));
  3. (Done) Complex algorithm (O(n log n))
  4. (Done) Adaptive algorithm

- (2/3 done) Checker for inputs (allowed inputs etc)
- Checker for output (bonus)


# Ideas:
- For medium algorithm, 5 or less numbers:
  - there is extra rra before pb even when there is 1 node left in A. (done)
  - Also, there is rb happening when there is only 1 node in B. (done)
  - Also, the rra or ra if/else checker is not functioning optimally, it is choosing 2 rra instead of one ra. (done, tbh not sure how exactly, but it is not doing it anymore)
These fixes will save at least 2 moves. Currently getting 16 for most tests.

# TO DO
- Multiple flags are accepted, e.g. ./push_swap 2 1 3 4 5 --medium --simple --complex runs on simple and doesn't give any errors.

# 16/07/2026
- Added int	stack_size(t_stack *lst) to get size of the stack (number of numbers). To be used for implementation in e.g. disorder_metric.

# 03/08/2026
- Added exception for rb and rra when size b and a are 1. No need to rotate when there is only one node.
- Also, verified that when we remove the hourglass thingy, for 5 numbers under 0.5 disorder, the no. of moves is always 15 or lower (acceptable) Added this by skipping the rb for hourglass for chunk size 5, it will also affect all list sizes until 35, but it is still okay since the next known performance metric after 5 numbers is 100 (confirm?). Could do a better/cleaner implementation??
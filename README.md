# push_swap

- (*done*) Disorder metric
- (*done*) Linked lists creation
- (*done*) Import Libft
- (*done*) Rules creation
- (*done*) Rules implementation
- (*done*) Reading arguments (flags, input stdin)
- (*done*) Add ft_printf and modify it to take fd to make it possible to print in stderr.
- (2/3 *done*) Checker for inputs (allowed inputs etc)
- Checker for output (bonus)

- ### Algorithm implementation:
  1. (*done*) Simple algorithm (O(n2));
  2. (*done*) Medium algorithm (O(n√n));
  3. (*done*) Complex algorithm (O(n log n))
  4. (*done*) Adaptive algorithm

# Issues
- For medium algorithm, 5 or less numbers:
  - (*done*) there is extra rra before pb even when there is 1 node left in A. 
  - (*done*) Also, there is rb happening when there is only 1 node in B. 
  - (*done*) Also, the rra or ra if/else checker is not functioning optimally, it is choosing 2 rra instead of one ra. (*done*, tbh not sure how exactly, but it is not doing it anymore)
- (*done* - follow up) Multiple flags are accepted, e.g. ./push_swap 2 1 3 4 5 --medium --simple --complex runs on simple and doesn't give any errors. We could scratch this edge case, nothing is mentioned. As backup, I made the default to Adaptive, i.e. if multiple flags provided, it will default to adaptive :)
- Need to handle already sorted input, currently, we are still doing actions.


# Ideas:
- Potentially, a better error handling for multiple flags as error is currently being handled in the main. 
- Need to handle the bonus compilation. The checker is working now, might need refining and edge case handling.


# TO DO
- 

# 16/07/2026
- Added int	stack_size(t_stack *lst) to get size of the stack (number of numbers). To be used for implementation in e.g. disorder_metric.

# 03/08/2026
- Added exception for rb and rra when size b and a are 1. No need to rotate when there is only one node.
- Also, verified that when we remove the hourglass thingy, for 5 numbers under 0.5 disorder, the no. of moves is always 15 or lower (acceptable) Added this by skipping the rb for hourglass for chunk size 5, it will also affect all list sizes until 35, but it is still okay since the next known performance metric after 5 numbers is 100 (confirm?). Could do a better/cleaner implementation??
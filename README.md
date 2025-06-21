--------------------------------------------------------------------------------------
|                      Main Process (main function)                                   |
|                           └─> (is_sorted) ─┐                                        |
|                                           |                                         |
|                                           v                                         |
|                                   [Input Parsing]                                   |
|                                ──> ft_atoi(argv) ─> get_nbr_stack(argv)             |
|                                           |                                         |
|                                           v                                         |
|                                 [Create Stack and Nodes]                          |
|                           └──> t_stack *stk = get_nbr_stack(argv)                 |
|                           └──> t_node **start = get_node(stk)                     |
|                                           |                                       |
|                                           v                                       |
|                                 [Operations]                                      |
|                         ┌────────────────┼────────────────┐                        |
|                         v                v                v                       |
|                 ┌───────┴───────┐   ┌───────┴───────┐   ┌───────┴───────┐         |
|                 ft_s()         ft_p()            ft_r()            ft_rr()         |
|                 (swap)         (push)            (rotate)          (reverse rotate)|
|                         |                |                |                       |
|                         v                v                v                       |
|                      [Update Stack]   [Update Stack]   [Update Stack]              |
|                       └────────────────┴────────────────┴───────────────────────────|
|                                            |
|                                            v
|                              [Sorting Functions]                                 |
|                       ┌──────────────────────────────────────────────────┐        |
|                       v                                                    v       |
|                  push_swap_by_size()                                   sort_small()  |
|                       └──────┬──────────────────┐                         (Sort 3-5 elements)|
|                              v                                  ┌──────────────────────────┐
|                    sort_medium()                             sort_big()                 |
|                    (Sort 6-100 elements)                    (Sort large stacks)         |
|                          └───────────────────────────────────────────────────────────────|
|                                      |
|                                      v
|                             [Final Check] (is_sorted)
--------------------------------------------------------------------------------------

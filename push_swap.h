#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdbool.h>

typedef struct s_stack //the whole stack node structure
{
    int value; //The actual number from input (e.g. 42, -3)
    int index; //position in sorted order (0 = smallest)
    int pos;   //current position in next stack (0 = top)
    struct s_stack  *next; //pointer to next node
} t_stack;



//parsing
bool    is_valid_integer(char *str);
bool    has_duplicates(t_stack *stack);
bool    is_sorted(t_stack *stack);
bool    parse_arguments(int ac,char **av,t_stack **stack_a);
bool    validate_and_create_stack(char **args,t_stack **stack_a);


//utils
t_stack *stack_new(int value);
void free_stack(t_stack **stack);
void    stack_add_back(t_stack **stack,t_stack *new_node);
t_stack *stack_last(t_stack *stack);
t_stack *stack_before_last(t_stack *stack);
int stack_size(t_stack *stack);



//operations
void    pa(t_stack **stack_a, t_stack **stack_b);
void    pb(t_stack **stack_a,t_stack **stack_b);
void    reverse_rotate(t_stack **stack);
void    rra(t_stack **stack_a);
void    rrb(t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    rotate(t_stack **stack);
void    ra(t_stack **stack_a);
void    rb(t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
void    swap(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);

//algorithm
void    assign_indices(t_stack *stack);
void    sort_three(t_stack **stack_a);
void    sort_4_5_elements(t_stack **stack_a, t_stack **stack_b);
void    sort_two(t_stack **stack_a);

int  calculate_chunk_count(int size);
int  find_first_pos(t_stack *stack, int max_index);
int find_last_pos(t_stack *stack,int max_index);
int get_best_pos(t_stack *stack, int max_index);
void rotate_a_to_top(t_stack **stack_a,int position);
void    push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
void push_back_to_a(t_stack **stack_a, t_stack **stack_b);


void    chunk_sort(t_stack **stack_a, t_stack **stack_b);
#endif

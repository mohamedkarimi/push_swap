/**
 * @brief Main entry point for push_swap program
 * 
 * Program flow:
 *   1. Parse arguments → build stack A
 *   2. Check if already sorted → exit if yes
 *   3. Choose sorting strategy based on size:
 *      - 2 elements: simple swap
 *      - 3 elements: hardcoded optimal solution
 *      - 4-5 elements: push min to B, sort 3, push back
 *      - 6+ elements: chunk algorithm
 *   4. Execute chosen algorithm
 *   5. Clean up and exit
 * 
 * Error handling:
 *   - Invalid input → print "Error\n" to stderr
 *   - Empty input → exit silently
 *   - Memory errors → free and exit
 * 
 * @param argc Argument count
 * @param argv Argument vector
 * @return 0 on success, 1 on error
 */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int size;

    stack_a = NULL;
    stack_b = NULL;

    if(ac < 2)
        return 0;
    if(!parse_arguments(ac, av, &stack_a))
    {
        ft_putstr_fd("Error\n",2);
        free_stack(&stack_a);
        return (1);
    }
    if(is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }
    size = stack_size(stack_a);
    if(size == 2)
        sort_two(&stack_a);
    else if(size == 3)
        sort_three(&stack_a);
    else if(size <= 5)
        sort_4_5_elements(&stack_a,&stack_b);
    else
        chunk_sort(&stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
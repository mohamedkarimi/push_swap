#include "push_swap.h"

bool    parse_arguments(int ac,char **av,t_stack **stack_a)
{
    char **args;
    bool need_free;
    bool success;

    if (ac < 2)
        return (false);
    if(ac == 2)
    {
        args = ft_split(av[1],' ');
        need_free = true;
        if(!args || !args[0])
        {
            if(args)
                ft_free_split(args);
            return (false);
        }
    }
    else
    {
        args = &av[1];
        need_free = false;
    }
    success = validate_and_create_stack(args, stack_a);
    if (need_free)
        ft_free_split(args);
    return (success);
}

bool    validate_and_create_stack(char **args,t_stack **stack_a)
{
    int i = 0;
    long num;
    t_stack *node;
    while(args[i])
    {
        if(!is_valid_integer(args[i]))
            return false;
        num = ft_atoi(args[i]);
        if(num > INT_MAX || num < INT_MIN)
            return false;
        node = stack_new((int)num);
        if(!node)
        {
            free_stack(stack_a);
            return false;
        }
        stack_add_back(stack_a,node);
        i++;
    }
    if(has_duplicates(*stack_a))
    {
        free_stack(stack_a);
        return false;
    }
    return true;
}
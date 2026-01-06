#include "push_swap.h"

bool    is_valid_integer(char *str)
{
    int i;
    if(!str || !*str)
        return false;
    i = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    if(!str[i])
        return false;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

bool    has_duplicates(t_stack *stack)
{
    t_stack *current;
    t_stack *checker;

    current = stack;
    while (current)
    {
        checker = current->next;
        while(checker)
        {
            if(current->value == checker->value)
                return true;
            checker = checker->next;
        }
        current = current->next;
    }
    return false;
}

bool    is_sorted(t_stack *stack)
{
    if(!stack)
        return true;
    while (stack->next)
    {
        if(stack->value > stack->next->value)
            return false;
        stack = stack->next;
    }
    return true;
}
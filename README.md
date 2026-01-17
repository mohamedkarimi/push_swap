# Push_swap

_This project has been created as part of the 42 curriculum by [mokarimi]._

---

## Description

**Push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations, with the goal of minimizing the number of instructions.

### Goal
Sort stack `a` in ascending order (smallest on top) using only these operations:
- `sa` - swap first two elements of stack a
- `sb` - swap first two elements of stack b
- `ss` - `sa` and `sb` at the same time
- `pa` - push top element from b to a
- `pb` - push top element from a to b
- `ra` - rotate stack a up (first element becomes last)
- `rb` - rotate stack b up
- `rr` - `ra` and `rb` at the same time
- `rra` - reverse rotate stack a down (last element becomes first)
- `rrb` - reverse rotate stack b down
- `rrr` - `rra` and `rrb` at the same time

### The Challenge
Find the most efficient sequence of operations to sort any given stack, staying within these operation limits:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

### Algorithm: Chunk Algorithm

This implementation uses the **Chunk Algorithm**, which divides the sorting process into three clear phases:

1. **Indexing Phase**: Assign each number its position in sorted order (0 = smallest, 1 = second smallest, etc.)

2. **Push to B Phase**: Divide numbers into chunks based on their index and push all elements to stack B in organized groups, processing smallest indices first

3. **Push Back to A Phase**: Return elements to stack A by always selecting the largest remaining index from B

**Why chunks?** Instead of searching through all elements randomly, we process them in organized ranges, significantly reducing the number of operations needed.

---

### Error Handling

The program displays `Error\n` to stderr for:
- Non-integer arguments: `./push_swap 1 2 abc`
- Duplicates: `./push_swap 1 2 3 2`
- Integer overflow: `./push_swap 2147483648`
- Out of range: `./push_swap -2147483649`

The program displays nothing and exits for:
- No arguments: `./push_swap`
- Empty string: `./push_swap ""`

---

### AI Usage

**Claude (Anthropic) was used for:**
- ✅ Understanding the chunk algorithm concept and strategy
- ✅ Explaining sorting algorithm trade-offs and complexity analysis
- ✅ Debugging assistance for edge cases and logical errors
- ✅ Code structure suggestions and best practices
- ✅ Optimization strategies for reducing operation count
- ✅ Documentation and README formatting

---

## Features

- ✅ Sorts any stack of integers efficiently
- ✅ Handles both input formats: `./push_swap 3 2 1` and `./push_swap "3 2 1"`
- ✅ Comprehensive error handling (duplicates, non-integers, overflow)
- ✅ Optimized for different stack sizes (2, 3, 4-5, 100, 500)
- ✅ No memory leaks (validated with Valgrind)
- ✅ Norminette compliant (42 coding standards)
- ✅ No global variables
- ✅ Proper Makefile (doesn't relink)

---

## 🔧 Technical Choices

### Data Structure: Singly Linked List
```c
typedef struct s_stack
{
    int             value;      // The actual integer value
    int             index;      // Position in sorted order (0 = smallest)
    struct s_stack  *next;      // Pointer to next node
}   t_stack;
```

**Why a linked list?**
- Dynamic size - no need to predefine maximum stack size
- Efficient push/pop operations at the head (O(1))
- Natural representation of a stack data structure
- Easy traversal for searching and indexing

### Algorithm Strategy

**For 2-3 elements:** Hardcoded optimal solutions
- Maximum 3 operations for any 3-element permutation
- Fastest possible approach for small inputs

**For 4-5 elements:** Push smallest to B, sort remaining 3, push back
- Leverages the optimal 3-element sorting
- Maximum 12 operations

**For 6+ elements:** Chunk algorithm
- Divides problem into manageable sub-problems
- Balances simplicity with efficiency
- Consistently achieves ~4500 operations for 500 numbers
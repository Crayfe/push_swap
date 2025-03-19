# PUSH_SWAP

[Español](README.md) | [English](README.en.md)

| 42 Project | Description |
| ----------- | ----------- |
| <a href=""> <img src="https://github.com/0bvim/42-project-badges/blob/main/badges/push_swape.png?raw=true" alt="Push Swap Badge"/></a> | Push_swap is an algorithmic project developed in C that aims to sort a set of integers in stack a using a limited set of instructions while optimizing the number of moves. To achieve this, an efficient algorithm must be implemented to generate the shortest possible sequence of sorting operations. |

## 🎯 Objective
The main goal of this project is to develop a program called `push_swap` that takes a list of integers as arguments and generates the shortest sequence of instructions to sort those numbers in ascending order. This exercise not only reinforces fundamental concepts of sorting algorithms but also introduces the developer to algorithmic complexity.

## ⚙️ How the Program Works
The program receives a list of integers as arguments, which are then loaded into **stack a**. Before loading, the input must be validated to ensure that the numbers are suitable for sorting. From there, the goal is to arrange them in ascending order using the following operations:

| Instruction | Description                                              |
| ----------- | -------------------------------------------------------- |
| **sa**      | Swaps the first two elements of stack a                |
| **sb**      | Swaps the first two elements of stack b                |
| **ss**      | Swaps the first two elements of a and b at the same time |
| **pa**      | Takes the first element from b and puts it into a       |
| **pb**      | Takes the first element from a and puts it into b       |
| **ra**      | Rotates all elements of a up                              |
| **rb**      | Rotates all elements of b up                              |
| **rr**      | Rotates a and b up simultaneously                         |
| **rra**     | Rotates all elements of a down                            |
| **rrb**     | Rotates all elements of b down                            |
| **rrr**     | Rotates a and b down simultaneously                       |

The program prints the sequence of operations needed to sort the list to standard output.

## Implementation
For the implementation of the project, the original linked list structure developed in the **libft** project was used. A new struct called `t_content` was created, which stores an integer value to be sorted and another integer indicating the position in which the number should be once the list is sorted:

```c
typedef struct s_content
{
    int value;        // Valor numérico
    int sorted_pos;   // Posición ordenada del valor
} t_content;
```

This data type will be the one handled by the linked list. This approach simplifies data management, reduces complexity and the number of implemented functions, and enables efficient management of values and facilitates indexing without repeatedly traversing the stacks (K.I.S.S).

### 🧮 Algorithms Used:
Several algorithms have been proposed in a staggered manner depending on the number of numbers to be sorted:
#### **Three-sort**
Sorts a stack composed of 3 numbers applying trivial solutions without having to use stack b.
#### **Mini-sort**
Sorts a stack composed of numbers between 4 and 7, doing up to three loops of iterative sorting, passing the largest numbers to stack b, and when only 3 numbers remain in stack a, the previous algorithm is reused, and the numbers that were passed to stack b are introduced already sorted.
#### **k-sort**
Sorts a stack of numbers greater than 7. To achieve sorting in the fewest number of moves, the **k-sort** algorithm optimizes the process by grouping elements into subsets and performing incremental sorting. This approach significantly reduces the number of operations compared to simpler algorithms.

### 🔧 Functions Implemented
According to the purpose and utility of each function, they have been organized into different files:

*   **ps\_input\_utils.c**: Reading and validation of non-duplicate integer type numeric arguments and loading them into stack a.

    *   `load_stack(int argc, char **argv)`: Loads the numbers from the arguments into stack a if the data is valid; otherwise, it returns null.
*   **ps\_array\_utils.c**: Array handling

    *   Functions to create and handle arrays that will be useful for creating an index with the position of each element once it is sorted. To do this, an array is created containing the same numbers from stack a while maintaining its order, a duplicate of that array will be created with the elements already sorted using the bubble sort algorithm, and finally, an index is created by searching for each unsorted number in the sorted array to determine its position when sorted, then load those values into stack a and free the memory of the arrays.
*   **ps\_swap.c**: Swaps the first two elements of a stack

    *   `swap_a(t_list **stack_a)`: Swaps the first two elements of stack `a`.
    *   `swap_b(t_list **stack_b)`: Swaps the first two elements of stack `b`.
    *   `swap_a_b(t_list **stack_a, t_list **stack_b)`: Performs `swap_a` and `swap_b` simultaneously.
*   **ps\_push.c**: Movement between stacks

    *   `push_a(t_list **stack_b, t_list **stack_a)`: Moves the first element from stack `b` to stack `a`.
    *   `push_b(t_list **stack_a, t_list **stack_b)`: Moves the first element from stack `a` to stack `b`.
*   **ps\_rotate.c**: Rotation

    *   `rotate_a(t_list **stack_a)`: Rotates all elements of stack `a` up.
    *   `rotate_b(t_list **stack_b)`: Rotates all elements of stack `b` up.
    *   `rotate_a_b(t_list **stack_a, t_list **stack_b)`: Performs both rotations simultaneously.
*   **ps\_rev\_rotate.c**: Reverse rotation

    *   `rev_rotate_a(t_list **stack_a)`: Rotates all elements of stack `a` down.
    *   `rev_rotate_b(t_list **stack_b)`: Rotates all elements of stack `b` down.
    *   `rev_rotate_a_b(t_list **stack_a, t_list **stack_b)`: Performs both reverse rotations simultaneously.
*   **ps\_stack\_utils.c**: Utilities for stacks

    *   Functions to obtain minimum and maximum positions, calculate rotation costs, and verify if a stack is sorted.
*   **ps\_sort.c**: Sorting algorithms

    *   `three_sort(t_list **stack)`: Sorts a list of three elements.
    *   `mini_sort(t_list **stack_a, t_list **stack_b, int size)`: Sorts a list of four to seven elements.
    *   `k_sort(t_list **stack_a, t_list **stack_b, int size)`: Sorts a list of more than 7 numbers.

## Evaluation and Performance
To pass the project, the following efficiency criteria must be met:
*   **Sort 100 numbers in less than 700 operations.** ✅
*   **Sort 500 numbers in less than 5500 operations.** ✅

## Checker (Bonus)
Once the mandatory part was completed, an additional program called *checker* was implemented. This program replicates the operation of the main project, but instead of applying a sorting algorithm, it executes the instructions read from standard input one by one. For this, the *get\_next\_line* function, implemented in a previous project, is used. At the end of the instructions, it is verified whether the stack is correctly sorted and returns **"OK"**, **"KO"**, or **"Error"** as appropriate.

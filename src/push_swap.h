/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:49 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/src/libft.h"
/* In ps_input_utils.c       */
t_list	*load_stack(int argc, char **argv);
/* In ps_swap.c:             */
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_push.c:             */
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
/* In ps_rotate.c:           */
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_rev_rotate.c:       */
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_stack_utils.c:      */
int		get_min_value_pos(t_list *stack);
int		get_max_value_pos(t_list *stack);
int		get_rotate_cost(t_list **stack, int pos);
int		is_stack_sorted(t_list *stack, int size);
void	print_stacks(t_list *stack_a, t_list *stack_b);
/*In ps_array_utils.c        */
int		get_value_pos(int *array, int value, int size);
int		*create_array(t_list **stack, int size);
int		*sort_array(int *array, int size);
int		load_sorted_positions(t_list **stack, int size);
/*In ps_sort.c:         */
void	three_sort(t_list **stack);
void	mini_sort(t_list **stack_a, t_list **stack_b, int size);
void	k_sort(t_list **stack_a, t_list **stack_b, int size);
typedef struct s_content
{
	int	value;
	int	sorted_pos;
}	t_content;

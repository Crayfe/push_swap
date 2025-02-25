/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:51:37 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
void	test_movements(t_list **stack_a, t_list **stack_b)
{
	print_stacks(stack_a[0], stack_b[0]);
	ft_printf("Is the stack ordered? : %i\n", is_stack_sorted(stack_a[0], 0));
	swap_a(stack_a);
	print_stacks(stack_a[0], stack_b[0]);
	ft_printf("Is the stack ordered? : %i\n", is_stack_sorted(stack_a[0], 0));
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	swap_b(stack_b);
	push_a(stack_b, stack_a);
	print_stacks(stack_a[0], stack_b[0]);
	rotate_a(stack_a);
	rotate_a(stack_a);
	rev_rotate_a(stack_a);
	rev_rotate_a(stack_a);
	print_stacks(stack_a[0], stack_b[0]);
	ft_printf("Is the stack ordered? : %i\n", is_stack_sorted(stack_a[0], 0));
}
*/
static	void	perform_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a[0]);
	if (is_stack_sorted(stack_a[0], 0))
		return ;
	else if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else if (size <= 7)
		mini_sort(stack_a, stack_b, size);
	else
		k_sort(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc > 1)
	{
		stack_a = load_stack(argc, argv);
		if (!stack_a)
			return (ft_putstr_fd("Error\n", 2), 0);
		else
		{
			perform_sort(&stack_a, &stack_b);
			ft_lstclear(&stack_a, free);
			ft_lstclear(&stack_b, free);
		}
	}
	return (0);
}

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

void	test_movements(t_list **stack_a, t_list **stack_b)
{
	print_stacks(stack_a[0], stack_b[0]);
	ft_printf("Is the stack ordered? : %i\n", is_stack_ordered(stack_a[0]));
	swap_a(stack_a);
	print_stacks(stack_a[0], stack_b[0]);
	ft_printf("Is the stack ordered? : %i\n", is_stack_ordered(stack_a[0]));
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
	ft_printf("Is the stack ordered? : %i\n", is_stack_ordered(stack_a[0]));
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
			return (ft_printf("Error\n"), 0);
		else
		{
			/*test_movements(&stack_a, &stack_b);
			print_stacks(stack_a, stack_b);
			ft_printf("Ordering...\n");*/
			apply_algorithm(&stack_a, &stack_b);
			/*print_stacks(stack_a, stack_b);*/
			ft_lstclear(&stack_a, free);
			ft_lstclear(&stack_b, free);
		}
	}
	return (0);
}

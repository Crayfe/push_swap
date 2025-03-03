/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/03 14:07:44 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

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
			return (ft_putstr_fd("Error\n", 2), 1);
		else
		{
			check_sort(&stack_a, &stack_b);
			ft_lstclear(&stack_a, free);
			ft_lstclear(&stack_b, free);
		}
	}
	return (0);
}

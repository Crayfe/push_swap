/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/20 21:38:07 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	apply_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	aux_value;

	while (ft_lstsize(stack_a[0]) > 0)
	{
		aux_value = get_stack_top(stack_a[0]);
		while (ft_lstsize(stack_b[0]) > 0 && get_stack_top(stack_b[0]) < aux_value)
			push_a(stack_b, stack_a);
		push_b(stack_a, stack_b);
	}
	while (ft_lstsize(stack_b[0]) > 0)
		push_a(stack_b, stack_a);
}

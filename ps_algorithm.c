/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:38:59 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void	push_a_from_pos(t_list **stack_a, t_list **stack_b, int pos)
{
	int	i;

	i = 0;
	while(i < pos)
	{
		rotate_a(stack_a);
		i++;
	}
	push_b(stack_a, stack_b);
}

void	apply_algorithm(t_list **stack_a, t_list **stack_b)
{
	int	pos;

	while (ft_lstsize(stack_a[0]) > 0)
	{
		pos = get_min_value_pos(stack_a[0]);
		push_a_from_pos(stack_a, stack_b, pos);
	}
	while (ft_lstsize(stack_b[0]) > 0)
		push_a(stack_b, stack_a);
}

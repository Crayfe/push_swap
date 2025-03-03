/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_stack_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/03 17:12:01 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

int	is_stack_sorted(t_list *stack, int size)
{
	int	value;
	int	i;

	if (ft_lstsize(stack) > 1 && size == 0)
	{
		while (stack->next)
		{
			value = ((t_content *)stack->content)->value;
			stack = stack->next;
			if (value > ((t_content *)stack->content)->value)
				return (0);
		}
	}
	else if (ft_lstsize(stack) > 1 && size > 0)
	{
		i = -1;
		while (stack->next && i++ < size)
		{
			value = ((t_content *)stack->content)->value;
			stack = stack->next;
			if (value > ((t_content *)stack->content)->value)
				return (0);
		}
	}
	return (1);
}

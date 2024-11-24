/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/20 21:38:07 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_stack_top(t_list *stack)
{
	return (*(int *)(stack->content));
}

int	get_stack_bot(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (*(int *)(stack->content));
}

int	is_stack_ordered(t_list *stack)
{
	int	value;

	if (ft_lstsize(stack) > 1)
	{
		while (stack->next)
		{
			value = *(int *)(stack->content);
			stack = stack->next;
			if (value > *(int *)(stack->content))
				return (0);
		}
	}
	return (1);
}

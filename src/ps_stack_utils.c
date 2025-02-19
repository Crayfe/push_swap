/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:33:59 by cayuso-f         ###   ########.fr       */
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

int	get_max_value_pos(t_list *stack)
{
	int	i;
	int	max;
	int	pos;

	max = *(int *)(stack->content);
	pos = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
		if (*(int *)(stack->content) > max)
		{
			max = *(int *)(stack->content);
			pos = i;
		}
	}
	return (pos);
}

int	get_min_value_pos(t_list *stack)
{
	int	i;
	int	min;
	int	pos;

	min = *(int *)(stack->content);
	pos = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
		if (*(int *)(stack->content) < min)
		{
			min = *(int *)(stack->content);
			pos = i;
		}
	}
	return (pos);
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

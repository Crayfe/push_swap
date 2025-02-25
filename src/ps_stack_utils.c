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
	return (((t_content *)stack->content)->value);
}

int	get_stack_bot(t_list *stack)
{
	while (stack->next)
		stack = stack->next;
	return (((t_content *)stack->content)->value);
}

int	get_max_value_pos(t_list *stack)
{
	int	i;
	int	max;
	int	pos;

	max = ((t_content *)stack->content)->value;
	pos = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
		if (((t_content *)stack->content)->value > max)
		{
			max = ((t_content *)stack->content)->value;
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

	min = ((t_content *)stack->content)->value;
	pos = 0;
	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
		if (((t_content *)stack->content)->value < min)
		{
			min = ((t_content *)stack->content)->value;
			pos = i;
		}
	}
	return (pos);
}

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

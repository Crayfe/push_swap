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

void	three_sort(t_list **stack)
{
	int	pos;

	pos = get_max_value_pos(stack[0]);
	if (pos == 0)
		rotate_a(stack);
	else if (pos == 1)
		rev_rotate_a(stack);
	else if (pos == 2)
		swap_a(stack);
	if (!is_stack_sorted(stack[0], 3))
		swap_a(stack);
}

void	mini_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	min_pos;
	int	i;

	i = size - 3;
	while (i--)
	{
		min_pos = get_min_value_pos(stack_a[0]);
		if (min_pos <= size / 2)
			while (min_pos--)
				rotate_a(stack_a);
		else
		{
			min_pos = size - min_pos;
			while (min_pos--)
				rev_rotate_a(stack_a);
		}
		if (is_stack_sorted(stack_a[0], 0) && ft_lstsize(stack_b[0]) == 0)
			return ;
		push_b(stack_a, stack_b);
		--size;
	}
	three_sort(stack_a);
	while (ft_lstsize(stack_b[0]) > 0)
		push_a(stack_b, stack_a);
}

static	void	sort_to_stack_b(t_list **stack_a, t_list **stack_b, int k)
{
	int	i;

	i = 0;
	while (stack_a[0])
	{
		if (((t_content *)stack_a[0]->content)->sorted_pos <= i)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
		}
		else if (((t_content *)stack_a[0]->content)->sorted_pos <= i + k)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a);
	}
}

static	void	sort_to_stack_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	rb_cost;
	int	rrb_cost;

	while (size - 1 >= 0)
	{
		rb_cost = get_rotate_cost(stack_b, size - 1);
		rrb_cost = (size + 3) - rb_cost;
		if (rb_cost <= rrb_cost)
		{
			while (((t_content *)stack_b[0]->content)->sorted_pos != size - 1)
				rotate_b(stack_b);
			push_a(stack_b, stack_a);
			size--;
		}
		else
		{
			while (((t_content *)stack_b[0]->content)->sorted_pos != size - 1)
				rev_rotate_b(stack_b);
			push_a(stack_b, stack_a);
			size--;
		}
	}
}

void	k_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	k;

	k = ft_sqrt(size) * 14 / 10;
	if (!load_sorted_positions(stack_a, size))
		return ;
	sort_to_stack_b(stack_a, stack_b, k);
	sort_to_stack_a(stack_a, stack_b, size);
}

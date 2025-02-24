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

int	*create_array(t_list **stack, int size)
{
	int	i;
	int	*array;
	t_list	*aux;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (0);
	aux = stack[0];
	i = -1;
	while (i++ < size - 1)
	{
		array[i] = *(int *)(aux->content);
		aux = aux->next;
	}
	return (array);
}

int	*sort_array(int *array, int size)
{
	int	*sorted_array;
	int	item;
	int	i;
	int	j;

	sorted_array = (int *)malloc(sizeof(int) * size);
        if (!sorted_array)
                return (0);
	i = -1;
	while (i++ < size - 1)
		sorted_array[i] = array[i];
	i = 1;
	while (i < size)
	{
		item = sorted_array[i];
		j = i - 1;
		while (j >= 0 && sorted_array[j] > item)
		{
			sorted_array[j + 1] = sorted_array[j];
			j = j - 1;
		}
		sorted_array[j + 1] = item;
		i++;
	}
	return (sorted_array);
}

void	three_sort(t_list **stack_a)
{
	int	pos;

	pos = get_max_value_pos(stack_a[0]);
	if (pos == 0)
		rotate_a(stack_a);
	else if (pos == 1)
		rev_rotate_a(stack_a);
	else if (pos == 2)
		swap_a(stack_a);
	if (!is_stack_sorted(stack_a[0], 3))
		swap_a(stack_a);
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

void	k_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	*array;
	int	*sorted_array;

	(void)stack_b;
	array = create_array(stack_a, size);
	if (!array)
		return ;
	sorted_array = sort_array(array, size);
	if (!sorted_array)
		return ;
	i = -1;
	ft_printf("Array:\n");
	while (i++ < size - 1)
		ft_printf("%i\n", array[i]);
	i = -1;
	ft_printf("Sorted Array:\n");
        while (i++ < size - 1)
                ft_printf("%i\n", sorted_array[i]);
	free(array);
	free(sorted_array);

}
void	apply_algorithm(t_list **stack_a, t_list **stack_b)
{
/*	dummy_algorithm(stack_a, stack_b);*/
	int	size;

	size = ft_lstsize(stack_a[0]);
	if (is_stack_sorted(stack_a[0], 0))
		ft_printf("\n");
	else if (size == 2)
		swap_a(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else if (size <= 7)
		mini_sort(stack_a, stack_b, size);
	else
		k_sort(stack_a, stack_b, size);
}

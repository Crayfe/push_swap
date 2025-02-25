/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:33:59 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_value_pos(int *array, int value, int size)
{
	int	i;

	i = 0;
	while (array[i] != value && i < size)
		i++;
	if (array[i] != value)
		return (-1);
	return (i);
}

int	*create_array(t_list **stack, int size)
{
	int		i;
	int		*array;
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

int	load_sorted_positions(t_list **stack, int size)
{
	int		*array;
	int		*sorted_array;
	int		i;
	t_list	*aux;

	array = create_array(stack, size);
	if (!array)
		return (0);
	sorted_array = sort_array(array, size);
	if (!sorted_array)
	{
		free(array);
		return (0);
	}
	aux = stack[0];
	i = -1;
	while (i++ < size - 1)
	{
		((t_content *)aux->content)->sorted_pos
			= get_value_pos(sorted_array, array[i], size);
		if (((t_content *)aux->content)->sorted_pos == -1)
			return (free(array), free(sorted_array), 0);
		aux = aux->next;
	}
	return (free(array), free(sorted_array), 1);
}

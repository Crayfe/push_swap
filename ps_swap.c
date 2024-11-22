/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_swap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*aux;

	if (ft_lstsize(stack[0]) > 1)
	{
		aux = stack[0]->next;
		stack[0]->next = aux->next;
		aux->next = stack[0];
		stack[0] = aux;
		return (1);
	}
	return (0);
}

void	swap_a(t_list **stack_a)
{
	if (swap(stack_a))
		ft_printf("sa\n");
}

void	swap_b(t_list **stack_b)
{
	if (swap(stack_b))
		ft_printf("sb\n");
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) || swap(stack_b))
		ft_printf("ss\n");
}

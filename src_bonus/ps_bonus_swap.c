/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

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
	swap(stack_a);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
}

void	swap_a_b(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

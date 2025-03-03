/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_rotate.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

int	rotate(t_list **stack)
{
	t_list	*aux;

	if (ft_lstsize(stack[0]) > 1)
	{
		aux = stack[0];
		stack[0] = stack[0]->next;
		aux->next = 0;
		ft_lstadd_back(stack, aux);
		return (1);
	}
	return (0);
}

void	rotate_a(t_list **stack_a)
{
	if (rotate(stack_a))
		;
}

void	rotate_b(t_list **stack_b)
{
	if (rotate(stack_b))
		;
}

void	rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) || rotate(stack_b))
		;
}

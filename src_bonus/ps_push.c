/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	push(t_list **stack_src, t_list **stack_dst)
{
	t_list	*aux;

	if (stack_src[0])
	{
		aux = stack_src[0];
		stack_src[0] = stack_src[0]->next;
		ft_lstadd_front(stack_dst, aux);
		return (1);
	}
	return (0);
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	if (push(stack_b, stack_a))
		;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b))
		;
}

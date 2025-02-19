/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	rev_rotate(t_list **stack)
{
	t_list	*aux;
	t_list	*prev;

	if (ft_lstsize(stack[0]) > 1)
	{
		prev = stack[0];
		aux = prev->next;
		while (aux->next)
		{
			prev = aux;
			aux = aux->next;
		}
		prev->next = 0;
		ft_lstadd_front(stack, aux);
		return (1);
	}
	return (0);
}

void	rev_rotate_a(t_list **stack_a)
{
	if (rev_rotate(stack_a))
		ft_printf("rra\n");
}

void	rev_rotate_b(t_list **stack_b)
{
	if (rev_rotate(stack_b))
		ft_printf("rrb\n");
}

void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b)
{
	if (rev_rotate(stack_a) || rev_rotate(stack_b))
		ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/20 21:38:07 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	isnum(char *s)
{
	int	i;
	int	num;

	if (!s)
		return (0);
	i = 0;
	num = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (ft_isdigit(s[i]) || (s[i] == '-' && ft_isdigit(s[1])))
				num = 1;
			else
				return (0);
		}
		else
			if (!ft_isdigit(s[i]))
				return (0);
		i++;
	}
	return (num);
}

int	isint(long num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
		return (0);
}

int	iscontentdup(t_list *stack, long num)
{
	t_list	*aux_node;

	aux_node = stack;
	if (!isint(num))
		return (1);
	while (aux_node)
	{
		if (*(int *)aux_node->content == (int)num)
			return (1);
		aux_node = aux_node->next;
	}
	return (0);
}

t_list	*load_stack(int argc, char **argv)
{
	int		i;
	long	num;
	t_list	*new_node;
	t_list	*loading_stack;

	i = 0;
	loading_stack = 0;
	while (i++ < argc -1)
	{
		num = ft_atol(argv[i]);
		if (!isnum(argv[i]) || !isint(num) || iscontentdup(loading_stack, num))
			return (ft_lstclear(&loading_stack, free), (void *)0);
		new_node = ft_lstnew(malloc(sizeof(int)));
		*(int *)(new_node->content) = (int)num;
		if (!loading_stack)
			loading_stack = new_node;
		else
			ft_lstadd_back(&loading_stack, new_node);
	}
	return (loading_stack);
}

void	print_stack(t_list *stack)
{
	t_list	*aux_node;

	aux_node = stack;
	ft_printf("Init a and b:\n");
	while (aux_node)
	{
		ft_printf("%i\n", *(int *)aux_node->content);
		aux_node = aux_node->next;
	}
	ft_printf("_ _\n");
	ft_printf("a b\n");
}

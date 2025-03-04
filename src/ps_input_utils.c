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

static	int	isnum(char *s)
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

static	int	isint(long num)
{
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
		return (0);
}

static	int	iscontentdup(t_list *stack, long num)
{
	t_list	*aux_node;

	aux_node = stack;
	if (!isint(num))
		return (1);
	while (aux_node)
	{
		if (((t_content *)aux_node->content)->value == (int)num)
			return (1);
		aux_node = aux_node->next;
	}
	return (0);
}

static	int	numcheckandload(t_list **loading_stack, char *str)
{
	long	num;
	t_list	*new_node;

	num = ft_atol(str);
	if (!isnum(str) || !isint(num) || iscontentdup(loading_stack[0], num))
		return (ft_lstclear(loading_stack, free), 0);
	new_node = ft_lstnew(malloc(sizeof(t_content)));
	((t_content *)new_node->content)->value = (int)num;
	if (!loading_stack[0])
		loading_stack[0] = new_node;
	else
		ft_lstadd_back(loading_stack, new_node);
	return (1);
}

t_list	*load_stack(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*loading_stack;
	char	**split;

	i = 0;
	loading_stack = 0;
	while (i++ < argc -1)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
			if (!numcheckandload(&loading_stack, split[j++]))
				return (free_2d_str(split), (void *)0);
		free_2d_str(split);
	}
	return (loading_stack);
}

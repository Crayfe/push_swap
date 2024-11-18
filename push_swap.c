/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
int	int_arg_checker(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	j = 0;
	while (i++ < argc)
	{
		len = ft_strlen(argv[i]);
		while (j++ < len)
			if(!ft_isdigit(argv[i][j]))
				return (0);
	}
	return (1);
}

t_list	ft_split_int(int argc, char **argv)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;
	if (int_arg_checker(argc, argv))
	{
		stack_a = ft_split_int(argc, argv);
	}
	else
		ft_printf("Error\n");
	return (0);
}

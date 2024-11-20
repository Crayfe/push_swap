/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/20 21:38:07 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
			if(ft_isdigit(s[i]) || (s[i] == '-' && ft_isdigit(s[1])))
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
int	isint(char *s)
{
	long num;

	num = ft_atol(s);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	else
		return (0);
}
int	int_checker(char *arg)
{
	if (!isnum(arg))
		return (0);
	if (!isint(arg))
		return (0);
	return(1);
}
/*
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
*/
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("is %s an int? %i\n", argv[1], int_checker(argv[1]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/03 14:07:44 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static	int	parse_line(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return(swap_a(stack_a), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return(swap_b(stack_b), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return(swap_a_b(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return(push_a(stack_b, stack_a), 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return(push_b(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return(rotate_a(stack_a), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return(rotate_b(stack_b), 1);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		return(rev_rotate_a(stack_a), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return(rev_rotate_b(stack_b), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return(rev_rotate_a_b(stack_a, stack_b), 1);
	else
		return (0);
}

static	void	check_sort(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		valid;

	if (is_stack_sorted(stack_a[0], 0))
	{
		line = get_next_line(0);
		if (ft_strncmp(line, "\n", ft_strlen(line)) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free(line);
	}
	else
	{
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				break ;
			valid = parse_line(stack_a, stack_b, line);
			if (!valid)
				break ;
			if (line)
				free(line);
		}
		if (line)
			free(line);
		if (valid && is_stack_sorted(stack_a[0], 0) && ft_lstsize(stack_b[0]) == 0)
			ft_printf("OK\n");
		else if(!valid)
			ft_printf("Error\n");
		else
			ft_printf("KO\n");
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = 0;
	stack_b = 0;
	if (argc > 1)
	{
		stack_a = load_stack(argc, argv);
		if (!stack_a)
			return (ft_putstr_fd("Error\n", 2), 1);
		else
		{
			check_sort(&stack_a, &stack_b);
			ft_lstclear(&stack_a, free);
			ft_lstclear(&stack_b, free);
		}
	}
	return (0);
}

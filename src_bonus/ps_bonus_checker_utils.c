/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus_checker_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:53:31 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/03 17:34:50 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap_bonus.h"

static	int	parse_line(t_list **stack_a, t_list **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (swap_a(stack_a), 1);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (swap_b(stack_b), 1);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (swap_a_b(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (push_a(stack_b, stack_a), 1);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (push_b(stack_a, stack_b), 1);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (rotate_a(stack_a), 1);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		return (rotate_b(stack_b), 1);
	else if (ft_strncmp(line, "rra\n", 3) == 0)
		return (rev_rotate_a(stack_a), 1);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (rev_rotate_b(stack_b), 1);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (rev_rotate_a_b(stack_a, stack_b), 1);
	else
		return (0);
}

static	void	sorted_case(void)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		ft_printf("OK\n");
	else
	{
		free(line);
		ft_printf("KO\n");
	}
}

void	check_sort(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		valid;

	if (is_stack_sorted(stack_a[0], 0))
		sorted_case();
	else
	{
		while (1)
		{
			line = get_next_line(0);
			if (!line)
				break ;
			valid = parse_line(stack_a, stack_b, line);
			free(line);
			if (!valid)
				break ;
		}
		if (valid && is_stack_sorted(stack_a[0], 0)
			&& ft_lstsize(stack_b[0]) == 0)
			ft_printf("OK\n");
		else if (!valid)
			ft_printf("Error\n");
		else
			ft_printf("KO\n");
	}
}

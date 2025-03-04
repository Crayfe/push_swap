/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/03 17:10:33 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/src/libft.h"
/* In ps_bonus_input_utils.c       */
t_list	*load_stack(int argc, char **argv);
/* In ps_bonus_swap.c:             */
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_bonus_push.c:             */
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
/* In ps_bonus_rotate.c:           */
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_bonus_rev_rotate.c:       */
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b);
/* In ps_bonus_stack_utils.c:      */
int		is_stack_sorted(t_list *stack, int size);
/*In ps_bonus_checker_utils.c        */
void	check_sort(t_list **stack_a, t_list **stack_b);
typedef struct s_content
{
	int	value;
	int	sorted_pos;
}	t_content;

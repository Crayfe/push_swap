/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/18 17:18:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*load_stack(int argc, char **argv);
void	print_stack(t_list *stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_b(t_list **stack_a, t_list **stack_b);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_b(t_list **stack_a, t_list **stack_b);
void	rev_rotate_a(t_list **stack_a);
void	rev_rotate_b(t_list **stack_b);
void	rev_rotate_a_b(t_list **stack_a, t_list **stack_b);

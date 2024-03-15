/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:32:41 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 19:32:44 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	revrotate(t_stack **stack)
{
	t_stack	*begin;
	t_stack	*last;

	if (!(*stack) || (*stack && !(*stack)->next))
		return ;
	begin = *stack;
	last = NULL;
	while (begin->next)
	{
		last = begin;
		begin = begin->next;
	}
	begin->next = *stack;
	*stack = begin;
	last->next = NULL;
}

void	rra(t_stack **stack_a, int i)
{
	revrotate(stack_a);
	if (i == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b, int i)
{
	revrotate(stack_b);
	if (i == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	revrotate(stack_a);
	revrotate(stack_b);
	if (i == 1)
		ft_putstr_fd("rrr\n", 1);
}

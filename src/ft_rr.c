/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:34:16 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 17:34:23 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;

	if (!(*stack) || (*stack && !(*stack)->next))
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
}

void	ra(t_stack **stack_a, int i)
{
	rotate(stack_a);
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b, int i)
{
	rotate(stack_b);
	if (i == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int i)
{
	rotate(stack_a);
	rotate(stack_b);
	if (i == 1)
		ft_putstr_fd("rr\n", 1);
}

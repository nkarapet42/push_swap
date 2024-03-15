/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:51:54 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 13:51:57 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->n;
	stack->n = stack->next->n;
	stack->next->n = temp;
}

void	sa(t_stack *stack_a, int i)
{
	swap(stack_a);
	if (i == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b, int i)
{
	swap(stack_b);
	if (i == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int i)
{
	swap(stack_a);
	swap(stack_b);
	if (i == 1)
		ft_putstr_fd("ss\n", 1);
}

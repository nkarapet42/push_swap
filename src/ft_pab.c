/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:34:07 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 14:34:09 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	push_first(t_stack **first, t_stack **second)
{
	t_stack	*temp;

	if (!second || !first || !(*second))
		return ;
	temp = *second;
	*second = (*second)->next;
	temp->next = *first;
	*first = temp;
}

void	pa(t_stack **first, t_stack **second, int i)
{
	push_first(first, second);
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **first, t_stack **second, int i)
{
	push_first(second, first);
	if (i == 1)
		ft_putstr_fd("pb\n", 1);
}

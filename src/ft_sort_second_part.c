/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_second_part.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:56:01 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/25 16:56:02 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	get_set(int size)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	while (i * i <= size)
	{
		if (i * i * i <= size)
			a = i;
		if (i * i <= size)
			b = i;
		i++;
	}
	return (a + b + 1);
}

int	get_pos(t_stack *lst, int index)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->i == index)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}

void	ft_push_back(t_stack **s_a, t_stack **s_b, int size)
{
	int	i;

	i = size - 1;
	while (*s_b)
	{
		if ((*s_b)->i == i)
		{
			pa(s_a, s_b, 1);
			i--;
			size--;
		}
		else if (get_pos(*s_b, i) >= 1 + size / 2)
			rrb(s_b, 1);
		else if (get_pos(*s_b, i) < 1 + size / 2)
			rb(s_b, 1);
	}
}

void	ft_buterrfly(t_stack **s_a, t_stack **s_b, int size)
{
	int	n;
	int	offset;

	n = 0;
	offset = get_set(size);
	while (*s_a)
	{
		if ((*s_a)->i <= n)
		{
			pb(s_a, s_b, 1);
			rb(s_b, 1);
			n += 1;
		}
		else if ((*s_a)->i <= n + offset)
		{
			pb(s_a, s_b, 1);
			n += 1;
		}
		else
			ra(s_a, 1);
	}
	ft_push_back(s_a, s_b, size);
}

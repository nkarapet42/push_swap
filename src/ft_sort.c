/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:17:36 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/24 12:17:39 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	set_index(t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*cur;

	ptr = *stack_a;
	while (ptr)
	{
		ptr->i = 0;
		ptr = ptr->next;
	}
	cur = *stack_a;
	while (cur)
	{
		ptr = *stack_a;
		while (ptr)
		{
			if (cur->n > ptr->n)
				cur->i += 1;
			ptr = ptr->next;
		}
		cur = cur->next;
	}
}

void	ft_sort_3_nums(t_stack **s)
{
	if ((*s)->n < (*s)->next->n && (*s)->n < (*s)->next->next->n)
	{
		sa(*s, 1);
		ra(s, 1);
	}
	else if ((*s)->n < (*s)->next->n && (*s)->n > (*s)->next->next->n)
		rra(s, 1);
	else if ((*s)->n > (*s)->next->n && (*s)->n < (*s)->next->next->n)
		sa(*s, 1);
	else if ((*s)->n > (*s)->next->n && (*s)->n > (*s)->next->next->n
		&& (*s)->next->n < (*s)->next->next->n)
		ra(s, 1);
	else
	{
		ra(s, 1);
		sa(*s, 1);
	}
}

void	ft_sort_5_nums(t_stack	**stack_a, t_stack **stack_b, int size)
{
	int	i;

	i = 0;
	while (size > 3)
	{
		if (get_pos(*stack_a, i) == 0)
		{
			pb(stack_a, stack_b, 1);
			i++;
			size--;
		}
		else if (get_pos(*stack_a, i) >= 1 + size / 2)
			rra(stack_a, 1);
		else if (get_pos(*stack_a, i) < 1 + size / 2)
			ra(stack_a, 1);
	}
	if (is_sorted(stack_a) == 0)
		ft_sort_3_nums(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}

void	ft_sort(int size, t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a) == 1)
	{
		ft_lstclear(stack_a, free);
		exit (0);
	}
	set_index(stack_a);
	if (size == 2)
		sa(*stack_a, 1);
	else if (size == 3)
		ft_sort_3_nums(stack_a);
	else if (size <= 5)
		ft_sort_5_nums(stack_a, stack_b, size);
	else
		ft_buterrfly(stack_a, stack_b, size);
	ft_lstclear(stack_a, free);
}

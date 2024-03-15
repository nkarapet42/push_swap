/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:32:39 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/23 15:32:40 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	is_sorted(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	if (!temp)
	{
		ft_lstclear(stack_a, free);
		exit(0);
	}
	while (temp && temp->next)
	{
		if (temp->n > temp->next->n)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_checkintenger(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp)
	{
		if (temp->n < INT_MIN || temp->n > INT_MAX)
		{
			ft_lstclear(stack_a, free);
			exit(!write(2, "Error\n", 6));
		}
		temp = temp->next;
	}
}

void	ft_checkdoubles(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tab;
	int		count;

	ft_checkintenger(stack_a);
	temp = *stack_a;
	while (temp->next)
	{
		count = 0;
		tab = *stack_a;
		while (tab)
		{
			if (temp->n == tab->n)
			{
				count++;
				if (count == 2)
				{
					ft_lstclear(stack_a, free);
					exit(!write(2, "Error\n", 6));
				}
			}
			tab = tab->next;
		}
		temp = temp->next;
	}
}

void	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		exit(0);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			exit (!write(2, "Error\n", 6));
		i++;
	}
}

int	countnum(char **s)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] >= '0' && s[i][j] <= '9')
				&& (s[i][j + 1] == ' ' || s[i][j + 1] == '\0'
				|| (s[i][j + 1] >= '\t' && s[i][j + 1] <= '\r')))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

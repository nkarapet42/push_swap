/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:03:26 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/23 15:03:28 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

t_stack	*ft_lstnew(long long num)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (!res)
		return (NULL);
	res->n = num;
	res->next = NULL;
	return (res);
}

void	ft_addstack(t_stack	**stack_a, char **res, t_stack *begin)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		(*stack_a)->next = ft_lstnew(ft_atoi(res[i]));
		if (!(*stack_a))
		{
			ft_lstclear(&begin, free);
			free_res(res, i);
			exit(!write(2, "Error\n", 6));
		}
		*stack_a = (*stack_a)->next;
		free(res[i++]);
	}
}

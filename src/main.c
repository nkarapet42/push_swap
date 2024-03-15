/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:56:01 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 14:56:05 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size;

	check_argv(argc, argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_a->next = NULL;
	stack_b = NULL;
	ft_validation(argv, &stack_a);
	size = countnum(argv);
	ft_sort(size, &stack_a, &stack_b);
	return (0);
}

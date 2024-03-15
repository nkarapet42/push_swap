/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:13:48 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/26 17:13:50 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	do_rotate(t_stack **s_a, t_stack **s_b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		ra(s_a, 0);
	else if (line[1] == 'b' && line[2] == '\n')
		rb(s_b, 0);
	else if (line[1] == 'r' && line[2] == '\n')
		rr(s_a, s_b, 0);
	else if (line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rra(s_a, 0);
	else if (line[1] == 'r' && line[2] == 'b' && line[3] == '\n')
		rrb(s_b, 0);
	else if (line[1] == 'r' && line[2] == 'r' && line[3] == '\n')
		rrr(s_a, s_b, 0);
	else
		return (0);
	return (1);
}

int	do_push(t_stack **s_a, t_stack **s_b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		pa(s_a, s_b, 0);
	else if (line[1] == 'b' && line[2] == '\n')
		pb(s_a, s_b, 0);
	else
		return (0);
	return (1);
}

int	do_swap(t_stack **s_a, t_stack **s_b, char *line)
{
	if (line[1] == 'a' && line[2] == '\n')
		sa(*s_a, 0);
	else if (line[1] == 'b' && line[2] == '\n')
		sb(*s_b, 0);
	else if (line[1] == 's' && line[2] == '\n')
		ss(*s_a, *s_b, 0);
	else
		return (0);
	return (1);
}

int	do_sort(t_stack **s_a, t_stack **s_b)
{
	char	*line;
	int		q;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == 'r')
			q = do_rotate(s_a, s_b, line);
		else if (line[0] == 'p')
			q = do_push(s_a, s_b, line);
		else if (line[0] == 's')
			q = do_swap(s_a, s_b, line);
		else
			q = 0;
		free (line);
		if (q == 0)
			return (0);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	check_argv(argc, argv);
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_a->next = NULL;
	stack_b = NULL;
	ft_validation(argv, &stack_a);
	if (do_sort(&stack_a, &stack_b) == 0)
	{
		ft_lstclear(&stack_a, free);
		return (!write(2, "Error\n", 6));
	}
	if (is_sorted(&stack_a) == 1 && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

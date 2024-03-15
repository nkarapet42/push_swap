/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:35:30 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/23 12:35:32 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_checklen(char **s, int i, int j)
{
	int	len;

	len = 0;
	while (s[i][j] == '0')
		j++;
	while (s[i][j] >= '0' && s[i][j] <= '9')
	{
		len++;
		j++;
	}
	if (len > 11)
		exit(!write(2, "Error\n", 6));
}

void	ft_checkafter(char a, char b)
{
	if ((a >= '0' && a <= '9')
		&& (b == '+' || b == '-'))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	else if ((a == '+' || a == '-')
		&& (b < '0' || b > '9'))
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

void	ft_checkchar(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!((s[i][j] >= '0' && s[i][j] <= '9')
					|| (s[i][j] == ' '
					|| (s[i][j] >= '\t' && s[i][j] <= '\r'))
					|| (s[i][j] == '+' || s[i][j] == '-')))
			{
				ft_putstr_fd("Error\n", 2);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	ft_checknums(char **s)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j] == ' ')
		{
			j++;
			if (s[i][j] == '\0')
				exit(!write(2, "Error\n", 6));
		}
		while (s[i][j])
		{
			if ((s[i][j] >= '0' && s[i][j] <= '9')
				|| (s[i][j] == '+' || s[i][j] == '-'))
			{
				ft_checkafter(s[i][j], s[i][j + 1]);
				ft_checklen(s, i, j);
			}
			j++;
		}
		i++;
	}
}

void	ft_validation(char **src, t_stack **stack_a)
{
	t_stack	*ptr;
	t_stack	*temp;
	char	**res;
	int		i;

	ft_checknums(src);
	ft_checkchar(src);
	i = 1;
	ptr = *stack_a;
	while (src[i])
	{
		res = ft_split(src[i], " \t\n\v\r\f");
		if (!res)
			exit(!write(2, "Error\n", 6));
		ft_addstack(&ptr, res, *stack_a);
		free(res);
		i++;
	}
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	free (temp);
	ft_checkdoubles(stack_a);
}

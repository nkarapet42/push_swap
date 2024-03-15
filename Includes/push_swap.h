/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:34:30 by nkarapet          #+#    #+#             */
/*   Updated: 2024/02/22 13:34:33 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	long long		n;
	int				i;
	struct s_stack	*next;
}	t_stack;

void		swap(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b, int i);
void		sb(t_stack *stack_b, int i);
void		sa(t_stack *stack_a, int i);

void		push_first(t_stack **first, t_stack **second);
void		pa(t_stack **first, t_stack **second, int i);
void		pb(t_stack **first, t_stack **second, int i);

void		rotate(t_stack **stack);
void		rr(t_stack **stack_a, t_stack **stack_b, int i);
void		ra(t_stack **stack_a, int i);
void		rb(t_stack **stack_b, int i);

void		revrotate(t_stack **stack);
void		rrr(t_stack **stack_a, t_stack **stack_b, int i);
void		rra(t_stack **stack_a, int i);
void		rrb(t_stack **stack_b, int i);

void		ft_validation(char **src, t_stack **stack_a);
void		check_argv(int argc, char **argv);
int			countnum(char **s);
void		ft_checkdoubles(t_stack **stack_a);
void		ft_checkintenger(t_stack **stack_a);
void		ft_addstack(t_stack	**stack_a, char **res, t_stack *begin);

void		ft_sort(int size, t_stack **stack_a, t_stack **stack_b);
int			is_sorted(t_stack **stack_a);
void		ft_buterrfly(t_stack **stack_a, t_stack **stack_b, int size);
int			get_pos(t_stack *lst, int index);

void		free_res(char **res, int i);
long long	ft_atoi(const char *str);
char		**ft_split(char const *s, char *c);

void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);

t_stack		*ft_lstnew(long long num);
void		ft_lstclear(t_stack **lst, void (*del)(void*));
void		ft_lstdelone(t_stack *lst, void (*del)(void*));

char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int argument);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(char *src);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarapet <nkarapet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:21:09 by nkarapet          #+#    #+#             */
/*   Updated: 2024/01/11 16:20:22 by nkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	free_res(char **res, int i)
{
	while (i >= 0)
	{
		free(res[i]);
		i--;
	}
	free(res);
	res = NULL;
}

int	ft_ischar(char const s, char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (s == c[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_wordcount(char const *s, char *c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_ischar(s[i], c)
			&& (ft_ischar(s[i + 1], c) || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_getword(char const **s, char *c)
{
	size_t	i;
	size_t	start;
	size_t	j;
	char	*word;

	i = 0;
	while ((*s)[i] != '\0' && ft_ischar((*s)[i], c))
		i++;
	start = i;
	while ((*s)[i] != '\0' && !ft_ischar((*s)[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i - start + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (start < i)
		word[j++] = (*s)[start++];
	word[j] = '\0';
	*s = *s + i;
	return (word);
}

char	**ft_split(char const *s, char *c)
{
	size_t	i;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	len = ft_wordcount(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_getword(&s, c);
		if (!res[i])
			free_res(res, i);
		i++;
	}
	res[i] = NULL;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:32:27 by alosada-          #+#    #+#             */
/*   Updated: 2025/02/21 12:32:29 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*word_dup(const char *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	add_word(char **split, size_t *i, char const **s, char c)
{
	size_t	len;

	len = 0;
	while (**s && **s == c)
		(*s)++;
	if (!**s)
		return (0);
	while ((*s)[len] && (*s)[len] != c)
		len++;
	split[*i] = word_dup(*s, len);
	if (!split[*i])
		return (-1);
	(*s) += len;
	(*i)++;
	return (1);
}

static int	fill_split(char **split, char const *s, char c)
{
	size_t	i;
	int		ret;

	i = 0;
	while (1)
	{
		ret = add_word(split, &i, &s, c);
		if (ret == -1)
		{
			while (i)
				free(split[--i]);
			return (-1);
		}
		if (ret == 0)
			break ;
	}
	split[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	split = ft_calloc(count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	if (fill_split(split, s, c) == -1)
	{
		free(split);
		return (NULL);
	}
	return (split);
}

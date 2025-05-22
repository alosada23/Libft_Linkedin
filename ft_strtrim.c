/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:36:28 by alosada-          #+#    #+#             */
/*   Updated: 2025/02/21 12:36:29 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		start++;
		i++;
	}
	end = ft_strlen(s1);
	i = end;
	while (i > start && ft_strchr(set, s1[i - 1]))
	{
		end--;
		i--;
	}
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}

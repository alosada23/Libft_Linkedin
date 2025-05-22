/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:34:18 by alosada-          #+#    #+#             */
/*   Updated: 2025/02/21 12:34:19 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		iptr;
	char	*joined;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = malloc(len);
	if (!joined)
		return (NULL);
	i = 0;
	iptr = 0;
	while (s1[i])
		joined[iptr++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[iptr++] = s2[i++];
	joined[iptr] = '\0';
	return (joined);
}

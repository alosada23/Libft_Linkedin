/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:34:09 by alosada-          #+#    #+#             */
/*   Updated: 2025/02/21 12:34:10 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(unsigned long n, char *base)
{
	char			*result;
	int				len;
	unsigned long	temp;
	int				base_len;

	base_len = 16;
	len = 1;
	temp = n;
	while (temp >= (unsigned long)base_len)
	{
		temp /= base_len;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len > 0)
	{
		result[--len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}

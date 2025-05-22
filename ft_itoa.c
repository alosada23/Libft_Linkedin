/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <alosada-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:14:01 by alosada-          #+#    #+#             */
/*   Updated: 2025/02/21 12:14:03 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(int n)
{
	int	i;
	int	temp;

	temp = n;
	i = 1;
	if (temp < 0)
	{
		temp = temp * -1;
		i++;
	}
	while (temp >= 10)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*c;
	int			nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nlen(n);
	c = (char *)malloc((sizeof(char)) * (len + 1));
	nb = n;
	if (!c)
		return (NULL);
	c[len--] = '\0';
	if (nb < 0)
	{
		c[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		c[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (c);
}

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

#include "libft.h"

static int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_print_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int	ft_print_uint(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int	ft_print_hex(unsigned int n, char *base)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, base);
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

static int	ft_print_pointer(void *ptr)
{
	char	*str;
	int		len;

	if (!ptr)
		return (ft_print_str("(nil)"));
	ft_putstr_fd("0x", 1);
	str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef");
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}

int	ft_repres_printf(char type, va_list args)
{
	if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (type == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (type == 'p')
		return (ft_print_pointer(va_arg(args, void *)));
	return (0);
}
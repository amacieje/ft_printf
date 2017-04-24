/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:44:50 by amacieje          #+#    #+#             */
/*   Updated: 2017/04/21 11:11:14 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse(va_list *ap, const char *format, int *i, int *printed)
{
	int		j;

	j = *i;
	while (format[++j])
		if ((ft_strchr("#0 +-lhjz123456789.*", format[j])) == NULL)
			break ;
	if (format[j] == 'd' || format[j] == 'i' || format[j] == 'D')
		*printed = *printed + ft_signed_decimal(va_arg(*ap, intmax_t), format, *i, j);
	else if (format[j] == 'o' || format[j] == 'O')
		*printed = *printed + ft_unsigned_octal(va_arg(*ap, uintmax_t), format, *i, j);
	else if (format[j] == 'x' || format[j] == 'X' || format[j] == 'p')
		*printed = *printed + ft_unsigned_hexa(va_arg(*ap, unsigned long long), format, *i, j);
	else if (format[j] == 'u' || format[j] == 'U')
		*printed = *printed + ft_unsigned_decimal(va_arg(*ap, uintmax_t), format, *i, j);
	else if (format[j] == 's' || format[j] == 'S')
		*printed = *printed + ft_string(va_arg(*ap, const char *), format, *i, j);
	else if (format[j] == 'c' || format[j] == 'C')
		*printed = *printed + ft_unsigned_char(va_arg(*ap, unsigned int), format, *i, j);
	else
	{
		write(1, &format[j], 1);
		*printed = *printed + 1;
	}
	*i = j;
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	i = -1;
	printed = 0;
	va_start(ap, format);
	while (format[++i])
		if (format[i] == '%')
			ft_parse(&ap, format, &i, &printed);
		else if (printed > -1)
		{
			write(1, &format[i], 1);
			printed++;
		}
	va_end(ap);
	return (printed);
}

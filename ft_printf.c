/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:44:50 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/08 15:26:27 by amacieje         ###   ########.fr       */
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
		*printed = *printed + ft_signed_decimal(va_arg(*ap, long int), format, *i, j);
//	if (format[j] == 'o' || format[j] == 'O')
//		*printed = *printed + ft_unsigned_octal(va_arg(*ap, long int), format, *i, j);
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
		else
		{
			write(1, &format[i], 1);
			printed++;
		}
	va_end(ap);
	return (printed);
}

int			main()
{
	ft_printf("%-5.3d\n", -1);
	printf("%-5.3d\n", -1);
	return (0);
}

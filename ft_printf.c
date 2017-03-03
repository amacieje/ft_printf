/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:44:50 by amacieje          #+#    #+#             */
/*   Updated: 2017/03/03 15:04:55 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse(va_list *ap, const char *format, int *i, int *printed)
{
	int		j;
	
	j = *i;
//	while (ft_strchr("sSpdDioOuUxXcC%", format[++j]) == NULL)
	while (format[++j])
		if ((ft_strchr("#0 +-lhjz123456789.*", format[j])) == NULL)
			break;
	if (format[j] == 'd' || format[j] == 'i' || format[j] == 'D')
		*printed = *printed + ft_signed_decimal(va_arg(*ap, long int), format, *i, j);
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

int		main()
{
//	printf("%d\n", ft_printf("%%Bla%2d\n", "Shh", "Psst"));
//	printf("%d\n", printf("%%Bla%2d\n", 89));
//	printf("%d\n", ft_printf("❤ ☀ ☆ \n"));
//	printf("%d\n", printf("❤ ☀ ☆ \n"));
//	printf("%d\n", ft_printf("Mon printf : %   l%"));
//	printf("%d\n", printf("Lautprintf : %   l%"));
//	ft_printf("%d\n", 214748364780);
//	printf("%d\n", 214748364780);
//	ft_printf("%6.4d\n", 156);
//	printf("%6.4d\n", 156);
	ft_printf("%-.5d\n", -156);
	printf("%-.5d\n", -156);
	return (0);
}

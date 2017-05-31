/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:44:50 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/31 14:52:23 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_no_conv_format(const char *s, int j, int k)
{
	int		i;
	int		l;
	int		minus;
	char	*width;
	char	*newformat;

	if ((ft_strchr("123456789", s[j])) == NULL || (s[j - 1] == '.'))
		return ((int)write(1, &s[j + 1], 1));
	while ((ft_strchr("0123456789", s[j])) != NULL)
		j--;
	minus = s[j] == '-' ? 1 : 0;
	i = 0;
	l = k + minus + 2 - j++;
	width = (char *)malloc(sizeof(char) * l--);
	width[l--] = '\0';
	width[0] = '%';
	if (minus == 1)
		width[++i] = '-';
	while (++i <= l)
		width[i] = s[j++];
	newformat = ft_strjoin(width, "c");
	free(width);
	return (ft_printf(newformat, s[k + 1]));
}

static void	ft_parse(va_list *ap, const char *format, int *i, int *p)
{
	int		j;

	j = *i;
	while (format[++j])
		if ((ft_strchr("#0 +-lhjz123456789.", format[j])) == NULL)
			break ;
	if (format[j] == 'd' || format[j] == 'i' || format[j] == 'D')
		*p = *p + ft_signed_decimal(va_arg(*ap, intmax_t), format, *i, j);
//	else if (format[j] == 'o' || format[j] == 'O')
//		*p = *p + ft_unsigned_octal(va_arg(*ap, uintmax_t), format, *i, j);
	else if (format[j] == 'x' || format[j] == 'X' || format[j] == 'p')
		*p = *p + ft_unsigned_hexa(va_arg(*ap, unsigned long long),
				format, *i, j);
	else if (format[j] == 'u' || format[j] == 'U')
		*p = *p + ft_unsigned_decimal(va_arg(*ap, uintmax_t), format, *i, j);
	else if (format[j] == 's' || format[j] == 'S')
		*p = *p + ft_string(va_arg(*ap, const char *), format, *i, j);
	else if (format[j] == 'c' || format[j] == 'C')
		*p = *p + ft_unsigned_char(va_arg(*ap, unsigned int), format, *i, j);
	else
		*p = *p + ft_no_conv_format(format, j - 1, j - 1);
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
		if (format[i] == '%' && format[i + 1])
			ft_parse(&ap, format, &i, &printed);
		else if (printed > -1 && format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
		}
	va_end(ap);
	return (printed);
}

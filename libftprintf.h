/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:07:26 by amacieje          #+#    #+#             */
/*   Updated: 2017/05/30 13:30:55 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <locale.h>
# include <wchar.h>

typedef struct		s_flags
{
	int				sharp;
	int				zero;
	int				space;
	int				plus;
	int				minus;
}					t_flags;

typedef struct		s_whole_specifier
{
	int				width;
	int				precision;
	int				i;
	int				j;
}					t_whole_specifier;

typedef struct		s_mask
{
	unsigned int	first;
	unsigned int	second;
	unsigned int	third;
	unsigned int	fourth;
	int				printed;
}					t_mask;

int					ft_printf(const char *restrict format, ...);
char				*ft_uitoa_base(unsigned long long int decimal, int base);
t_flags				*ft_flags_struct(const char *format, int *i, int j);
t_flags				*ft_flags_struct_uo_uh(const char *format,
		int *i, int j);
t_flags				*ft_flags_struct_ud(const char *format, int *i, int j);
t_whole_specifier	*ft_whole_spec_struct(int width, int precision,
		int i, int j);
int					ft_width(const char *format, int *i);
int					ft_precision(const char *format, int *i);
int					ft_signed_decimal(intmax_t li, const char *format,
		int i, int j);
int					ft_unsigned_octal(uintmax_t li, const char *format,
		int i, int j);
int					ft_unsigned_hexa(unsigned long long li, const char *format,
		int i, int j);
int					ft_unsigned_decimal(uintmax_t li, const char *format,
		int i, int j);
int					ft_unsigned_char(unsigned int c, const char *format,
		int i, int j);
int					ft_string(const char *str, const char *format,
		int i, int j);
int					ft_cast_sd(intmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
int					ft_cast_uo(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
int					ft_cast_uh(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
int					ft_cast_ud(uintmax_t li, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
int					ft_cast_uc(unsigned int c, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
int					ft_cast_string(const char *str, t_flags *flags,
		t_whole_specifier *wholespec, const char *format);
void				ft_fill_and_display_sd(char *output, char *li,
		t_flags *flags, t_whole_specifier *wholespec);
void				ft_fill_and_display_uo(char *output, char *li,
		t_flags *flags, t_whole_specifier *wholespec);
void				ft_fill_and_display_uh(char *output, char *li,
		t_flags *flags, t_whole_specifier *wholespec);
void				ft_fill_and_display_ud(char *output, char *li,
		t_flags *flags, t_whole_specifier *wholespec);
void				ft_display_c(int c, t_flags *flags, int printed);
void				ft_display_char(const char *str, char *output,
		t_whole_specifier *wholespec, int minus);

#endif

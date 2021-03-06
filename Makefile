# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amacieje <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/08 15:13:06 by amacieje          #+#    #+#              #
#    Updated: 2017/06/01 13:00:00 by amacieje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARRC = ar rc
SRC = ft_printf.c ft_uitoa_base.c ft_fill_and_display_sd.c ft_fill_and_display_uh.c ft_flags_struct.c ft_flags_struct_uo_uh.c ft_flags_struct_ud.c ft_precision.c ft_signed_decimal.c ft_unsigned_decimal.c ft_unsigned_char.c ft_string.c ft_whole_spec_struct.c ft_width.c ft_cast_sd.c ft_cast_uo.c ft_cast_uh.c ft_cast_ud.c ft_cast_uc.c ft_cast_string.c ft_unsigned_octal.c ft_unsigned_hexa.c ft_fill_and_display_uo.c ft_fill_and_display_ud.c ft_display_c.c ft_display_char.c
SRC2 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_test_strlcat.c ft_sqrt.c ft_div_mod.c ft_print_list.c ft_swap.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_longitoa.c ft_ullitoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c
DSRC = libft/
SRCLIB = $(addprefix $(DSRC), $(SRC2))
PTSO = $(SRC:%.c=%.o)
PTS02 = $(SRC2:%.c=%.o)
PTS03 = $(addprefix $(DSRC), $(PTS02))

all: $(NAME)

$(NAME): $(SRC)
	make -C libft/
	$(CC) $(CFLAGS) -c $? -I $(DSRC)
	$(ARRC) $(NAME) $(PTSO) $(PTS03)
	ranlib $(NAME)

clean:
	make -C libft/ clean
	rm -f $(PTSO) $(PTS02)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re

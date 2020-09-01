# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycameron <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 13:12:03 by ycameron          #+#    #+#              #
#    Updated: 2019/09/22 21:05:37 by ycameron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
SRCS=ft_atoi.c ft_bzero.c ft_isalnum.c \
	 ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	 ft_itoa.c\
	 ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	 ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	 ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
	 ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	 ft_strcpy.c ft_strdel.c \
	 ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
	 ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	 ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	 ft_strrchr.c ft_strstr.c \
	 ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	 ft_ctoi.c ft_islower.c ft_isspaces.c ft_isupper.c ft_strsplit.c \
	 ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	 ft_lstmap.c ft_lstprint.c ft_lstpush_back.c ft_lstpop.c \
	 ft_lstremove_if.c ft_delcontent.c \
	 get_next_line.c ft_itoa_base.c ft_pow.c ft_putwchar.c ft_putwchar_fd.c \
	 ft_putwstr.c ft_putwstr_fd.c ft_ltoa_base.c ft_ltoa.c ft_ultoa.c

OBJECTS = $(SRCS:%.c=%.o)

INCLUDES = ./

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

%.o: %.c libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

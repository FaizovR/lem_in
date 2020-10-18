# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 10:57:07 by nalysann          #+#    #+#              #
#    Updated: 2020/09/01 10:57:10 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.17)
project(libft C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -O2 -march=native -pipe")

include_directories(inc)
include_directories(inc/ft_printf)
include_directories(inc/hidden)

add_library(ft STATIC
        inc/ft_printf/pf_bigint.h
        inc/ft_printf/pf_buffer.h
        inc/ft_printf/pf_handle_asterisk.h
        inc/ft_printf/pf_handle_bigfloat.h
        inc/ft_printf/pf_handle_float.h
        inc/ft_printf/pf_handle_length.h
        inc/ft_printf/pf_handle_placeholder.h
        inc/ft_printf/pf_print_placeholder.h
        inc/ft_printf/pf_read_fields.h
        inc/ft_printf/pf_type_handlers.h
        inc/ft_printf/pf_utils.h
        inc/hidden/hd_get_next_line.h
        inc/hidden/hd_strtol.h
        inc/hidden/hd_strtoll.h
        inc/ft_ctype.h
        inc/ft_error.h
        inc/ft_list.h
        inc/ft_math.h
        inc/ft_stdio.h
        inc/ft_stdlib.h
        inc/ft_string.h
        inc/ft_vector.h
        inc/libft.h
        src/free_split.c
        src/ft_abs.c
        src/ft_atoi.c
        src/ft_atol.c
        src/ft_atoll.c
        src/ft_bzero.c
        src/ft_digittoint.c
        src/ft_fabs.c
        src/ft_fabsf.c
        src/ft_fabsl.c
        src/ft_fmax.c
        src/ft_fmaxf.c
        src/ft_fmaxl.c
        src/ft_fmin.c
        src/ft_fminf.c
        src/ft_fminl.c
        src/ft_isalnum.c
        src/ft_isalpha.c
        src/ft_isascii.c
        src/ft_isblank.c
        src/ft_iscntrl.c
        src/ft_isdigit.c
        src/ft_isgraph.c
        src/ft_islower.c
        src/ft_isprint.c
        src/ft_ispunct.c
        src/ft_isspace.c
        src/ft_isupper.c
        src/ft_isxdigit.c
        src/ft_itoa.c
        src/ft_labs.c
        src/ft_llabs.c
        src/ft_llmax.c
        src/ft_llmin.c
        src/ft_lmax.c
        src/ft_lmin.c
        src/ft_max.c
        src/ft_memalloc.c
        src/ft_memccpy.c
        src/ft_memchr.c
        src/ft_memcmp.c
        src/ft_memcpy.c
        src/ft_memdel.c
        src/ft_memmove.c
        src/ft_mempcpy.c
        src/ft_memset.c
        src/ft_min.c
        src/ft_printf.c
        src/ft_putchar.c
        src/ft_putchar_fd.c
        src/ft_putendl.c
        src/ft_putendl_fd.c
        src/ft_putnbr.c
        src/ft_putnbr_fd.c
        src/ft_putstr.c
        src/ft_putstr_fd.c
        src/ft_strcasecmp.c
        src/ft_strcat.c
        src/ft_strchr.c
        src/ft_strclr.c
        src/ft_strcmp.c
        src/ft_strcpy.c
        src/ft_strdel.c
        src/ft_strdup.c
        src/ft_strequ.c
        src/ft_striter.c
        src/ft_striteri.c
        src/ft_strjoin.c
        src/ft_strlcat.c
        src/ft_strlcpy.c
        src/ft_strlen.c
        src/ft_strmap.c
        src/ft_strmapi.c
        src/ft_strncasecmp.c
        src/ft_strncat.c
        src/ft_strncmp.c
        src/ft_strncpy.c
        src/ft_strndup.c
        src/ft_strnequ.c
        src/ft_strnew.c
        src/ft_strnlen.c
        src/ft_strnstr.c
        src/ft_strrchr.c
        src/ft_strsplit.c
        src/ft_strstr.c
        src/ft_strsub.c
        src/ft_strtol.c
        src/ft_strtoll.c
        src/ft_strtrim.c
        src/ft_swap.c
        src/ft_throw.c
        src/ft_tolower.c
        src/ft_toupper.c
        src/get_next_line.c
        src/list_free.c
        src/list_init.c
        src/list_pop_back.c
        src/list_pop_front.c
        src/list_push_back.c
        src/list_push_front.c
        src/pf_bigint.c
        src/pf_buffer.c
        src/pf_handle_asterisk.c
        src/pf_handle_bigfloat.c
        src/pf_handle_bin.c
        src/pf_handle_char.c
        src/pf_handle_float.c
        src/pf_handle_hex_lower.c
        src/pf_handle_hex_upper.c
        src/pf_handle_invalid.c
        src/pf_handle_length.c
        src/pf_handle_oct.c
        src/pf_handle_percent.c
        src/pf_handle_placeholder.c
        src/pf_handle_pointer.c
        src/pf_handle_rounding.c
        src/pf_handle_signed.c
        src/pf_handle_string.c
        src/pf_handle_unsigned.c
        src/pf_print_placeholder.c
        src/pf_read_fields.c
        src/pf_utils_1.c
        src/pf_utils_2.c
        src/vector_free.c
        src/vector_get.c
        src/vector_init.c
        src/vector_pop_back.c
        src/vector_push_back.c
        src/vector_resize.c
        src/vector_set.c)

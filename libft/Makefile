#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/15 20:31:16 by tstaes-           #+#    #+#              #
#    Updated: 2016/11/30 21:02:30 by tstaes-          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS=-Wall -Werror -Wextra
HEADER = -Ilibft.h
NAME=libft.a
SRC= get_next_line.c ft_realloc.c ft_iscntrl.c ft_isblank.c ft_isspace.c ft_isgraph.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_itoa.c ft_strsplit.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memccpy.c ft_strcat.c ft_strlcat.c ft_strnstr.c ft_memchr.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_memcmp.c ft_strclr.c ft_strmap.c ft_atoi.c ft_memcpy.c ft_strcmp.c ft_strstr.c ft_bzero.c ft_memdel.c ft_strcpy.c ft_strmapi.c ft_strsub.c ft_isalnum.c ft_memmove.c ft_strdel.c ft_strtrim.c ft_isalpha.c ft_memset.c ft_strdup.c ft_strncat.c ft_tolower.c ft_isascii.c ft_putchar.c ft_strequ.c ft_strncmp.c ft_toupper.c ft_isdigit.c ft_putendl.c ft_striter.c ft_strncpy.c ft_isprint.c ft_putnbr.c ft_striteri.c ft_strnequ.c ft_memalloc.c ft_putstr.c ft_strjoin.c ft_strnew.c
OBJ= get_next_line.o ft_realloc.o ft_iscntrl.o ft_isblank.o ft_isspace.o ft_isgraph.o ft_lstmap.o ft_lstiter.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstnew.o ft_itoa.o ft_strsplit.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_memccpy.o ft_strcat.o ft_strlcat.o ft_strnstr.o ft_memchr.o ft_strchr.o ft_strlen.o ft_strrchr.o ft_memcmp.o ft_strclr.o ft_strmap.o ft_atoi.o ft_memcpy.o ft_strcmp.o ft_strstr.o ft_bzero.o ft_memdel.o ft_strcpy.o ft_strmapi.o ft_strsub.o ft_isalnum.o ft_memmove.o ft_strdel.o ft_strtrim.o ft_isalpha.o ft_memset.o ft_strdup.o ft_strncat.o ft_tolower.o ft_isascii.o ft_putchar.o ft_strequ.o ft_strncmp.o ft_toupper.o ft_isdigit.o ft_putendl.o ft_striter.o ft_strncpy.o ft_isprint.o ft_putnbr.o ft_striteri.o ft_strnequ.o ft_memalloc.o ft_putstr.o ft_strjoin.o ft_strnew.o

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HEADER) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

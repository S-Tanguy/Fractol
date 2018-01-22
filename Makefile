#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tstaes- <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/29 17:55:26 by tstaes-           #+#    #+#              #
#    Updated: 2017/04/29 17:55:29 by tstaes-          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
SOURCES = main.c mandel.c color.c julia.c burningship.c init.c keyboard.c mouse.c axone.c toto.c
FLAG = -Wall -Werror -Wextra
LIB = -C ./libft/
LIBNAME = ./libft/libft.a
DEFAULT = "\033[00m"
GREEN = "\033[32m"
SUCCESS = $(GREEN)DONE$(DEFAULT)
OBJECT = $(addprefix $(D_OBJECT), $(SOURCES:.c=.o))
	D_OBJECT = ./object/
	D_SOURCES = ./sources/
all : $(NAME)

object :
		@mkdir -p $(D_OBJECT)

$(D_OBJECT)%.o:$(D_SOURCES)%.c
		@gcc $(FLAG) -I./libft -I/includes -o $@ -c $<
			@echo "Object" [ $(NAME) ] $(SUCCESS)

$(NAME) : object $(OBJECT)
		@make $(LIB)
			@gcc $(FLAG) -o $(NAME) $(OBJECT) -L./libft -lft -lmlx  -framework OpenGL -framework AppKit
				@echo "Compiled" [ $(NAME) ] $(SUCCESS)

clean :
		@make clean $(LIB)
			@echo "Cleaned" [ $(NAME) ] $(SUCCESS)
				@/bin/rm -rf $(D_OBJECT)

fclean : clean
		@rm -rf $(NAME)
			@rm -rf libft/libft.a
				@echo "Fcleaned" [ $(NAME) ] $(SUCCESS)

re : fclean all

.PHONY: all clean fclean re

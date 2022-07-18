# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:59:19 by jecolmou          #+#    #+#              #
#    Updated: 2022/07/18 14:08:20 by jeannecolmo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	philosopher

SRC					=	philosopher.c \
						srcs/parsing.c \
						utils/ft_bzero.c \
						utils/ft_putstr_fd.c\
						utils/ft_strlen.c \
						utils/ft_atoi.c

NAME = philosopher


CC = clang

LINK = clang

CFLAGS = -Wall -Wextra -Werror -Imlx -I. -c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(LINK) $(OBJ) $(LFLAGS) $(OUTPUT_OPTION)

%.o: %.c
	${CC} ${CFLAGS} $< $(OUTPUT_OPTION)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

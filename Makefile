# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 15:59:19 by jecolmou          #+#    #+#              #
#    Updated: 2022/08/03 16:26:17 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	philosopher

SRC					=	philosopher.c \
						srcs/parsing.c \
						srcs/initialisation.c \
						srcs/inside_routine.c \
						srcs/routine.c \
						utils/ft_bzero.c \
						utils/ft_putstr_fd.c\
						utils/ft_strlen.c \
						utils/ft_atoi.c \
						utils/ft_get_time.c \

NAME = philosopher


CC = clang

LINK = clang -pthread

CFLAGS = -Wall -Wextra -Werror -I. -c

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

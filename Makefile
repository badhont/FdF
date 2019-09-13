# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badhont <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 17:23:13 by badhont           #+#    #+#              #
#    Updated: 2018/11/22 16:28:08 by badhont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS =	srcs/main.c \
		srcs/parsing.c \
		srcs/display.c \
		srcs/event.c \
		srcs/drawing.c \

OBJS =	$(SRCS:.c=.o)

INCLUDES = includes/

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
		$(CC) $(CFLAGS) -o $(NAME) libft/libft.a $(OBJS) -I $(INCLUDES) $(MLX)

libft/libft.a :
	make -C libft/

%.o: %.c $(INCLUDES)fdf.h Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJS) && make -C libft/ clean

fclean: clean
	rm -f $(NAME) && make -C libft/ fclean

re: fclean all

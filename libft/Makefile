# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badhont <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 14:47:46 by badhont           #+#    #+#              #
#    Updated: 2018/10/19 21:16:06 by badhont          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		= 	ft_strlen.c \
		 	ft_strdup.c \
		 	ft_strcpy.c \
		 	ft_strncpy.c \
		 	ft_strcmp.c \
		 	ft_strncmp.c \
		 	ft_isalpha.c \
		 	ft_isdigit.c \
		 	ft_isalnum.c \
		 	ft_isascii.c \
		  	ft_isprint.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_atoi.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_bzero.c \
			ft_memset.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strsplit.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_isblank.c \
			ft_countwords.c \
			ft_tablen.c \
			ft_puttab.c \
			ft_min.c \
			ft_max.c \
			ft_abs.c \
			get_next_line.c \
			ft_getnbr.c \
			ft_isnumber.c \

OBJ		=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror




all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) -c $(SRC)
			ar rc $(NAME) $(OBJ)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

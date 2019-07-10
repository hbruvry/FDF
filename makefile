# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 11:28:49 by hbruvry           #+#    #+#              #
#    Updated: 2018/06/12 10:52:55 by hbruvry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		sources/main.c \
			sources/ft_setenv.c \
			sources/ft_getenv.c \
			sources/ft_debug.c \
			sources/ft_drawline.c \
			sources/ft_drawmap.c \
			sources/ft_drawtxt.c \
			sources/ft_mousehook.c \
			sources/ft_keyhook.c \

OBJS =		$(SRCS:.c=.o)

NAME =		fdf

MLX =		-L /usr/X11/lib/ -lmlx -framework OpenGl -framework Appkit

// MLX =		-L /usr/local/lib/ -lmlx -framework OpenGl -framework Appkit

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

LIBFT =		libft

_GREEN =	$ \033[32m
_YELLOW =	$ \033[33m
_RED =		$ \033[31m
_END =		$ \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@gcc $(CFLAGS) -o $(NAME) -I /usr/local/include/ $(OBJS) libft/libft.a $(MLX)
	@echo "$(_GREEN)fdf compiled$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT)
	@rm -f $(OBJS)
	@echo "libft cleaned"
	@echo "fdf cleaned"

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "fdf fcleaned"

re: fclean all

.PHONY: libft clean fclean all re

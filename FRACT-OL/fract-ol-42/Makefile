# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbaazzy <mbaazzy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 20:34:02 by mbaazzy           #+#    #+#              #
#    Updated: 2022/02/20 17:22:12 by mbaazzy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c utils.c hook_hundle.c mandelbrot.c fractol.c julia.c my_mlx_pixel_put.c Burning_Ship.c
OBJS = $(SRCS:.c=.o)
NAME = fractol
HEADER = fract.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAG = -lm -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(MLX_FLAG) $(FLAGS) $(OBJS) -o $(NAME)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $<
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
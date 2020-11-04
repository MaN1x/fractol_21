# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoss <mjoss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 16:57:36 by mjoss             #+#    #+#              #
#    Updated: 2020/11/02 22:05:31 by mjoss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Werror -Wall -Wextra -O3

OBJ_DIR = obj/
SRC_DIR = src/

INCLUDES_DIR = includes
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)includes -I$(INCLUDES_DIR)

MLX_DIR = minilibx_macos/
LIB_MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = libft/
LIBFT_NAME = libft.a
LIBFT = -L $(LIBFT_DIR) -lft

SRC_FILES = main.c                  \
            draw_fractal.c          \
            fractal_color.c         \
            failure.c               \
            hooks.c                 \
            init.c                  \
            julia.c                 \
            mandelbrot.c            \
            mandelbrot4.c           \
            put_pixel_to_image.c    \
            close.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIB_MLX) $(LIBFT)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCLUDES_DIR)/fractol.h $(INCLUDES_DIR)/keymap.h
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIBFT_DIR)$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all fclean clean re

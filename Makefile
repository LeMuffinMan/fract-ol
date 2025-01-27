# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 18:04:39 by oelleaum          #+#    #+#              #
#    Updated: 2025/01/16 18:04:42 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Werror -Wextra -Wall -g3
SRC = src/main.c src/maths.c src/kb_inputs.c src/init.c src/render_fractal.c src/color.c src/check_input.c src/mouse_inputs.c src/wheel_zoom.c src/animations.c src/animations_utils.c src/wheel_combo.c src/switch_palette.c src/check_inputs_utils.c src/init_utils_1.c src/init_utils_2.c src/color_switch.c src/kb_switch.c src/kb_pav_num.c src/kb_julia.c src/kb_animations.c src/calculate_fractal.c
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_SRC = $(wildcard $(MLX_DIR)/*.c)
MLX_OBJ = $(MLX_SRC:.c=.o)
MLX_FLAGS = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX) -lm

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

$(MLX): $(MLX_SRC)
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c Makefile ./include/fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -I $(MLX_DIR) -c $< -o $@

clean: 
	@rm -rf $(OBJS_PATH) $(OBJS)
	@make clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME) $(MLX_NAME)

re: fclean all

debug: 
	@echo $(OBJS)


.PHONY: all re clean fclean


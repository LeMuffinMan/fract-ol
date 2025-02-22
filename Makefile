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
BONUS_NAME = fractol_bonus

CC = cc
# verifier les leeeeeeaks et virer le flag valgrind 
# flag -Weverything peut me donner plus d'infos
CFLAGS = -Werror -Wextra -Wall -O3 -g3
INC = -I includes
INC_LIBFT = -I libft/include
INC_BONUS = -I bonus/include

SRC_DIR = src
OBJ_DIR = obj

LIBFT_SRC_DIR = libft/src
LIBFT_OBJ_DIR = libft/obj
BONUS_SRC_DIR = bonus/src
BONUS_OBJ_DIR = bonus/obj

# variable src_dir
SRC_FILES = src/main.c \
			src/check_input.c \
			src/init.c \
			src/render_fractal.c \
			src/inputs.c \
			src/check_inputs_utils.c 

# mettre la variable LIBFT_SRC_DIR a la place 
LIBFT_SRC_FILES = \
    libft/src/ft_atoi.c \
    libft/src/ft_bzero.c \
    libft/src/ft_calloc.c \
    libft/src/ft_isalnum.c \
    libft/src/ft_isalpha.c \
    libft/src/ft_isascii.c \
    libft/src/ft_isdigit.c \
    libft/src/ft_isprint.c \
    libft/src/ft_itoa.c \
    libft/src/ft_lstadd_back_bonus.c \
    libft/src/ft_lstadd_front_bonus.c \
    libft/src/ft_lstclear_bonus.c \
    libft/src/ft_lstdelone_bonus.c \
    libft/src/ft_lstiter_bonus.c \
    libft/src/ft_lstlast_bonus.c \
    libft/src/ft_lstnew_bonus.c \
    libft/src/ft_lstsize_bonus.c \
    libft/src/ft_memchr.c \
    libft/src/ft_memcmp.c \
    libft/src/ft_memcpy.c \
    libft/src/ft_memmove.c \
    libft/src/ft_memset.c \
    libft/src/ft_putchar_fd.c \
    libft/src/ft_putendl_fd.c \
    libft/src/ft_putnbr_fd.c \
    libft/src/ft_putstr_fd.c \
    libft/src/ft_split.c \
    libft/src/ft_strdup.c \
    libft/src/ft_strchr.c \
    libft/src/ft_striteri.c \
    libft/src/ft_strjoin.c \
    libft/src/ft_strlcat.c \
    libft/src/ft_strlcpy.c \
    libft/src/ft_strmapi.c \
    libft/src/ft_strnstr.c \
    libft/src/ft_strrchr.c \
    libft/src/ft_strtrim.c \
    libft/src/ft_substr.c \
    libft/src/ft_strlen.c \
    libft/src/ft_strncmp.c \
    libft/src/ft_tolower.c \
    libft/src/ft_toupper.c \
    libft/src/ft_split.c \
    libft/src/get_next_line.c \
    libft/src/get_next_line_utils.c

LIBFT_OBJ_FILES = $(LIBFT_SRC_FILES:.c=.o)

# variable src bonus
BONUS_SRC_FILES = \
    bonus/src_bonus/calculate_fractal_bonus.c \
    bonus/src_bonus/maths_bonus.c \
    bonus/src_bonus/main_bonus.c \
    bonus/src_bonus/render_fractal_bonus.c \
    bonus/src_bonus/animations_bonus/animations_utils_bonus.c \
    bonus/src_bonus/animations_bonus/animations_bonus.c \
    bonus/src_bonus/check_input_bonus/check_input_bonus.c \
    bonus/src_bonus/check_input_bonus/check_input_utils_bonus.c \
    bonus/src_bonus/color_bonus/color_bonus.c \
    bonus/src_bonus/color_bonus/color_switch_bonus.c \
    bonus/src_bonus/color_bonus/switch_palette_bonus.c \
    bonus/src_bonus/init_bonus/init_bonus.c \
    bonus/src_bonus/init_bonus/init_palette_bonus.c \
    bonus/src_bonus/init_bonus/init_utils_1_bonus.c \
    bonus/src_bonus/init_bonus/init_utils_2_bonus.c \
    bonus/src_bonus/kb_inputs_bonus/kb_animations_bonus.c \
    bonus/src_bonus/kb_inputs_bonus/kb_inputs_bonus.c \
    bonus/src_bonus/kb_inputs_bonus/kb_julia_bonus.c \
    bonus/src_bonus/kb_inputs_bonus/kb_pav_num_bonus.c \
    bonus/src_bonus/kb_inputs_bonus/kb_switch_bonus.c \
    bonus/src_bonus/mouse_inputs_bonus/mouse_inputs_bonus.c \
    bonus/src_bonus/mouse_inputs_bonus/wheel_combo_bonus.c \
    bonus/src_bonus/mouse_inputs_bonus/wheel_zoom_bonus.c 

BONUS_OBJ_FILES = $(addprefix $(BONUS_OBJ_DIR)/, $(subst bonus/src_bonus/, , $(BONUS_SRC_FILES:.c=.o)))

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))
BONUS = $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_OBJ_FILES))

LIBFT_A = libft/libft.a

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_SRC = 	$(MLX_DIR)/mlx_int_param_event.c \
			$(MLX_DIR)/mlx_int_set_win_event_mask.c \
	        $(MLX_DIR)/mlx_int_str_to_wordtab.c \
            $(MLX_DIR)/mlx_int_wait_first_expose.c \
            $(MLX_DIR)/mlx_key_hook.c \
            $(MLX_DIR)/mlx_lib_xpm.c \
            $(MLX_DIR)/mlx_loop.c \
            $(MLX_DIR)/mlx_loop_hook.c \
			$(MLX_DIR)/mlx_clear_window.c \
			$(MLX_DIR)/mlx_mouse.c \
			$(MLX_DIR)/mlx_destroy_display.c \
			$(MLX_DIR)/mlx_mouse_hook.c \
			$(MLX_DIR)/mlx_destroy_image.c \
			$(MLX_DIR)/mlx_new_image.c \
			$(MLX_DIR)/mlx_destroy_window.c \
			$(MLX_DIR)/mlx_new_window.c \
			$(MLX_DIR)/mlx_expose_hook.c \
			$(MLX_DIR)/mlx_pixel_put.c \
			$(MLX_DIR)/mlx_ext_randr.c \
			$(MLX_DIR)/mlx_put_image_to_window.c \
			$(MLX_DIR)/mlx_flush_event.c \
			$(MLX_DIR)/mlx_rgb.c \
			$(MLX_DIR)/mlx_get_color_value.c \
			$(MLX_DIR)/mlx_screen_size.c \
			$(MLX_DIR)/mlx_get_data_addr.c \
			$(MLX_DIR)/mlx_set_font.c \
			$(MLX_DIR)/mlx_string_put.c \
			$(MLX_DIR)/mlx_hook.c \
			$(MLX_DIR)/mlx_xpm.c \
			$(MLX_DIR)/mlx_init.c \
			$(MLX_DIR)/mlx_int_anti_resize_win.c \
			$(MLX_DIR)/mlx_int_do_nothing.c \
			$(MLX_DIR)/mlx_int_get_visual.c

MLX_OBJ = $(MLX_SRC:.c=.o)
MLX_FLAGS = -L $(MLX_DIR) -lmlx_Linux -L/usr/lib -I $(MLX_DIR) -lX11 -lm -lz -lXext $(MLX) 

GREEN=\033[32m
RED=\033[31m
RESET=\033[0m

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT_A) Makefile libft/Makefile libft/include/libft.h
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_A) $(LIBFT_FLAGS) -o $(NAME)
	@echo 
	@echo "$(GREEN)compilation successful ✅ $(NAME)$(RESET)"
	@echo 

$(LIBFT_A): $(LIBFT_SRC_FILES) FORCE
	@$(MAKE) --no-print-directory -C libft

$(MLX): $(MLX_SRC)
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: %.c Makefile ./include/fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -I . -I $(MLX_DIR) -c $< -o $@


bonus: $(BONUS_NAME)

$(BONUS_OBJ_DIR)/%.o: bonus/src_bonus/%.c ./bonus/include_bonus/fractol_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

$(BONUS_NAME): $(BONUS_OBJ_FILES) $(LIBFT_A) Makefile libft/Makefile ./bonus/include_bonus/fractol_bonus.h
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) $(LIBFT_A) $(LIBFT_FLAGS) $(MLX_FLAGS)-o $(BONUS_NAME)
	@echo
	@echo "$(GREEN)compilation successful ✅ $(BONUS_NAME)$(RESET)"
	@echo

clean:
	rm -rf $(OBJ_DIR)/*

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	rm -f $(LIBFT_A)

re: fclean all

FORCE:
.PHONY: all re clean fclean bonus


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:52:25 by oelleaum          #+#    #+#              #
#    Updated: 2025/02/15 15:06:56 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=cc
FLAGS=-Wall -Werror -Wextra
INC= -I include
SRC_DIR=src
INC_DIR=include
OBJ_DIR=obj

RM=rm -f

SRC_FILES=ft_atoi.c\
	ft_bzero.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putnbr_fd.c\
	ft_strjoin.c\
	ft_split.c\
	ft_itoa.c\
	ft_substr.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_putendl_fd.c\
	ft_striteri.c \
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\
	get_next_line.c\
	get_next_line_utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

GREEN=\033[32m
RED=\033[31m
RESET=\033[0m

all: $(NAME)

# Créer la bibliothèque .a
$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	@echo 
	@echo "$(GREEN)compilation successful ✅ $(NAME) $(RESET)"
	@echo 

# Compilations des fichiers .o à partir des fichiers .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/libft.h Makefile
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

# Suppression des fichiers objets
clean:
	$(RM) $(OBJ)

# Suppression des fichiers objets et de la bibliothèque
fclean: clean
	$(RM) $(NAME)

# Rebuild complet (nettoyage + compilation)
re: fclean all

.DEFAULT_GOAL = all
.PHONY: all clean fclean re


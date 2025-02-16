# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelleaum <oelleaum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:52:25 by oelleaum          #+#    #+#              #
#    Updated: 2025/02/15 14:49:57 by oelleaum         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS=-Wall -Werror -Wextra
RM=rm -f
SRC=ft_atoi.c\
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
	ft_striteri.c\
	get_next_line.c\
	get_next_line_utils.c

BONUS=ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c
ALL_SRC=$(SRC) $(BONUS)		
OBJS=$(SRC:.c=.o)
ALL_OBJ=$(ALL_SRC:.c=.o)
NAME=libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):$(OBJS)
		ar -rcs $(NAME) $(OBJS)


bonus : $(ALL_OBJ)
		ar -rcs $(NAME) $(ALL_OBJ)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

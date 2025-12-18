# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzafra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 18:08:50 by dzafra            #+#    #+#              #
#    Updated: 2025/12/11 22:44:55 by dzafra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
SRC_DIR     = .
SRC         = $(SRC_DIR)/ft_isalpha.c \
	      $(SRC_DIR)/ft_isdigit.c \
	      $(SRC_DIR)/ft_isalnum.c \
	      $(SRC_DIR)/ft_isascii.c \
	      $(SRC_DIR)/ft_isprint.c
OBJ         = $(SRC:.c=.o)
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

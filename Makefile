# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzafra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 18:08:50 by dzafra            #+#    #+#              #
#    Updated: 2025/12/23 20:00:04 by dzafra           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
SRC_DIR     = .
SRC         = $(SRC_DIR)/ft_isalpha.c \
	      	$(SRC_DIR)/ft_split.c \
		$(SRC_DIR)/ft_isalnum.c \
		$(SRC_DIR)/ft_isalpha.c \
		$(SRC_DIR)/ft_isascii.c \
		$(SRC_DIR)/ft_isdigit.c \
		$(SRC_DIR)/ft_isprint.c \
		$(SRC_DIR)/ft_strlcpy.c \
		$(SRC_DIR)/ft_strlcat.c \
		$(SRC_DIR)/ft_strnstr.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_lstdelone.c \
		$(SRC_DIR)/ft_lstlast.c \
		$(SRC_DIR)/ft_lstmap.c \
		$(SRC_DIR)/ft_lstsize.c \
		$(SRC_DIR)/ft_strjoin.c \
		$(SRC_DIR)/ft_strmapi.c \
		$(SRC_DIR)/ft_strchr.c \
		$(SRC_DIR)/ft_striteri.c \
		$(SRC_DIR)/ft_strdup.c \
		$(SRC_DIR)/ft_substr.c \
		$(SRC_DIR)/ft_strtrim.c \
		$(SRC_DIR)/ft_strrchr.c \
		$(SRC_DIR)/ft_atoi.c \
		$(SRC_DIR)/ft_bzero.c \
		$(SRC_DIR)/ft_memchr.c \
		$(SRC_DIR)/ft_memcmp.c \
		$(SRC_DIR)/ft_memcpy.c \
		$(SRC_DIR)/ft_memmove.c \
		$(SRC_DIR)/ft_memset.c \
		$(SRC_DIR)/ft_strlen.c \
		$(SRC_DIR)/ft_strncmp.c \
		$(SRC_DIR)/ft_tolower.c \
		$(SRC_DIR)/ft_toupper.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putendl_fd.c \
		$(SRC_DIR)/ft_lstaddback.c \
		$(SRC_DIR)/ft_lstaddfront.c \
		$(SRC_DIR)/ft_lstclear.c \
		$(SRC_DIR)/ft_lstiter.c \
		$(SRC_DIR)/ft_lstnew.c \
		$(SRC_DIR)/ft_calloc.c \
		$(SRC_DIR)/ft_itoa.c

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

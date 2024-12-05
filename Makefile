# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 20:55:36 by dimachad          #+#    #+#              #
#    Updated: 2024/12/05 01:49:30 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c \
    ft_isprint.c \
    ft_strlen.c \
    ft_bzero.c \
    ft_memcpy.c \
    ft_isalnum.c \
    ft_memmove.c \
    ft_isalpha.c \
    ft_memset.c \
    ft_isascii.c \
    ft_strlcat.c \
    ft_isdigit.c \
    ft_strlcpy.c \
    ft_strlcat.c \
    ft_toupper.c \
    ft_tolower.c \
    ft_strchr.c \
    ft_strncmp.c \
    ft_memcmp.c \
    ft_strnstr.c \
	ft_memchr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_substr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \

OBJS := $(SRC:%.c=%.o)

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
AR = ar
ARFLAGS = rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 20:55:36 by dimachad          #+#    #+#              #
#    Updated: 2024/11/20 21:15:55 by dimachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addsuffix .c, main ft_isprint ft_strlen ft_bzero ft_memcpy ft_isalnum ft_memmove ft_isalpha ft_memset ft_isascii ft_strlcat ft_isdigit ft_strlcpy)
OBJS := $(SRC:%.c=%.0)
# BONUS_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, ft_lstnew))
# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft
CC = cc
CCFLAGS = -Wall -Extra -Werror
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
OBJS_BASBO = $(OBJS) # $(BONUS_OBJS)
# OBJS_ALL = $(OBJS_BASBO) $(SUPP_OBJS)
RM = rm -f

all: $(NAME)
	${CC} ${FLAGS} $^ -o $@	

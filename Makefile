# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dimachad <dimachad@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 20:55:36 by dimachad          #+#    #+#              #
#    Updated: 2024/11/22 23:14:13 by dimachad         ###   ########.fr        #
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
      ft_strlcpy.c

OBJS := $(SRC:%.c=%.o)

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re



SRC = $(addsuffix .c, main ft_isprint ft_strlen ft_bzero ft_memcpy ft_isalnum ft_memmove ft_isalpha ft_memset ft_isascii ft_strlcat ft_isdigit ft_strlcpy)
OBJS := $(SRC:%.c=%.o)
# BONUS_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, ft_lstnew))
# BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

NAME = libft.a
CC = cc
CCFLAGS = -Wall -Wextra -Werror
INC_DIR = .
CPPFLAGS = -I$(INC_DIR)
OBJS_BASBO = $(OBJS) # $(BONUS_OBJS)
# OBJS_ALL = $(OBJS_BASBO) $(SUPP_OBJS)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CCFLAGS} $^ -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_ALL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS_BASBO)
	$(CC) $(CCFLAGS) $? -o $(NAME)

everything: $(OBJS_ALL)
	$(CC) $(CCFLAGS) $? -o $(NAME)

.PHONY: all clean fclean re bonus everything


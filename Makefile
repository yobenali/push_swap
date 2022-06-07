# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yobenali <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 00:05:29 by yobenali          #+#    #+#              #
#    Updated: 2022/05/31 00:05:53 by yobenali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker
SRC = src/ft_atoi.c \
	src/ft_bzero.c \
	src/ft_calloc.c \
	src/ft_instructions.c \
	src/ft_instructions2.c \
	src/ft_memset.c \
	src/ft_small_sort.c \
	src/ft_sort_int_tab.c \
	src/ft_split.c \
	src/ft_strdup.c \
	src/ft_strjoin.c \
	src/ft_strlcpy.c \
	src/ft_utils.c \
	push_swap.c	\

B_SRCS = src_bonus/ft_atoi_bonus.c \
		src_bonus/ft_bzero_bonus.c \
		src_bonus/ft_calloc_bonus.c \
		src_bonus/ft_instructions_bonus.c \
		src_bonus/ft_instructions2_bonus.c \
		src_bonus/ft_memset_bonus.c \
		src_bonus/ft_small_sort_bonus.c \
		src_bonus/ft_sort_int_tab_bonus.c \
		src_bonus/ft_split_bonus.c \
		src_bonus/ft_strdup_bonus.c \
		src_bonus/ft_strjoin_bonus.c \
		src_bonus/ft_strlcpy_bonus.c \
		src_bonus/ft_utils_bonus.c \
		src_bonus/ft_help.c \
		gnl_ps/get_next_line.c \
		gnl_ps/get_next_line_utils.c \
		checker.c \

CC = cc
FLAGS = -Wall -Wextra -Werror
$(NAME) :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
$(B_NAME) :
	$(CC) $(FLAGS) $(B_SRCS) -o $(B_NAME)
all : $(NAME)
bonus : $(B_NAME)
clean :
	rm -f $(NAME)
	rm -f $(B_NAME)
fclean : clean
	rm -f $(NAME)
	rm -f $(B_NAME)
re : clean fclean all

.PHONY : all clean fclean re
:
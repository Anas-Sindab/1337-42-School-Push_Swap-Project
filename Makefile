# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 20:19:39 by anasinda          #+#    #+#              #
#    Updated: 2026/01/05 17:50:20 by anasinda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
NAME = push_swap
CHECKER_PROGRAM = checker

SRCS_FT_PRINTF = src/ft_printf_files/ft_printf.c src/ft_printf_files/ptr_check_ft_printf.c src/ft_printf_files/putchar_ft_printf.c src/ft_printf_files/puthex_ft_printf.c src/ft_printf_files/putnbr_ft_printf.c src/ft_printf_files/putptr_ft_printf.c src/ft_printf_files/putsigned_ft_printf.c src/ft_printf_files/putstr_ft_printf.c
SRCS_HELPER_FUNCTIONS = src/helper_functions/ft_atoi.c src/helper_functions/ft_split.c src/helper_functions/ft_strdup.c src/helper_functions/ft_strlen.c src/helper_functions/ft_substr.c src/helper_functions/ft_append.c src/helper_functions/ft_strchr.c
SRCS_PUSH_SWAP_FILES = src/push_swap_files/push_swap_index_nodes.c src/push_swap_files/push_swap_moves.c src/push_swap_files/push_swap_nodes.c src/push_swap_files/push_swap_small_sorts.c src/push_swap_files/push_swap_algo_count_moves.c src/push_swap_files/push_swap_algo_set_targets.c src/push_swap_files/push_swap_algo_start_moves.c src/push_swap_files/push_swap_algo_entry.c src/push_swap_files/push_swap_parser.c src/push_swap_files/push_swap_more_moves.c src/push_swap_files/push_swap_dup_check_build_stack.c src/push_swap_files/push_swap.c
SRCS_BONUS = src/push_swap_files/push_swap_dup_check_build_stack.c src/push_swap_files/push_swap_parser.c src/push_swap_files/push_swap_index_nodes.c src/push_swap_files/push_swap_more_moves.c src/push_swap_files/push_swap_moves.c src/push_swap_files/push_swap_nodes.c bonus/checker_program.c  bonus/get_next_line.c

OBJS_FT_PRINTF = $(SRCS_FT_PRINTF:.c=.o)
OBJS_HELPER_FUNCTIONS = $(SRCS_HELPER_FUNCTIONS:.c=.o)
OBJS_PUSH_SWAP_FILES = $(SRCS_PUSH_SWAP_FILES:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(CHECKER_PROGRAM)

$(CHECKER_PROGRAM): $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_BONUS) -o $(CHECKER_PROGRAM)

$(NAME): $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_PUSH_SWAP_FILES)
	$(CC) $(CFLAGS) $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_PUSH_SWAP_FILES) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_PUSH_SWAP_FILES) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re
.SECONDARY: $(OBJS_FT_PRINTF) $(OBJS_HELPER_FUNCTIONS) $(OBJS_PUSH_SWAP_FILES)


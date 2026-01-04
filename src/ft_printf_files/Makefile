# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anasinda <anasinda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 11:18:32 by anasinda          #+#    #+#              #
#    Updated: 2025/12/21 17:34:23 by anasinda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c putstr_ft_printf.c putsigned_ft_printf.c putptr_ft_printf.c putnbr_ft_printf.c puthex_ft_printf.c putchar_ft_printf.c ptr_check_ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	@echo "---> Making object files! <---"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "\n"

clean:
	@echo "---> Removing object files ^__^ <---"
	$(RM) $(OBJS)
	@echo "\n"

fclean: clean
	@echo "---> Removing EVERYTHING o__o <---"
	$(RM) $(NAME)
	@echo "\n"

re: fclean all
	@echo "---> Removed EVERYTHING and created from SCRATCH :D <---"
	@echo "\n"

.PHONY: clean fclean re

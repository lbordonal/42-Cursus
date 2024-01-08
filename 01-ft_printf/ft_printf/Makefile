# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 11:42:19 by lbordona          #+#    #+#              #
#    Updated: 2022/11/22 15:16:27 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables:
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

#Sources:
SRC = ft_printf.c ft_printf_utils.c libft_functions.c \
	ft_args_csp.c ft_args_diu.c ft_args_xXpercent.c
#BONUS = *.c

OBJ = $(SRC:%.c=%.o)
#BONUS_OBJ = $(BONUS:%.c=%.o)

#Rules:
all: $(NAME)

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

clean:
		@$(RM) $(OBJ)


fclean: clean
		@$(RM) $(NAME)

re: fclean all

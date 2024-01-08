# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 17:25:18 by lbordona          #+#    #+#              #
#    Updated: 2023/04/04 15:46:44 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT = ./libft/libft.a

NAME = push_swap

SRCS = srcs/push_swap.c \
	srcs/utils.c \
	srcs/operation_swap.c \
	srcs/operation_rotate.c \
	srcs/operation_push.c \
	srcs/operation_rerotate.c \
	srcs/sort_utils_1.c \
	srcs/sort_utils_2.c \
	srcs/sort_small.c \
	srcs/sort_big.c \
	srcs/errors.c

OBJS = $(SRCS:%.c=%.o)

#Rules:
all: $(NAME)
$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

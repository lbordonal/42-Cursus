# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbordona <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 21:21:31 by lbordona          #+#    #+#              #
#    Updated: 2024/01/18 01:59:54 by lbordona         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=address
RM = rm -rf

NAME = philo

SRCS = srcs/main.c \
	srcs/libft_functions.c \
	srcs/starts.c \
	srcs/threads.c \
	srcs/time.c \
	srcs/routine.c \
	srcs/actions.c \
	srcs/checker.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:

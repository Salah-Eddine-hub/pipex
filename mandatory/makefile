# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 12:21:18 by sharrach          #+#    #+#              #
#    Updated: 2022/10/13 14:35:43 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

HEADER	=	pipex.h

SRCS	=	main.c\
			pipex.c\
			utils_1.c\
			utils_2.c\
			free_2d.c\
			ft_strlen.c\
			get_command.c\
			error_cases.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME)	:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
				$(RM) $(NAME) $(OBJS)

re		:	fclean all

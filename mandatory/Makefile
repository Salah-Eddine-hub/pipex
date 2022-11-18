# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sharrach <sharrach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 12:21:18 by sharrach          #+#    #+#              #
#    Updated: 2022/11/16 18:32:51 by sharrach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

HEADER	=	includes/pipex.h\
			
HEADER_BONUS =	includes/pipex_bonus.h

SRCS	=	main.c\
			srcs/pipex.c\
			utils/utils.c\
			utils/utils_1.c\
			utils/utils_2.c\
			utils/get_next_line.c\
			utils/get_next_line_utils.c\
			srcs/get_command.c\
			srcs/error_cases.c

SRCS_BONUS	=	main_bonus.c\
				utils/utils.c\
				utils/utils_1.c\
				utils/utils_2.c\
				utils/get_next_line.c\
				utils/get_next_line_utils.c\
				srcs_bonus/pipex_bonus.c\
				srcs_bonus/get_command_bonus.c\
				srcs_bonus/error_bonus.c

OBJS	=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

$(NAME)	:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus	:	$(OBJS_BONUS) $(HEADER_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME)

all		:	$(NAME)

clean	:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all

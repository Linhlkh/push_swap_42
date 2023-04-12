# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khle <khle@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 03:15:51 by khle              #+#    #+#              #
#    Updated: 2023/04/09 00:54:58 by khle             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -g3 -Wall -Werror -Wextra -MMD

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES	=	parsing/exit.c \
				parsing/parsing.c \
				utils/utils_lst.c \
				utils/utils_sujet1.c \
				utils/utils_sujet2.c \
				utils/utils.c \
				push_swap/algo.c \
				push_swap/big_sort.c \
				push_swap/push_swap.c \
				push_swap/utils_sort.c \
				push_swap/small_sort.c

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

DEPS			=	${SRCS_NAMES:.c=.d}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

INC				=	-Iincludes

CC				=	cc

CDFLAGS 		=	-MMD -MP

CFLAGS			=	-g3 -Wall -Werror -Wextra

all:	${NAME}

$(NAME): $(DIR_OBJS) $(OBJS) 
	$(CC) -g3 ${INC} $(OBJS) -o $(NAME)

$(OBJS) : $(DIR_OBJS)/%.o : $(DIR_SRCS)/%.c
	$(CC) -g3 $(CDFLAGS) $(INC) -c $< -o $@ 

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/parsing
	mkdir -p objs/push_swap
	mkdir -p objs/utils

clean:
	rm -rf ${DIR_OBJS}

fclean:	clean
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re bonus leaks stop
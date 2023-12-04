# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 14:22:06 by bebrandt          #+#    #+#              #
#    Updated: 2023/12/04 07:21:01 by bebrandt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	solve_day

SRCS	=	day-01.c day-02.c day-03.c day-04.c day-05.c day-06.c day-07.c \
				day-08.c day-09.c day-10.c day-11.c day-12.c day-13.c day-14.c \
				day-15.c day-16.c day-17.c day-18.c day-18.c day-19.c day-20.c \
				day-21.c day-22.c day-23.c day-24.c day-25.c \
				get_input_to_struct.c get_input_to_array.c safe_free.c error.c \
				display.c daily-utils.c day-03-utils.c day-03-lst.c day-04-utils.c

OBJS		:=	$(SRCS:.c=.o)

LIB_AOC		=	aoc.a

PRINTF_DIR		=	printf

PRINTF_NAME		=	libftprintf.a

HDRS		=	-I .

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

AR			=	ar rcs

RM			=	rm -f

all: libft $(NAME)

%.o:	%.c
	$(CC) $(HDRS) $(CFLAGS) -c $< -o $@

$(NAME):	main.c $(OBJS) $(LIB_AOC)
	$(CC) $(HDRS) $(CFLAGS) main.c -L . $(LIB_AOC) -g -o $(NAME)

libft:
	$(MAKE) -C $(PRINTF_DIR)
	cp $(PRINTF_DIR)/$(PRINTF_NAME) $(LIB_AOC)

$(LIB_AOC): $(OBJS)
	$(AR) $(LIB_AOC) $^

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)
	$(RM) main.o
	$(RM) $(LIB_AOC)

fclean:	clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all libft clean fclean re

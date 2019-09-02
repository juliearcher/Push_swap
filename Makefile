# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/08/05 06:16:06 by jarcher      #+#   ##    ##    #+#        #
#    Updated: 2019/09/02 11:00:38 by jarcher     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAMELIB= libft/libft.a
NAMECHECKER= checker
NAME= push_swap

INCLUDE_FILES= includes/checker.h  \
			   includes/common.h    \
			   includes/libft.h     \
			   includes/push_swap.h

SRCS_COMMON=	srcs/common/create_list.c			\
				srcs/common/init.c					\
				srcs/common/instructions.c			\
				srcs/common/list.c					\
				srcs/common/push.c					\
				srcs/common/reverse_rotate.c		\
				srcs/common/rotate.c				\
				srcs/common/swap.c	

SRCSCHECKER=	srcs/checker/main.c					\
				srcs/checker/check.c

SRCSPUSH=		srcs/push_swap/calculations.c		\
				srcs/push_swap/divide.c				\
				srcs/push_swap/long_sort.c			\
				srcs/push_swap/main.c				\
				srcs/push_swap/order_list.c			\
				srcs/push_swap/sort_list.c

OBJSCOMMON= $(SRCS_COMMON:.c=.o)
OBJSCHECKER= $(SRCSCHECKER:.c=.o)
OBJSPUSH= $(SRCSPUSH:.c=.o)

RM= rm -f

CFLAGS= -Iincludes -Wall -Wextra -Werror

all:	$(NAME) $(NAMECHECKER)

$(NAME): $(OBJSPUSH) $(OBJSCOMMON) $(INCLUDE_FILES)
	make -C libft
	gcc $(OBJSPUSH) $(OBJSCOMMON) -o $(NAME) -Llibft -lft

$(NAMECHECKER): $(OBJSCHECKER) $(OBJSCOMMON) $(INCLUDE_FILES)
	make -C libft
	gcc $(OBJSCHECKER) $(OBJSCOMMON) -o $(NAMECHECKER) -Llibft -lft

clean:
	make clean -C libft
	$(RM) $(OBJSCOMMON) $(OBJSCHECKER) $(OBJSPUSH)

fclean: clean
	$(RM) $(NAMELIB) $(NAMECHECKER) $(NAME)

re: fclean all

.PHONY: all clean fclean re

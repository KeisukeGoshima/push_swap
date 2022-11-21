CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
SRCSDIR		= ./srcs
SRCS		= swap.c libft.c push_swap_main.c
OBJS		= $(notdir $(SRCS:.c=.o))
BOBJS		= $(notdir $(BSRUS:.c=.o))
INCLUDEDIR	= ./includes
NAME		= push_swap.exe

all:			$(NAME)

clean:
				rm -f $(OBJS)
				rm -f $(BOBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

bonus:			$(NAME)

wfclean:		
				del -f $(OBJS)
				del -f $(NAME)
NAME = libftprintf.a

SRCS = ft_printf.c

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

CC = gcc

$(NAME):$(OBJS)
	$(CC) -c $(FLAGS) $(HEADER) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
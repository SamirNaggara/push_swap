NAME	=	push_swap
LIBS	=	libs/libft.a
FLAGS	= -Wall -Wextra -Werror		
RM		= rm -f

SOURCES	=	./main.c \
				./helper/add_link_list.c \
				./helper/delete_link_list.c \
				./helper/print_link_list.c \
				./helper/test_link_list.c \
				./init/error_handling.c \
				./init/init.c \
				./moves/add_move.c \
				./moves/push.c \
				./moves/rotate_reverse.c \
				./moves/rotate.c \
				./moves/swap.c \
				./moves/swap.c \
				./free/free.c \

 


OBJETS	=	$(SOURCES:.c=.o)			

CC	=	gcc $(FLAGS)
RM	=	rm -f				

all		: $(NAME)

$(NAME): $(OBJETS)
	$(CC) $(FLAGS)-o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< 


clean	:
		$(RM) $(OBJETS)						 

fclean	:	clean			
		$(RM) $(NAME)
		$(RM) a.out

re		:	fclean all

.PHONY: all clean fclean re
.SILENT: all
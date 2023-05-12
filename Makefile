NAME	=	push_swap
LIBS	=	libs/libft.a
FLAGS	= -Wall -Wextra -Werror		
RM		= rm -f

SOURCES	=	./main.c
#				./ft_main/ft_first_flag.c \

 


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
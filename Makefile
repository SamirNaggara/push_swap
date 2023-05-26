NAME		= push_swap
LIB			= libftprintf.a
LIB_PATH	= printf
FLAGS		= -Wall -Wextra -Werror -g	
RM			= rm -f
GREEN		= \033[0;32m
RESET		= \033[0m



SOURCES	=	./main.c \
				./brute_force/brute_force.c \
				./brute_force/display_comb.c \
				./brute_force/increment_comb.c \
				./brute_force/test_comb.c \
				./helper_heap/add_link_list.c \
				./helper_heap/delete_link_list.c \
				./helper_heap/print_link_list.c \
				./helper_heap/test_link_list.c \
				./init/error_handling.c \
				./init/init_tab_func.c \
				./init/init.c \
				./mediane/comparaisons.c \
				./mediane/mediane.c \
				./moves/add_move.c \
				./moves/push.c \
				./moves/rotate_reverse.c \
				./moves/rotate.c \
				./moves/swap.c \
				./moves/swap.c \
				./free/free.c \
				./free/free2.c \
				./radix/radix_count.c \
				./radix/radix_moves.c \
				./radix/radix_optimize.c \
				./radix/radix.c \

 


OBJETS	=	$(SOURCES:.c=.o)			

CC	=	gcc $(FLAGS)
RM	=	rm -f				

all		: lib $(NAME)
	@echo -e "$(GREEN)\n\nC'est bon, plus qu'à executer ./$(NAME) avec tes nombres derrières.\n\nSi tu ne sais pas quoi tester, essaie ça : ./$(NAME) 987 52 -365 10 54 87 63 88 -16 59\n${RESET}"

$(NAME): $(OBJETS)
	@echo "Création de l'executable $(NAME)"
	@$(CC) $(FLAGS)-o $@ $^ $(LIB)

%.o: %.c
	@echo "Génération de $@"
	@$(CC) $(FLAGS) -o $@ -c $< 

lib	: 
	@echo "Je déclenche le Makefile de Printf, et donc de Libft"
	@$(MAKE) -C $(LIB_PATH) all
	@echo "Copie de $(LIB) dans le repertoire courant"
	@cp $(LIB_PATH)/$(LIB) $(LIB)

clean	:
		@echo "Suppression des .o"
		@$(RM) $(OBJETS)
		@echo "On clean la librairie"
		@$(MAKE) -C $(LIB_PATH) clean				 

fclean	:	clean
		@echo "Suppression de $(NAME)"
		@$(RM) $(NAME)
		@echo "Suppression de a.out"
		@$(RM) a.out
		@echo "Suppression de la librairie"
		@$(MAKE) -C $(LIB_PATH) fclean
		@$(RM) a.out
		@$(RM) $(LIB)

re		:	fclean all

.PHONY: all clean fclean re lib

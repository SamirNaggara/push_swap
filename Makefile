NAME		= 	push_swap
LIB_PATH	= 	libft-plus
LIBFT 		= 	$(LIB_PATH)/libft.a
PRINTF		=	$(LIB_PATH)/printf.a 
FLAGS		= 	-Wall -Wextra -Werror -g	
RM			= 	rm -f
GREEN		= 	\033[0;32m
RESET		= 	\033[0m



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
	@echo -e "$(GREEN)\n\nC'est bon, plus qu'à executer ./$(NAME) avec tes nombres a trier derrières.\n\n$(RESET)Si tu ne sais pas quoi tester, essaie ça : ./$(NAME) 987 52 -365 10 54 87 63 88 -16 59\n"

$(NAME): $(OBJETS)
	@echo "Création de l'executable $(NAME)"
	@$(CC) $(FLAGS)-o $@ $^ $(PRINTF) $(LIBFT)

%.o: %.c
	@echo "Génération de $@"
	@$(CC) $(FLAGS) -o $@ -c $< 

lib	: 
	@echo "Je déclenche le Makefile de Libft-plus\n"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) all
	@echo "Je sors du Makefile de Libft-plus"


clean	:
	@echo "Suppression des .o de push_swap"
	@$(RM) $(OBJETS)
	@echo "\n$(GREEN)Tout les .o ont bien été effacé$(RESET)"


fclean	:	clean
	@echo "Suppression de $(NAME)"
	@$(RM) $(NAME)
	@echo "Suppression de a.out au cas ou"
	@$(RM) a.out
	@echo "Je rentre dans la librairie libft-plus"
	@$(MAKE) --no-print-directory -C $(LIB_PATH) fclean
	@echo "Je sors de la librairie libft-plus"
	@echo "\n$(GREEN)Tout les fichiers ont bien été effacés$(RESET)\n"

re		:	fclean all

.PHONY: all clean fclean re lib

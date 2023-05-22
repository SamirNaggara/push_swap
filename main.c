/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/22 14:44:19 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_init(ac, av);

	if (ft_is_order(data->a_heap))
	{
		ft_printf("liste ordonnée\n");
		return (0);
	}
	
	data->move_func[0] = &ft_sa;
	data->move_func[1] = &ft_sb;
	data->move_func[2] = &ft_ss;
	data->move_func[3] = &ft_pa;
	data->move_func[4] = &ft_pb;
	data->move_func[5] = &ft_ra;
	data->move_func[6] = &ft_rb;
	data->move_func[7] = &ft_rr;
	data->move_func[8] = &ft_rra;
	data->move_func[9] = &ft_rrb;
	data->move_func[10] = &ft_rrr;

	data->move_func_rev[0] = &ft_sa;
	data->move_func_rev[1] = &ft_sb;
	data->move_func_rev[2] = &ft_ss;
	data->move_func_rev[3] = &ft_pb;
	data->move_func_rev[4] = &ft_pa;
	data->move_func_rev[5] = &ft_rra;
	data->move_func_rev[6] = &ft_rrb;
	data->move_func_rev[7] = &ft_rrr;
	data->move_func_rev[8] = &ft_ra;
	data->move_func_rev[9] = &ft_rb;
	data->move_func_rev[10] = &ft_rr;
	
	if (data->nb_numbers <= 6)
		data->comb = ft_brut_force_it(data);
	
	if (!data->comb)
		ft_printf("on dirait qu'on a pas reussis a brute force !\n");
	else
		ft_display_comb(data);

	ft_print_heap(data->a_heap);
	
	free(data->comb);
	ft_free_end(data);
	return (0);
}

void	ft_display_comb(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_comb)
	{
		if (data->comb[i] == 0)
			printf("%s\n", "sa");
		else if (data->comb[i] == 1)
			printf("%s\n", "sb");
		else if (data->comb[i] == 2)
			printf("%s\n", "ss");
		else if (data->comb[i] == 3)
			printf("%s\n", "pa");
		else if (data->comb[i] == 4)
			printf("%s\n", "pb");
		else if (data->comb[i] == 5)
			printf("%s\n", "ra");
		else if (data->comb[i] == 6)
			printf("%s\n", "rb");
		else if (data->comb[i] == 7)
			printf("%s\n", "rr");
		else if (data->comb[i] == 8)
			printf("%s\n", "rra");
		else if (data->comb[i] == 9)
			printf("%s\n", "rrb");
		else if (data->comb[i] == 10)
			printf("%s\n", "rrr");
		i++;
	}
}

/*
	Pour un petit nombre, on essaie toute les possibilités
*/
int	*ft_brut_force_it(t_data *data)
{
	int	*comb;
	int	j;

	data->nb_comb = 1;
	while (data->nb_comb <= 10)
	{
		comb = (int *)malloc((data->nb_comb + 1) * (sizeof(int)));
		if (!comb)
			return (0);
		j = 0;
		while (j < data->nb_comb)
		{
			comb[j] = 0;
			j++;
		}
		comb[j] = -1;

		if (ft_try_with_n_possilitie(data, comb, data->nb_comb))
		{
			printf("normalement Sam, ça a marché \n");
			return (comb);
		}
		data->nb_comb++;
		free(comb);

	}
	return ((int *) 0);
}

/*
	On test la combinaison envoyé
	Si elle fonctionne on renvoie la combinaison
	Sinon on renvoie un pointeur null, on incremente comb
	Et on se rappel nous meme avec la nouvelle comb
	sauf si on est au bout !
	La on renvoie un pointeur null
*/
int	*ft_try_with_n_possilitie(t_data *data, int *comb, int n)
{
	// Si la combinaison est bonne, on la renvoie, on a finis
	if (ft_test_combinaison(comb, data, n))
		return (comb);
	if (!ft_increment_comb(comb, n)) // Ca renvoie faux si pas incrementable
		return ((int *)0);
	// Donc là on a incrementé, oklm
	// on peut se rappeller nous meme avec le nouveau comb
	return (ft_try_with_n_possilitie(data, comb, n));
}


/* Ici on a une combinaison, on va l'incrementer de 1
	Y'a un -1 a la fin pour connaitre sa taille
	Et si on ne peut pas parce qu'on est au max
	On renvoie faux
*/
int	ft_increment_comb(int *comb, int n)
{
	int	i;

	comb[n - 1]++;
	i = n - 1;
	while (i >= 0)
	{
		if (comb[i] == 11)
		{
			if (i == 0)
				return (0);
			comb[i] = 0;
			comb[i - 1]++;
			continue ;
		}
		if (i != 0)
		{
			if (comb[i] == 0 && comb[i - 1] == 0)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 1 && comb[i - 1] == 1)
			{
				comb[i]++;
				continue ;
			}else if (comb[i] == 2 && comb[i - 1] == 2)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 3 && comb[i - 1] == 4)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 4 && comb[i - 1] == 3)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 5 && comb[i - 1] == 8)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 6 && comb[i - 1] == 9)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 7 && comb[i - 1] == 10)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 8 && comb[i - 1] == 5)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 9 && comb[i - 1] == 6)
			{
				comb[i]++;
				continue ;
			}
			else if (comb[i] == 10 && comb[i - 1] == 7)
			{
				comb[i]++;
				continue ;
			}
		}
		i--;
	}
	if (!ft_increment_more(comb))
		return (0);
	return (1);
}

/* 
	On lis le nombre, et si on vois qu'il a besoin d'une incrementation
	supplementaire
	On renvoie 1
	Par exemple si il finit par un pb, c'est impossible
	Donc on incremente 
*/
int	ft_increment_more(int *comb)
{
	/*
	Ca ne peut pas commencer par tout ça
	*/

	if (comb[0] == 1 || comb[0] == 2 || comb[0] == 3 
	|| comb[0] == 6 || comb[0] == 7 || comb[0] == 9
	|| comb[0] == 10)
	{
		comb[0]++;
		if (comb[0] == 11)
			return (0);
	}
	return (1);
}

/*
	On test une combinaison d'une longueur donnée
	Si ça reussis on renvoie 1
	Sinon, on rembobine et on renvoie 0 !
	Attention, c'est tricky parce que si un mouv ne marche pas
	Genre pa, mais y'a rien dans b
	Alors on arrete tout, et on revient en arriere,
	mais juste les coups qui ont marché !
*/
int	ft_test_combinaison(int *comb, t_data *data, int n)
{
	int	i;

	i = 0;

	while (i < n)
	{
		if (!data->move_func[comb[i]](data))
			break ;
		i++;
	}
	if (i == n && ft_is_empty(data->b_heap) && ft_is_order(data->a_heap))
		return (1);
	if (i > 0)
		ft_reverse_combinaison(comb, data, i);

	return (0);

}

/*
	Cette fonction est top, elle inverse une combinaison.
	Si on a testé une combinaison, et qu'elle n'a pas marché
	On peut appeler cette fonction pour faire un ctrl z
	Ca marche du fait que les combinaisons ont tous un opposé
	et qu'ils sont bien placé dans la liste
*/
void	ft_reverse_combinaison(int *comb, t_data *data, int n)
{
	int	i;

	i = n - 1;

	while (i >= 0)
	{
		data->move_func_rev[comb[i]](data);
		i--;
	}

}


/*
	Renvoie 1 si la liste est ordonnée
	Et que B est vide !
*/
int		ft_is_order(t_heap	**heap)
{
	t_heap	*browse;

	browse = *heap;
	while (browse->next != *heap)
	{
		if (browse->nb >= browse->next->nb)
			return (0);
		browse = browse->next;
	}
	return (1);
}

int		ft_is_empty(t_heap **heap)
{
	if (!heap)
		return (1);
	if (!*heap)
		return (1);
	return (0);
}
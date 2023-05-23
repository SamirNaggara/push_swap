/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:11:59 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:27:21 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	On test une combinaison d'une longueur donnée
	Si ça reussis on renvoie 1
	Sinon, on rembobine et on renvoie 0 !
	Attention, c'est tricky parce que si un mouv ne marche pas
	Genre pa, mais y'a rien dans b
	Alors on arrete tout, et on revient en arriere,
	mais juste les coups qui ont marché !
*/
int	ft_test_combinaison_a(int *comb, t_data *data, int n, int len)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!data->move_func[comb[i]](data))
			break ;
		i++;
	}
	if (i == n && ft_size_heap(data->a_heap) == len
		&& ft_is_order(data->a_heap))
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

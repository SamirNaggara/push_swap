/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:55:54 by snaggara          #+#    #+#             */
/*   Updated: 2023/08/07 18:48:54 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_really_small_method(t_data *data)
{
	data->comb = ft_brut_force_a(data);
	if (!data->comb)
		return (ft_free_heap_and_data(data));
	ft_display_comb(data);
	free(data->comb);
	return (1);
}

/*
	Pour un petit nombre, on essaie toute les possibilités
*/
int	*ft_brut_force_a(t_data *data)
{
	int	*comb;
	int	j;

	data->nb_comb = 1;
	while (data->nb_comb <= 10)
	{
		comb = (int *)malloc((data->nb_comb + 1) * (sizeof(int)));
		if (!comb)
			return ((int *)0);
		j = 0;
		while (j < data->nb_comb)
		{
			comb[j] = 0;
			j++;
		}
		comb[j] = -1;
		if (ft_fb_a_with_n_possilities(data, comb, data->nb_comb))
			return (comb);
		data->nb_comb++;
		free(comb);
	}
	return (comb);
}

/*
	On test la combinaison envoyé
	Si elle fonctionne on renvoie la combinaison
	Sinon on renvoie un pointeur null, on incremente comb
	Et on se rappel nous meme avec la nouvelle comb
	sauf si on est au bout !
	La on renvoie un pointeur null
*/

int	*ft_fb_a_with_n_possilities(t_data *data, int *comb, int n)
{
	if (ft_test_combinaison_a(comb, data, n, data->nb_numbers))
		return (comb);
	if (!ft_increment_comb(comb, n))
		return ((int *)0);
	return (ft_fb_a_with_n_possilities(data, comb, n));
}

// int		ft_double_brute_force(t_data *data)
// {
// 	int	*comb;

// 	data->med = ft_mediane(data->a_heap);
// 	if (!data->med)
// 		return (0);
// 	comb = ft_push_above_mediane(data, data->nb_numbers);
// 	ft_display_this_comb(comb, data->nb_numbers);
// 	ft_brut_force_a(data);
// 	free(comb);
// 	return (1);
// }

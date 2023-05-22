/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:52:30 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/22 13:32:27 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
    On ajoute les mouvements dans le tableau data->moves
    Pour ça on se place tout de suite a 3 * nb_move, c'est à peu pres la fin.
    Si y'a des caracteres bah on avance jusqu'a la fin de la chaine.
    Et arriver à la fin, on ajoute name (qui fait parfois 2 ou 3 caracteres)
*/
// void	ft_add_move(t_data *data, const char *name)
// {
// 	int	i;

// 	i = 3 * data->nb_move;
// 	while (data->moves[i])
// 		i++;
// 	data->moves[i] = name[0];
// 	i++;
// 	data->moves[i] = name[1];
// 	i++;
// 	if (name[2])
// 	{
// 		data->moves[i] = name[2];
// 		i++;
// 	}
// 	data->moves[i] = '\n';
// 	i++;
// 	data->moves[i] = '\0';
// 	data->nb_move++;
// }

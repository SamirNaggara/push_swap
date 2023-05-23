/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:11:44 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/23 14:18:57 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Ce tableau alloué dans la stack contient toutes 
	les fonctions de mouvement dans l'ordre
*/

void	ft_init_move_func(t_data *data)
{
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
}

/*
	Et ici leur opposé !
*/
void	ft_init_move_func_rev(t_data *data)
{
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
}

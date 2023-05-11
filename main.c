/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/11 19:03:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    check_format(ac, av);
    ft_printf("salut :%d, %s", ac, av[1]);
    return (0);
}

void     check_format(int ac, char **av)
{
    if (ac == 1)
        returnError();
    if (!av)
        return;
}

int     returnError()
{
    ft_printf("Error\n");
    exit(0);
}
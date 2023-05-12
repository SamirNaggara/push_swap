/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/05/12 23:05:19 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{

    ft_create_A_list(ac, av);
    ft_printf("Je suis au bout\n");
    //ft_printf("cmp : %d", ft_strcmp("123", INT_MAX));
    return (0);
}

int ft_create_A_list(int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 1)
        returnError();

    while (i < ac)
    {
        ft_test_is_number(av[i]);
        i++;
    }
    return (0);
}

void    ft_test_is_number(char *nbc)
{
    int i;
    int sign;

    sign = 1;
    if (*nbc == '-' || *nbc == '+')
    {
        sign = -1;
        nbc++;
    }
    if (!*nbc)
        returnError();
    while (*nbc == '0')
        nbc++;
    i = 0;
    while (ft_isdigit(nbc[i]))
        i++;
    if (nbc[i])
        returnError();
    if (sign == 1)
    {
        if (ft_strlen(nbc) > 10)
            returnError();
        if (ft_strncmp(nbc, INT_MAX, 10) > 0)
            returnError();
        return ;
    }

    if (ft_strlen(nbc) > 10)
        returnError();
    if (ft_strncmp(nbc, INT_MIN, 10) > 0)
        returnError();

}


int     returnError()
{
    ft_printf("Error\n");
    exit(0);
}
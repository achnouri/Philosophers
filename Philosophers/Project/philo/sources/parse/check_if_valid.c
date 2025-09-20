/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:13:16 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/18 02:58:48 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

bool	check_n_args(int n)
{
	if (n == 5 || n == 6)
		return (true);
	return (false);
}

static bool	int_valid2(char **nb)
{
	while (**nb == ' ')
		(*nb)++;
	if (**nb == '+')
		(*nb)++;
	else if (**nb == '-')
		return (display_details_msg(O_P_NUM), false);
	if (!(**nb >= '0' && **nb <= '9'))
		return (display_details_msg(N_V_NUM), false);
	while (**nb >= '0' && **nb <= '9')
		(*nb)++;
	return (true);
}

static bool	n_valid(char *nb)
{
	long	number;

	number = str_to_long(nb);
	if (!int_valid2(&nb))
		return (false);
	while (*nb)
	{
		if (*nb != ' ')
			return (display_details_msg(O_NUM), false);
		nb++;
	}
	if (number > INT_MAX)
		return (display_details_msg(MEM_ERR), false);
	return (true);
}

static bool	check_limits_args(char **av)
{
	if (str_to_long(av[1]) > 200)
		return (display_details_msg(MAX_P), false);
	if (str_to_long(av[2]) < 60 || str_to_long(av[3]) < 60
		|| str_to_long(av[4]) < 60)
		return (display_details_msg(MAX_A), false);
	return (true);
}

bool	valid_input(int ac, char **av)
{
	int	i;

	i = 1;
	if (!check_limits_args(av))
		return (false);
	while (i < ac)
	{
		if (n_valid(av[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

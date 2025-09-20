/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:42:18 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/19 19:58:45 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_n_args(ac))
		return (display_usage_msg(), 0);
	if (valid_input(ac, av) && initialize_data(ac, av, &data))
	{
		simulation(&data);
		clear_all(&data);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:10:19 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/18 02:57:11 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	add_philo_back(t_philo **list, t_philo *new_node)
{
	t_philo	*tmp;

	if (!*list)
	{
		*list = new_node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
}

long	str_to_long(const char *str)
{
	char	*s;
	long	result;

	s = (char *)str;
	result = 0;
	while (*s && *s == ' ')
		s++;
	if (*s && *s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}

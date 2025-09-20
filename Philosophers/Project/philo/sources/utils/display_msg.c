/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achnouri <achnouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 02:11:48 by achnouri          #+#    #+#             */
/*   Updated: 2025/08/20 16:35:20 by achnouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	display_usage_msg(void)
{
	printf("Usage : A B C D E F\n");
	printf("[A] : program name\n");
	printf("[B] : number_of_philosophers\n");
	printf("[C] : die_time\n");
	printf("[D] : eat_time\n");
	printf("[E] : sleep_time\n");
	printf("[F] : (F option is optional) : ");
	printf("number_of_times_each_philosopher_must_eat\n");
}

void	display_details_msg(int error_code)
{
	if (error_code == I_M_L)
		printf("[invalid input] : integer exceeds max limit\n");
	else if (error_code == O_NUM)
		printf("[invalid input] : must insert only numbers\n");
	else if (error_code == O_P_NUM)
		printf("[invalid input] : only positive numbers are allowed\n");
	else if (error_code == N_V_NUM)
		printf("[invalid input] : number not valid\n");
	else if (error_code == MEM_ERR)
		printf("[invalid input] : memory allocation failed\n");
	else if (error_code == MAX_A)
		printf("[invalid input]\n");
	else if (error_code == MAX_P)
	{
		printf("[invalid input] : numbers of philosophers ");
		printf("must be between 1 and 200\n");
	}
}

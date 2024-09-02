/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:03:49 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 19:24:05 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	else if (ac > 1)
	{
		preinit_stack(&a, ac, av);
		while (!(stack_sorted(a)))
		{
			if (stack_len(a) == 2)
				sa(&a, false);
			if (stack_len(a) == 3)
				sorthree(&a);
			if (stack_len(a) > 3)
				sort_other(&a, &b);
		}
	}
	frees(&a);
}

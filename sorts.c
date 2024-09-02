/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:59:22 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 17:58:04 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortwo(t_stack_node *a)
{
	sa(&a, false);
}

void	sorthree(t_stack_node **a)
{
	t_stack_node	*max;

	max = findmax(*a);
	if (max == *a)
		ra(a, false);
	else if ((*a)->next == max)
		rra(a, false);
	if ((*a)->next->nbr < (*a)->nbr)
		sa(a, false);
}

void	head_is_min(t_stack_node **a)
{
	t_stack_node	*mini;

	mini = findmin(*a);
	while ((*a)->nbr != mini->nbr)
	{
		if (mini->a_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_other(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len-- > 3 && !stack_sorted(*a))
	{
		itpc_a(*a, *b);
		push_a_b(a, b);
	}
	sorthree(a);
	while (*b)
	{
		it_b(*a, *b);
		push_b_a(a, b);
	}
	index_node(*a);
	head_is_min(a);
}

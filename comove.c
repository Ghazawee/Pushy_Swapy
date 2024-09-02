/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:28:16 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:01:28 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	itpc_a(t_stack_node *a, t_stack_node *b)
{
	index_node(a);
	index_node(b);
	a_target_node(a, b);
	push_cost(a, b);
	cheapestn(a);
}

void	it_b(t_stack_node *a, t_stack_node *b)
{
	index_node(a);
	index_node(b);
	b_target_node(a, b);
}

void	push_a_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap;

	cheap = NULL;
	cheap = find_cheap_node(*a);
	if (cheap->a_median && cheap->target_node->a_median)
	{
		rot_both(a, b, cheap);
	}
	else if (!(cheap->a_median) && !(cheap->target_node->a_median))
	{
		revrot_both(a, b, cheap);
	}
	prepush(a, cheap, 'a');
	prepush(b, cheap->target_node, 'b');
	pb(b, a, false);
}

void	push_b_a(t_stack_node **a, t_stack_node **b)
{
	prepush(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

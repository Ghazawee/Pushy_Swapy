/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:23:56 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:07:09 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate(t_stack_node **s)
{
	t_stack_node	*lastn;

	if (!*s || !(*s)->next)
		return ;
	lastn = flastn(*s);
	lastn->prev->next = NULL;
	lastn->next = *s;
	lastn->prev = NULL;
	*s = lastn;
	lastn->next->prev = lastn;
}

void	rra(t_stack_node **a, bool tf)
{
	revrotate(a);
	if (!tf)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool tf)
{
	revrotate(b);
	if (!tf)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool tf)
{
	revrotate(a);
	revrotate(b);
	if (!tf)
		write(1, "rrr\n", 4);
}

void	revrot_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b, false);
	index_node(*a);
	index_node(*b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:24:17 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:06:38 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **s)
{
	t_stack_node	*lastn;

	if (!*s || !(*s)->next)
		return ;
	lastn = flastn(*s);
	lastn->next = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	lastn->next->prev = lastn;
	lastn->next->next = NULL;
}

void	ra(t_stack_node **a, bool tf)
{
	rotate(a);
	if (!tf)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool tf)
{
	rotate(b);
	if (!tf)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool tf)
{
	rotate(a);
	rotate(b);
	if (!tf)
		write(1, "rr\n", 3);
}

void	rot_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b, false);
	index_node(*a);
	index_node(*b);
}

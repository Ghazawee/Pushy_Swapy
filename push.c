/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:24:38 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/29 18:06:08 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **d, t_stack_node **s)
{
	t_stack_node	*pn;

	if (!*s)
		return ;
	pn = *s;
	*s = (*s)->next;
	if (*s)
		(*s)->prev = NULL;
	pn->prev = NULL;
	if (!*d)
	{
		*d = pn;
		pn->next = NULL;
	}
	else
	{
		pn->next = *d;
		pn->next->prev = pn;
		*d = pn;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool tf)
{
	push(a, b);
	if (!tf)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a, bool tf)
{
	push(b, a);
	if (!tf)
		write(1, "pb\n", 3);
}

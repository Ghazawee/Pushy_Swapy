/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshaheen <mshaheen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:23:29 by mshaheen          #+#    #+#             */
/*   Updated: 2024/08/22 11:31:07 by mshaheen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_node **s)
{
	if (!*s || !(*s)->next)
		return ;
	*s = (*s)->next;
	(*s)->prev->prev = *s;
	(*s)->prev->next = (*s)->next;
	if ((*s)->next)
		(*s)->next->prev = (*s)->prev;
	(*s)->next = (*s)->prev;
	(*s)->prev = NULL;
}

void	sa(t_stack_node **a, bool tf)
{
	swap(a);
	if (!tf)
		write(1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool tf)
{
	swap(b);
	if (!tf)
		write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool tf)
{
	swap(a);
	swap(b);
	if (!tf)
		write(1, "ss\n", 3);
}

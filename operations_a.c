/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:09 by lteng             #+#    #+#             */
/*   Updated: 2024/03/18 22:33:03 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SA (Swap A)
// Swap the first 2 elements at the top of stack A
// Do nothing if there is only one or no elements
void	swap_a(t_stack **a)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sa\n", 3);
}

// RA (Rotate A)
// Shift up all elements of stack A by 1
// The first element becomes the last one
void	rotate_a(t_stack **a)
{
	t_stack	*temp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	temp = ft_last_node(*a);
	temp->next = *a;
	*a = (*a)->next;
	temp->next->next = NULL;
	write(1, "ra\n", 3);
}

// RRA (Reverse Rotate A)
// Shift down all elements of stack A by 1
// The last element becomes the first one
void	reverse_rotate_a(t_stack **a)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last_node = ft_last_node(*a);
	second_last_node = ft_second_last_node(*a);
	last_node->next = *a;
	*a = last_node;
	second_last_node->next = NULL;
	write(1, "rra\n", 4);
}

// PA (Push A)
// Take the first element at the top of B and put it at the top of A
// Do nothing if B is empty
void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	if (*a == NULL)
		*a = temp;
	else
	{
		temp->next = *a;
		*a = temp;
	}
	write(1, "pa\n", 3);
}

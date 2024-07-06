/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:58:09 by lteng             #+#    #+#             */
/*   Updated: 2024/03/20 22:13:55 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// SB (Swap B)
// Swap the first 2 elements at the top of stack B
// Do nothing if there is only one or no elements
void	swap_b(t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = (*b)->next;
	(*b)->next = temp;
	write(1, "sb\n", 3);
}

// RB (Rotate B)
// Shift up all elements of stack B by 1
// The first element becomes the last one
void	rotate_b(t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	temp = ft_last_node(*b);
	temp->next = *b;
	*b = (*b)->next;
	temp->next->next = NULL;
	write(1, "rb\n", 3);
}

// RRB (Reverse Rotate B)
// Shift down all elements of stack B by 1
// The last element becomes the first one
void	reverse_rotate_b(t_stack **b)
{
	t_stack	*last_node;
	t_stack	*second_last_node;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	last_node = ft_last_node(*b);
	second_last_node = ft_second_last_node(*b);
	last_node->next = *b;
	*b = last_node;
	second_last_node->next = NULL;
	write(1, "rrb\n", 4);
}

// PB (Push B)
// Take the first element at the top of A and put it at the top of B
// Do nothing if A is empty
void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	if (*b == NULL)
		*b = temp;
	else
	{
		temp->next = *b;
		*b = temp;
	}
	write(1, "pb\n", 3);
}

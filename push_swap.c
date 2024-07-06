/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:44:06 by lteng             #+#    #+#             */
/*   Updated: 2024/03/21 20:54:08 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For Testing List Operations
while (a != NULL)
{
	printf("Start to end: %i\n", a->nbr);
	a = a->next;
}
*/

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = ft_process(argc, argv);
	if (stack_size(a) == 5 && is_sorted(a) == 1)
		ft_sort_five(&a);
	if (is_sorted(a) == 1)
		ft_sort(&a);
	free_lst(&a);
	return (0);
}

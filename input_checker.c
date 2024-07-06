/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:34:44 by lteng             #+#    #+#             */
/*   Updated: 2024/03/23 13:38:36 by lteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack **lst)
{
	free_lst(lst);
	write(2, "Error\n", 6);
	exit(1);
}

// Function to check all are digits
int	ft_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			ft_error(NULL);
		else
			i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

// New atoi to cater for int limits
int	ft_atoi_new(char *nptr)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		ft_error(NULL);
	return (num * sign);
}

// Process to split "numbers" into individual strings
t_stack	*ft_process_split(char *argv[])
{
	t_stack	*a;
	char	**temp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	temp = ft_split(argv[1], 32);
	if (ft_duplicate(temp) != 0)
		ft_error(NULL);
	while (temp[i])
	{
		if (ft_num(temp[i]) == 0)
			ft_error(&a);
		j = ft_atoi_new(temp[i]);
		ft_add_node(&a, ft_new_node(j));
		i++;
	}
	free_all(temp);
	return (a);
}

// Initial check to see if input is a legit number and in "" or not
// If in "" to run process to split, else stick to current process
t_stack	*ft_process(int argc, char *argv[])
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		a = ft_process_split(argv);
	else
	{
		if (ft_duplicate(argv) != 0)
			ft_error(NULL);
		while (i < argc)
		{
			if (ft_num(argv[i]) == 0)
				ft_error(&a);
			j = ft_atoi_new(argv[i]);
			ft_add_node(&a, ft_new_node(j));
			i++;
		}
	}
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:33:59 by arpages           #+#    #+#             */
/*   Updated: 2023/12/27 14:49:24 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	make_lst(t_stack *stack, char **num, int size)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	while (++i < size)
	{
		j = 0;
		temp = ft_split(num[i]);
		if (verif_strstr(temp) < 0)
			return (-1);
		while (temp[j] != NULL)
		{
			create_n_add(&stack->a, temp, j);
			j++;
		}
		free(temp);
	}
	if (verif_lst(stack->a) < 0)
	{
		ft_free_lst(stack->a);
		return (-1);
	}
	ranker(stack->a);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (argc <= 1)
		return (ft_printf("\n"));
	if (make_lst(&stack, argv, argc) < 0)
		return (ft_printf("Error in stack creation\n"), 0);
	algo(&stack);
	ft_free_lst(stack.a);
	ft_free_lst(stack.b);
	return (0);
}

/*
void print_lst(t_lst *lsta, t_lst *lstb)
{
	t_lst *tempa;
	t_lst *tempb;

	tempa = lsta;
	tempb = lstb;
	printf(" A  <->  B \n");
	printf("    ---    \n");
	while (tempa || tempb)
	{
		if (tempa && tempb)
		{
			printf("|%d| <-> |%d (%d.%d)|\n", tempa->rank, 
					tempb->rank, tempb->to_a, tempb->to_b);
			tempa = tempa->next;
			tempb = tempb->next;
		}
		else if (tempa)
		{
			printf("|%d| <-> |X|\n", tempa->rank);
			tempa = tempa->next;
		}
		else if (tempb)
		{
			printf("|X| <-> |%d (%d.%d)|\n", 
					tempb->rank, tempb->to_a, tempb->to_b);
			tempb = tempb->next;
		}
	}
	printf("\n");
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:33:59 by arpages           #+#    #+#             */
/*   Updated: 2024/01/10 15:21:43 by arpages          ###   ########.fr       */
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		verif;

	stack.a = NULL;
	stack.b = NULL;
	if (argc <= 1 || verif_strstr(argv) == -1)
	{
		return (0);
	}
	verif = make_lst(&stack, argv, argc);
	if (verif < 0)
		return (ft_printf("Error\n"), 0);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:33:59 by arpages           #+#    #+#             */
/*   Updated: 2023/12/17 16:36:10 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_lst(t_stack *stack, char **num, int size)
{
	int i;
	int j;
	char **temp;
	
	i = 0;
	while (++i < size)
	{
		j = 0;
		temp = ft_split(num[i]);
		if (verif_strstr(temp) < 0)
			return(-1);
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
			printf("|%d| <-> |%d|\n", tempa->rank, tempb->rank);
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
			printf("|X| <-> |%d|\n", tempb->rank);
			tempb = tempb->next;
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_stack	stack;
	
	stack.a = NULL;
	stack.b = NULL;
	if (argc <= 1)
		return(printf("arguments error\n"));
	//printf("----%d----\n", make_lst(&stack, argv, argc));
	if (make_lst(&stack, argv, argc) < 0)
		return (printf("Error\n"), 0);
	print_lst(stack.a, stack.b);
	mv_pb(&stack);
	print_lst(stack.a, stack.b);
	mv_pb(&stack);
	print_lst(stack.a, stack.b);
	mv_pb(&stack);
	print_lst(stack.a, stack.b);
	mv_sa(&stack);
	print_lst(stack.a, stack.b);
	mv_pb(&stack);
	print_lst(stack.a, stack.b);
	mv_pa(&stack);
	print_lst(stack.a, stack.b);
	mv_ss(&stack);
	print_lst(stack.a, stack.b);
	mv_ra(&stack);
	print_lst(stack.a, stack.b);
	mv_rb(&stack);
	print_lst(stack.a, stack.b);
	mv_ss(&stack);
	print_lst(stack.a, stack.b);
	mv_rrr(&stack);
	print_lst(stack.a, stack.b);
	ft_free_lst(stack.a);
	ft_free_lst(stack.b);
	printf("ok\n");
	return(0);
}



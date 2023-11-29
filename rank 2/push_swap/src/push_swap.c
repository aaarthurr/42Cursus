/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:33:59 by arpages           #+#    #+#             */
/*   Updated: 2023/11/29 16:45:52 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	make_lst(t_stack *stack, char **num, int size)
{
	int i;
	int j;
	char **temp;
	int retour;
	
	i = 0;
	while (++i < size)
	{
		j = 0;
		temp = ft_split(num[i]);
		if (verif_strstr(temp) < 0)
			return(-1);
		while (temp[j] != NULL)
		{
			printf("<-> |%d| <->\n", j);
			ft_lstadd_back(&stack->a, ft_lstnew(ft_atoi(temp[j])));
			free(temp[j]);
			j++;
		}
		free(temp);
	}
	if (verif_lst(stack->a) < 0)
		return (-1);
	return (1);
}

void print_lst(t_lst *lst)
{
	while (lst)
	{
		printf("-> %d\n", lst->content);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	t_stack	stack;
	
	stack.a = NULL;
	stack.b = NULL;
	//printf("----%d----\n", make_lst(&stack, argv, argc));
	if (make_lst(&stack, argv, argc) < 0)
		return (printf("Error\n"), 0);
	//printf("ok\n");
	return(0);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:36:08 by arpages           #+#    #+#             */
/*   Updated: 2023/12/02 14:16:14 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct lst_s
{
	struct lst_s		*next;
	struct lst_s		*prev;
	int					content;
	int					rank;
}				t_lst;

typedef struct stack_s
{
	t_lst		*a;
	t_lst		*b;
}				t_stack;

t_lst	*ft_lstnew(int content);
t_lst	*ft_lstlast(t_lst *lst);
void	ft_lstadd_back(t_lst **lst, t_lst *new);
void	ft_lstadd_front(t_lst **lst, t_lst *new);
int		ft_atoi(char *s);
char	**ft_split(char *str);
int 	verif_lst(t_lst *lst);
char	*ft_strchr(const char *str, int c);
int 	verif_char(char *str);
int		verif_strstr(char **str);

int		make_lst(t_stack *stack, char **num, int size);
void	print_lst(t_lst *lst);

void ft_sa(t_stack *stack);

#endif
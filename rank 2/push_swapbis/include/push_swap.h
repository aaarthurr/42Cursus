/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:36:08 by arpages           #+#    #+#             */
/*   Updated: 2024/01/09 14:10:14 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct lst_s
{
	struct lst_s		*next;
	struct lst_s		*prev;
	int					to_a;
	int					to_b;
	int					content;
	int					rank;
}				t_lst;

typedef struct stack_s
{
	t_lst		*a;
	t_lst		*b;
}				t_stack;

int			abs_val(int i);

t_lst		*ft_lstnew(int content);
t_lst		*ft_lstlast(t_lst *lst);
void		ft_lstadd_back(t_lst **lst, t_lst *new);
void		ft_lstadd_front(t_lst **lst, t_lst *new);
t_lst		*ft_lstdup(t_lst *src);
void		ft_free_lst(t_lst *lst);
int			lsize(t_lst *lst);

char		**ft_split(char *str);
int			verif_lst(t_lst *lst);
char		*ft_strchr(const char *str, int c);
int			verif_char(char *str);
int			verif_strstr(char **str);

int			divide_size(t_lst *lst);

void		ranker(t_lst *lst);

void		create_n_add(t_lst **lst, char **str, int i);

int			make_lst(t_stack *stack, char **num, int size);
void		print_lst(t_lst *lsta, t_lst *lstb);

void		mv_sa(t_stack *stack);
void		mv_sb(t_stack *stack);
void		mv_ss(t_stack *stack);

void		mv_pb(t_stack *stack);
void		mv_pa(t_stack *stack);

void		mv_ra(t_stack *stack);
void		mv_rb(t_stack *stack);
void		mv_rr(t_stack *stack);

void		mv_rra(t_stack *stack);
void		mv_rrb(t_stack *stack);
void		mv_rrr(t_stack *stack);

int			is_sorted(t_stack *stack);
void		lil_sort(t_stack *stack);
void		min_sort_a(t_lst *a, t_stack *stack);
void		max_sort_b(t_lst *b, t_stack *stack);

void		algo(t_stack *stack);
void		devide(t_stack *stack, int i, int j);
int			devide_bis(t_stack *stack, int size, int div, int i);
void		sort_trio(t_stack *stack, t_lst *a);

void		calc_b(t_stack *stack);
void		calc_a(t_stack *stack, t_lst *index);
t_lst		*srch_min(t_stack *stack);

void		duo_min(t_stack *stack, t_lst *to_apl);
void		duo_max(t_stack *stack, t_lst *to_apl);
void		opti_a(t_stack *stack, t_lst *to_apl);
void		opti_b(t_stack *stack, t_lst *to_apl);

int			is_xtrm(t_stack *stack, t_lst *node);
void		calc_xtrm(t_stack *stack, t_lst *lst, int rank_min, int i);

void		applie_mv(t_stack *stack);

void		adjust(t_stack *stack);

long int	ft_atoi(char *s);

#endif
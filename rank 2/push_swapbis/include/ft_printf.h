/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:36:38 by arpages           #+#    #+#             */
/*   Updated: 2023/12/26 17:03:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *txt, ...);
int		ft_strlen(const char *str);
int		ft_strchr_boo(char *s, int c);
int		is_int(char c, int value);
int		is_str(int *value);
int		is_point(unsigned long long value);
int		ft_type(const char *txt, va_list args, int retour);
int		ft_putchar(int c);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putnbr(long nbr, char *base);
int		ft_putstr(char *s);
int		ft_putunbr(unsigned int n);
int		is_uint(unsigned int value);
int		ft_putpoint(unsigned long long nbr);

#endif
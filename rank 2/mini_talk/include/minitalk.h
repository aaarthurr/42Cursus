/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:13:20 by arthur            #+#    #+#             */
/*   Updated: 2024/01/12 17:47:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _XOPEN_SOURCE 700
# define _DEFAULT_SOURCE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <signal.h>
# include "ft_printf.h"

int		ft_atoi(const char *str);
void	ft_error(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
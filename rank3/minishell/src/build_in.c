/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD:rank 3/minishell/src/build_in.c
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:53 by arthur            #+#    #+#             */
/*   Updated: 2024/01/22 16:33:47 by arthur           ###   ########.fr       */
=======
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:04:53 by arthur            #+#    #+#             */
/*   Updated: 2024/02/05 16:31:23 by lle-saul         ###   ########.fr       */
>>>>>>> 61fe67aa2fb57ffbe7b16b3abf3f8b1f3a6738b8:rank3/minishell/src/build_in.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

<<<<<<< HEAD:rank 3/minishell/src/build_in.c
void	ft_pwd(char **tab)
{
	int i;
	char *tmp;
	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp_shell(tab[i], "PWD=") == 1)
		{
			tmp = tab[i];
			tmp += 4;
			printf("%s\n", tmp);
		}
		i++;
	}
}

=======
/*fonction pwd du shell*/
void	ft_pwd(void)
{
	char	path[1024];

	printf("%s\n", getcwd(path, 1024));
	g_res_error = 0;
}

/*/fonction echo du shell*/
>>>>>>> 61fe67aa2fb57ffbe7b16b3abf3f8b1f3a6738b8:rank3/minishell/src/build_in.c
void	ft_echo(char *line)
{
	char	**temp;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
<<<<<<< HEAD:rank 3/minishell/src/build_in.c
	temp = ft_split(line, " ");
	if (ft_strcmp_shell(temp[1], "-n") == 1)
=======
	temp = ft_split(line, " ", 0);
	if (ft_strcmp_shell(temp[1], "-n", 0) == 1)
>>>>>>> 61fe67aa2fb57ffbe7b16b3abf3f8b1f3a6738b8:rank3/minishell/src/build_in.c
	{
		i++;
		flag = 1;
	}
	while (temp[i] != NULL)
	{
		ft_putstr(temp[i], 1);
<<<<<<< HEAD:rank 3/minishell/src/build_in.c
		ft_putchar(' ', 1);
		i++;
	}
	if (flag == 0)
		ft_putchar('\n', 1);
=======
		i++;
		if (temp[i] != NULL)
			ft_putchar(' ', 1);
	}
	if (flag == 0)
		ft_putchar('\n', 1);
	ft_free_tab(temp);
	g_res_error = 0;
}

void	ft_unset(char ***tab, char *line)
{
	char	**temp;
	char	*name;
	int		index;
	int		i;

	i = 0;
	temp = ft_split(line, " ", 0);
	while (temp[i] != NULL)
	{
		name = get_var_name(temp[i]);
		index = is_exported(*tab, name, 1);
		if (index != -1)
			*tab = rm_index(*tab, index);
		i++;
	}
	ft_free_tab(temp);
	g_res_error = 0;
}

void	ft_export(char ***tab, char *line)
{
	char	**temp;
	int		i;

	temp = ft_split(line, " ", 0);
	i = 0;
	g_res_error = 0;
	if (temp[1] == NULL)
		print_export(*tab);
	while (temp[++i] != NULL)
	{
		if (ft_check_export(temp[i]) == 1)
		{
			free(temp[i]);
			g_res_error = 1;
			continue ;
		}
		ft_export_bis(tab, temp, i);
	}
	free(temp[0]);
	free(temp);
}

void	ft_cd(char ***tab, char **cmd)
{
	char	*home;
	int		export;

	set_pwd(tab);
	export = is_exported(*tab, "HOME", 0);
	home = NULL;
	if (cmd[1] == NULL)
	{
		if (export >= 0)
			home = get_var_value((*tab)[export]);
		if (home != NULL)
			chdir(home);
		update_pwd(tab);
		g_res_error = 0;
	}
	else if (cmd[2] == NULL)
		ft_cd_bis(tab, cmd);
	else
	{
		print_error("\033[1;91mminishell:\033[0;91m cd:\033[0m",
			" too many arguments !\n", NULL);
		g_res_error = 1;
	}
	free(home);
	ft_free_tab(cmd);
>>>>>>> 61fe67aa2fb57ffbe7b16b3abf3f8b1f3a6738b8:rank3/minishell/src/build_in.c
}

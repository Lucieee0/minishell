/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:49:49 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 17:15:02 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void execute_builtin(char *input, t_env **env_list, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	if (ft_strncmp(input, "env", 3) == 0)
		ft_env(env_list);
	else if (ft_strncmp(input, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(input, "exit", 5) == 0)
		ft_exit(env_list);
	else if (ft_strncmp(input, "echo", 4) == 0)
		ft_echo(input);
	else if ((ft_strncmp(input, "cd", 2) == 0))
		ft_cd(input, env_list);
	else
		printf("Command not found: %s\n", input);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:51:58 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 17:14:07 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void check_leaks(void)
{
    printf("\nChecking for memory leaks...\n");
    char command[256];
    sprintf(command, "leaks %d", getpid());
    system(command);
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	int			i;
	t_env *env_list = NULL;

	i = argc;
	create_env_list(&env_list, envp);
	while (1)
	{
		atexit(check_leaks);
		input = readline("minishell> ");
		if (!input)
			break ;
		execute_builtin(input, &env_list, argv, envp);
		free(input);
	}
	return (0);
}

// int main(int argc, char **argv, char **envp)
// {
// 	int i = 0;
// 	while (envp[i] != NULL)
// 	{
// 		printf("%s\n", envp[i]);
// 		i++;
// 	}
// 	return (0);
// }

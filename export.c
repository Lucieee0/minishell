/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:42:14 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 19:02:10 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

//Use export when you want to persist a variable to child processes from your current shell.
//Use env when you want to see or temporarily modify the environment for just one command.

//modify the env -> change the env, create a char **export
//so that it follows the ASCII order (like alphabetical order)
//also add the declare -x function in front
//do like for env but modify a bit

void	ft_export(t_env **env_list)
{
	(void)env_list;
	printf("export\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_env_failure_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:18:03 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 15:42:12 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	update_env_old(char *old_path, t_env **env_list)
{
	t_env	*current;

	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "OLDPWD=", 7) == 0)
		{
			free(current->str);
			current->str = ft_strjoin("OLDPWD=", old_path);
			break ;
		}
		current = current->next;
	}
	free(old_path);
}

void	update_env(t_env **env_list, char *path)
{
	t_env	*current;
	char	*old_path;

	old_path = NULL;
	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "PWD=", 4) == 0)
		{
			old_path = ft_strdup(current->str + 4);
			free(current->str);
			current->str = ft_strjoin("PWD=", path);
			break ;
		}
		current = current->next;
	}
	update_env_old(old_path, env_list);
}

void	access_failure(char *path)
{
	if (access(path, X_OK) == -1)
	{
		if (errno == ENOENT)
			printf("cd: no such file or directory: %s\n", path);
		else if (errno == EACCES)
			printf("cd: permission denied: %s\n", path);
		else if (errno == ENOTDIR)
			printf("cd: not a directory: %s\n", path);
		else
			printf("cd: access error for %s\n", path);
	}
}

void	chdir_failure(char *path)
{
	if (chdir(path) == -1)
	{
		if (errno == ENOENT)
			printf("cd: no such file or directory: %s\n", path);
		else if (errno == EACCES)
			printf("cd: permission denied: %s\n", path);
		else if (errno == ENOTDIR)
			printf("cd: not a directory: %s\n", path);
		else
			printf("cd: error changing directory to %s\n", path);
	}
}

void	free_input_array(char **input_array)
{
	int	i;

	i = 0;
	if (!input_array)
		return ;
	while (input_array[i])
	{
		free(input_array[i]);
		i++;
	}
	free(input_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:23:51 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/16 17:10:44 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

char *go_home_path(t_env **env_list)
{
	t_env *current = NULL;
	char *home_path = NULL;

	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "HOME=", 5) == 0)
		{
			home_path = current->str + 5;
			break ;
		}
		current = current->next;
	}
	return (home_path);
}

void	update_env(t_env **env_list, char *path)
{
	t_env *current = NULL;
	char *old_path = NULL;

	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "PWD=", 4) == 0)
		{
			old_path = ft_strdup(current->str + 4);
			free(current->str);
			current->str = ft_strjoin("PWD=", path);
		}
		current = current->next;
	}
	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "OLDPWD=", 7) == 0)
		{
			free(current->str);
			current->str = ft_strjoin("OLDPWD=", old_path);
		}
		current = current->next;
	}
	free(old_path);
}

char	*go_parent_path(t_env **env_list)
{
	t_env *current = NULL;
	char *old_path = NULL;
	char *new_path = NULL;
	int i = 0;
	int f = -1;

	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "PWD=", 4) == 0)
			old_path = ft_strdup(current->str + 4);
		current = current->next;
	}
	while (old_path[i] != '\0')
		i++;
	while (old_path[i] != '/')
		i--;
	new_path = (char *)malloc(sizeof(char) * (i + 1));
	while (f++ < (i - 1))
	{
		new_path[f] = old_path[f];
	}
	new_path[f] = '\0';
	free(old_path);
	return (new_path);
}

char	*go_previous_path(t_env **env_list)
{
	t_env *current = NULL;
	char *new_path = NULL;

	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "OLDPWD=", 7) == 0)
			new_path = ft_strdup(current->str + 7);
		current = current->next;
	}
	return (new_path);
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
	int	i = 0;

	if (!input_array)
		return ;
	while (input_array[i])
	{
		free(input_array[i]);
		i++;
	}
	free(input_array);
}

void	ft_cd(char *input, t_env **env_list)
{
	char **input_array;
	int				i;
	char *path = NULL;
	char	buffer[1024];

	i = 1;
	input_array = ft_split(input, ' ');
	printf("%s\n", getcwd(buffer, 1024));
	if (input_array[i] == NULL || ft_strncmp(input_array[i], "~", 1) == 0)
	{
		path = go_home_path(env_list);
		if (chdir(path) == -1)
			return (chdir_failure(path));
		update_env(env_list, path);
		printf("%s\n", getcwd(buffer, 1024));
	}
	else if (ft_strncmp(input_array[i], "..", 2) == 0)
	{
		path = go_parent_path(env_list);
		if (chdir("..") == -1)
		{
			free(path);
			return (chdir_failure(".."));
		}
		update_env(env_list, path);
		free(path);
		printf("%s\n", getcwd(buffer, 1024));
	}
	else if (ft_strncmp(input_array[i], "-", 1) == 0)
	{
		path = go_previous_path(env_list);
		if (chdir(path) == -1)
		{
			free(path);
			return (chdir_failure(path));
		}
		update_env(env_list, path);
		free(path);
		printf("%s\n", getcwd(buffer, 1024));
	}
	else if (access(input_array[i], X_OK) == 0)
	{
		if (chdir(input_array[i]) == -1)
			return (chdir_failure(input_array[i]));
		path = getcwd(buffer, 1024);
		update_env(env_list, path);
		printf("%s\n", getcwd(buffer, 1024));
	}
	else
		access_failure(input_array[i]);
	free_input_array(input_array);
}

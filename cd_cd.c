/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:23:51 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 15:33:32 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

void	ft_cd_home(t_env **env_list)
{
	char	*path;
	char	buffer[1024];

	path = NULL;
	path = go_home_path(env_list);
	if (chdir(path) == -1)
		return (chdir_failure(path));
	update_env(env_list, path);
	printf("%s\n", getcwd(buffer, 1024));
}

void	ft_cd_parent(t_env **env_list)
{
	char	*path;
	char	buffer[1024];

	path = NULL;
	path = go_parent_new_path(env_list);
	if (chdir("..") == -1)
	{
		free(path);
		return (chdir_failure(".."));
	}
	update_env(env_list, path);
	free(path);
	printf("%s\n", getcwd(buffer, 1024));
}

void	ft_cd_previous(t_env **env_list)
{
	char	*path;
	char	buffer[1024];

	path = NULL;
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

void	ft_cd(char *input, t_env **env_list)
{
	char	**input_array;
	int		i;
	char	*path;
	char	buffer[1024];

	path = NULL;
	i = 1;
	input_array = ft_split(input, ' ');
	printf("%s\n", getcwd(buffer, 1024));
	if (input_array[i] == NULL || ft_strncmp(input_array[i], "~", 1) == 0)
		ft_cd_home(env_list);
	else if (ft_strncmp(input_array[i], "..", 2) == 0)
		ft_cd_parent(env_list);
	else if (ft_strncmp(input_array[i], "-", 1) == 0)
		ft_cd_previous(env_list);
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

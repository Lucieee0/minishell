/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:18:30 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 15:42:02 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"

char	*go_home_path(t_env **env_list)
{
	t_env	*current;
	char	*home_path;

	current = NULL;
	home_path = NULL;
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

char	*go_parent_old_path(t_env **env_list)
{
	t_env	*current;
	char	*old_path;

	current = NULL;
	old_path = NULL;
	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "PWD=", 4) == 0)
			old_path = ft_strdup(current->str + 4);
		current = current->next;
	}
	return (old_path);
}

char	*go_parent_new_path(t_env **env_list)
{
	char	*old_path;
	char	*new_path;
	int		i;
	int		f;

	old_path = NULL;
	old_path = go_parent_old_path(env_list);
	new_path = NULL;
	i = 0;
	f = -1;
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
	t_env	*current;
	char	*new_path;

	current = NULL;
	new_path = NULL;
	current = *env_list;
	while (current)
	{
		if (ft_strncmp(current->str, "OLDPWD=", 7) == 0)
			new_path = ft_strdup(current->str + 7);
		current = current->next;
	}
	return (new_path);
}

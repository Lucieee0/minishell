/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:50:38 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/16 16:50:03 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structure.h"
//look for the parameters 
//create a linked list with them 

t_env	*create_env_node(char *string)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(string);
	new_node->next = NULL;
	return (new_node);
}

void	add_back_env(t_env **head, char *string)
{
	t_env	*current;
	t_env	*new_node;

	current = *head;
	new_node = create_env_node(string);
	if (!head || !new_node)
		return ;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	create_env_list(t_env **head, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		add_back_env(head, envp[i]);
		i++;
	}
}

char	**env_array(t_env **head)
{
	int		i;
	char	**my_env;
	t_env	*current;

	i = 0;
	current = *head;
	while (current)
	{
		current = current->next;
		i++;
	}
	my_env = malloc(sizeof(char *) * (i + 1));
	if (my_env == NULL)
		return (NULL);
	i = 0;
	current = *head;
	while (current)
	{
		my_env[i] = strdup(current->str);
		current = current->next;
		i++;
	}
	my_env[i] = NULL;
	return (my_env);
}

void	ft_env(t_env **env_list)
{
	char	**env_arr;
	int		i;
	int		f;

	i = 0;
	f = 1;
	env_arr = env_array(env_list);
	while (env_arr[i] != NULL)
	{
		printf("%d -> %s\n", f, env_arr[i]);
		f++;
		i++;
	}
}

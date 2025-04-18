/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusimon <lusimon@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:49:19 by lusimon           #+#    #+#             */
/*   Updated: 2025/04/18 17:22:31 by lusimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_lib/libft/libft.h"
#include "minishell_lib/ft_printf/ft_printf.h"
#include "minishell_lib/get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>

// #define REDIR_IN 1       // <
// #define REDIR_OUT 2      // >
// #define REDIR_APPEND 3   // >>
// #define REDIR_HEREDOC 4  // <<

// typedef struct s_redirection {
// 	char	*file;
// 	int		type;  // e.g., REDIR_IN <, REDIR_OUT >, REDIR_APPEND >>, REDIR_HEREDOC <<
// } t_redirection;

// typedef struct s_command {
// 	char			**argv;         // Null-terminated array of arguments (e.g., {"grep", "error", NULL})
// 	t_redirection	*redirs;        // List of t_redirection *
// } t_command;

// typedef struct s_list_pid {
// 	int	pid;
// 	struct s_list_pid *next;
// } t_list_pid;

// typedef struct s_cmd_table {
// 	t_command	*commands;          // List of t_command *, each one a simple command in a pipeline
// 	int			**pipes;            // File descriptors for inter-command pipes (nbr of pipes = commands - 1)
// 	t_list_pid	*pids;              // PIDs of forked child processes (nbr of pids == nbr of commands)
// 	int			return_value;       // Last command's return value, exit status of the last command (used for $? error handling)
// } t_cmd_table;

typedef struct s_env
{
	char 		 *str;
	struct s_env *next;
} t_env;

//pwd.c
void	ft_pwd(void);

//env.c
t_env *create_env_node(char *string);
void add_back_env(t_env **head, char *string);
void create_env_list(t_env **head, char **env);
char **recreate_env(t_env **head);
void	ft_env(t_env **env_list);

//exit.c
void	ft_exit(t_env **env_list);

//echo.c
void	ft_echo(char *input);

//builtin.c
void execute_builtin(char *input, t_env **env_list, char **argv, char **envp);

//cd.c
//cd_path.c
char	*go_home_path(t_env **env_list);
char	*go_parent_old_path(t_env **env_list);
char	*go_parent_new_path(t_env **env_list);
char	*go_previous_path(t_env **env_list);
//cd_env_failure_free.c
void	update_env_old(char *old_path, t_env **env_list);
void	update_env(t_env **env_list, char *path);
void	access_failure(char *path);
void	chdir_failure(char *path);
void	free_input_array(char **input_array);
//cd_cd.c
void	ft_cd_home(t_env **env_list);
void	ft_cd_parent(t_env **env_list);
void	ft_cd_previous(t_env **env_list);
void	ft_cd(char *input, t_env **env_list);

//helper.c
void	free_array(char **input_array);
void	free_env(t_env **env);

//mini_shell.c
int	main(int argc, char **argv, char **env);

//t_list_pid *pids: linked list of pid. Works as a queue / FIFO data structure.
//Each time we fork(), we add a node at the back, we wait on dead child processes
//as long as the queue is not empty
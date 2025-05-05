/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closefds_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:34:43 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/30 15:10:50 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_fds(int fd1, int fd2)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close(fd2);
}

void	len_path(char **paths, char *command_path, char *command, int i)
{
	char	*p;
	char	*q;

	p = command_path;
	q = paths[i];
	while (*q)
		*p++ = *q++;
	*p++ = '/';
	q = command;
	while (*q)
		*p++ = *q++;
	*p = '\0';
}

char	*result_path(char **paths, char *command, char *command_path)
{
	char	*result;
	int		i;

	result = NULL;
	i = -1;
	while (paths[++i])
	{
		len_path(paths, command_path, command, i);
		if (access(command_path, X_OK) == 0)
		{
			result = ft_strdup(command_path);
			break ;
		}
	}
	return (result);
}

char	*find_command_path(char *command, char **envp)
{
	char	**paths;
	char	command_path[MAX_PATH_LENGTH];
	int		i;
	char	*result_f;

	if (command == NULL)
		return (NULL);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i], ':');
	if (!envp)
		return (NULL);
	result_f = result_path(paths, command, command_path);
	i = 0;
	while (paths[i])
		free (paths[i++]);
	free (paths);
	return (result_f);
}

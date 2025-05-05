/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:54:33 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/30 15:05:26 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error(-1);
	}
	if (execve(path, cmd, envp) == -1)
		error(-1);
}

void	child_process(char *argv, char **envp, int w)
{
	pid_t	pid;
	int		fd[2];
	char	**split_cmd;
	char	*path;

	if (pipe(fd) == -1)
		error(w);
	pid = fork();
	fork_err_bonus(pid, fd[0], fd[1], w);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		split_cmd = ft_split(argv, ' ');
		path = find_command_path(split_cmd[0], envp);
		close(fd[1]);
		exec_error(path, split_cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	deli_line(char *line, char *delimiter, int fd)
{
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
		&& line[ft_strlen(delimiter)] == '\n')
	{
		free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	here_doc(int argc, char *delimiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (argc < 6 || pipe(fd) == -1)
		error(-1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		line = get_next_line();
		while (line)
		{
			deli_line(line, delimiter, fd[1]);
			write(fd[1], line, ft_strlen(line));
			free(line);
			line = get_next_line();
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		nb_cmd;
	int		fd[2];

	if (argc < 5)
		error(-1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argv[1][8] == '\0')
	{
		nb_cmd = 3;
		here_doc(argc, argv[2]);
		fd[1] = open_file(argv[argc - 1], 0, 0);
	}
	else
	{
		nb_cmd = 2;
		fd[1] = open_file(argv[argc - 1], 1, 0);
		fd[0] = open_file(argv[1], 2, fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
	while (nb_cmd < argc - 2)
		child_process(argv[nb_cmd++], envp, fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	close_fds(fd[1], fd[0]);
	nb_cmd = fork();
	if (!nb_cmd)
		execute(argv[argc - 2], envp);
}

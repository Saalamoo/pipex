/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalamoo <saalamoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:44:34 by saalamoo          #+#    #+#             */
/*   Updated: 2024/01/26 16:15:20 by saalamoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "./libft/libft.h"

# ifndef MAX_PATH_LENGTH
#  define MAX_PATH_LENGTH 1024
# endif

void	len_path(char **paths, char *command_path, char *command, int i);
void	in_put(int fds[2], char *infile, char *cmd, char **envp);
void	out_put(int fds[2], char *outfile, char *cmd, char **envp);
void	exec_error(char *path, char **split_cmd, char **envp);
void	error_cmd(char *cmd, char *path);
void	free_char_array(char **array);
void	fork_err(pid_t pid);
char	*result_path(char **paths, char *command, char *command_path);
char	*find_command_path(char *command, char **envp);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	**ft_split(char const *s, char c);

#endif
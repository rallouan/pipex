/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:04:06 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/28 20:51:21 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipex	*ft_initialize(int argc, char **argv, char **env)
{
	t_pipex		*pipex;

	pipex = malloc(1 * sizeof(t_pipex));
	if (! pipex)
		return (NULL);
	pipex->fd_infile = open(argv[1], O_RDONLY);
	if (pipex->fd_infile == -1)
		perror("infile");
	pipex->fd_outfile = open(argv[argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0666);
	if (pipex->fd_outfile == -1)
		perror("outfile");
	pipex->path = ft_split(path_parsing(env), ':');
	if (! pipex->path)
		perror("path");
	pipex->cmd1 = ft_split(argv[2], ' ');
	pipex->cmd2 = ft_split(argv[3], ' ');
	pipex->env = env;
	return (pipex);
}

char	*ft_find_cmd(char **path, char *command)
{
	char	*tmp;
	char	*cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		cmd = ft_strjoin(tmp, command);
		free (tmp);
		if (access(cmd, 0) == 0)
			return (cmd);
		free (cmd);
		path++;
	}
	return (NULL);
}

void	ft_free_pipex(t_pipex *pipex)
{
	close(pipex->fd_infile);
	close(pipex->fd_outfile);
	ft_free_all(pipex->path);
}

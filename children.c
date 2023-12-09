/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallouan <rallouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:30:28 by rallouan          #+#    #+#             */
/*   Updated: 2023/10/28 20:38:23 by rallouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipes[1], 1);
	close(pipex->pipes[0]);
	dup2(pipex->fd_infile, 0);
	cmd = ft_find_cmd(pipex->path, pipex->cmd1[0]);
	if (! cmd)
	{
		ft_free_all(pipex->cmd1);
		perror("Command Error");
		exit (1);
	}
	execve(cmd, pipex->cmd1, pipex->env);
	free (cmd);
}

void	ft_child_two(t_pipex *pipex)
{
	char	*cmd;

	dup2(pipex->pipes[0], 0);
	close(pipex->pipes[1]);
	dup2(pipex->fd_outfile, 1);
	cmd = ft_find_cmd(pipex->path, pipex->cmd2[0]);
	if (! cmd)
	{
		ft_free_all(pipex->cmd2);
		perror("Command Error");
		exit (1);
	}
	execve(cmd, pipex->cmd2, pipex->env);
	free (cmd);
}

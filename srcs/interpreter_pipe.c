/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:37:10 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/13 11:50:10 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int	exec_ast_pipe(t_ast *node, int inputfd, int outputfd)
{
	int	ret1;
	int	ret2;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		exit_error("pipe() error");
	ret1 = exec_ast(node->left, inputfd, pipefd[1]);
	ret2 = exec_ast(node->right, pipefd[0], outputfd);
	if (ret2 != 0)
		return (ret2);
	return (ret1);
}

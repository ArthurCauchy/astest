/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 11:37:10 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/11 11:37:11 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astest.h"

int	exec_ast_pipe(t_ast *node)
{
	int	ret1;
	int	ret2;

	ft_putendl("PIPE LEFT :");
	ret1 = exec_ast(node->left);
	ft_putendl("PIPE RIGHT :");
	ret2 = exec_ast(node->right);
	if (ret2 != 0)
		return (ret2);
	return (ret1);
}

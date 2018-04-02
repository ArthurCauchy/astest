/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:02 by acauchy           #+#    #+#             */
/*   Updated: 2018/04/02 13:58:30 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_ast	*new_ast_node(t_token token, char *arg)
{
	t_ast	*node;

	if (!(node = (t_ast*)malloc(sizeof(t_ast))))
		exit_error("malloc() error");
	node->token = token;
	node->arg = ft_strdup(arg);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void		syntax_analysis(t_word *wordlist, t_ast **root)
{
}

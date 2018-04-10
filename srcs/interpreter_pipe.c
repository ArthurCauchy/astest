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

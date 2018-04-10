#include "astest.h"

int	exec_ast_or(t_ast *node)
{
	int	ret1;
	int	ret2;

	ret1 = exec_ast(node->left);
	if (ret1 != 0)
	{
		ret2 = exec_ast(node->right);
		return (ret2);
	}
	return (0);
}

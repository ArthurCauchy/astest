#include "astest.h"

int	exec_ast_semicol(t_ast *node)
{
	int	ret;

	exec_ast(node->left);
	ret = exec_ast(node->right);
	return (ret);
}

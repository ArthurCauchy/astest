#include "astest.h"

int	exec_ast_arg(t_ast *node)
{
	t_word	*cur;

	cur = node->arglist;
	ft_putstr("exec : ");
	while (cur)
	{
		ft_putstr(cur->str);
		if (cur->next)
			ft_putchar(' ');
		cur = cur->next;
	}
	ft_putchar('\n');
	return (0);
}

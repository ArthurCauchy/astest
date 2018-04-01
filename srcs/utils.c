#include "astest.h"

void	exit_error(char *errmsg)
{
	if (errmsg)
	{
		ft_putendl_fd(errmsg, 2);
	}
	else
		ft_putendl_fd("Error.", 2);
	exit(1);
}

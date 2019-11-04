
#include "minishell.h"

void	print_input(unsigned char c) {
	if (is_ctrl_key(c))
	{
  		ft_putnbr(c);
		ft_putstr("\r\n");
	}
	else
	{
		ft_putnbr(c);
		ft_putstr(" (");
		ft_putchar(c);
		ft_putstr(")");
		ft_putstr("\r\n");
	}
}

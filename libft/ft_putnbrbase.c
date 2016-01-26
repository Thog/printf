#include <unistd.h>
#include "libft.h"

static void	ft_putnbrbase_inner(uintmax_t nbr, char *base, size_t baselen)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_inner(nbr / baselen, base, baselen);
		ft_putnbrbase_inner(nbr % baselen, base, baselen);
	}
	else
		ft_putchar(base[nbr]);
}

void		ft_putnbrbase(uintmax_t nbr, char *base)
{
	ft_putnbrbase_inner(nbr, base, ft_strlen(base));
}

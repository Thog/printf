#include "libft.h"

void		ft_putwstr(wchar_t *strr)
{
	while(*strr)
		ft_putwchar(*strr++);
}

#include "./libft/libft.h"

int		main(void)
{
	int i = 0;
	char **new = NULL;
	char *str = "\"ls\" \" ee\"-la \" \"   \"funk\"";

	new = ft_split_refill(str, '\"');
	while (new[i])
	{
		ft_putstr_fd(new[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	return (0);
}

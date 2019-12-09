#include <stdlib.h>

void	ft_arr_free(void **d_arr, int rows)
{
	while (--rows > -1)
	{
		free(d_arr[rows]);
	}
	free(d_arr);
}

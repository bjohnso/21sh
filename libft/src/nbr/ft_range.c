#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int*)malloc(sizeof(*arr) * (max - min));
	while (min < max)
		arr[i++] = min++;
	return (arr);
}

#include "libft.h"

float	ft_sqrtf(float x)
{
	float ret;

	ret = 1.0f;
	while (ABS((ret * ret) / x - 1.0f) >= 0.0000001f)
		ret -= (ret * ret - x) / (2 * ret);
	return (ret);
}

#include "../philosopher.h"

int ft_atoi(char *str)
{
    int i;
    int res;
    int sign;

    i = 0;
	sign = 0;
	while (str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
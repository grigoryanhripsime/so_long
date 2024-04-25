#include "so_long.h"

static int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*when_0(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		n_size;
	long	n1;

	if (n == 0)
		return (when_0());
	n1 = (long) n;
	n_size = n_len(n);
	str = (char *)malloc((n_size + 1) * sizeof(char));
	if (!str)
		return (0);
	str[n_size--] = '\0';
	if (n1 < 0)
	{
		n1 *= -1;
		str[0] = '-';
	}
	while (n1)
	{
		str[n_size--] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (str);
}
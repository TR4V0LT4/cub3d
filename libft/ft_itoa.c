/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:57:26 by yjaadoun          #+#    #+#             */
/*   Updated: 2021/11/29 13:11:29 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(int nb)
{
	int			count;
	long int	num;

	num = (long int)nb;
	count = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*ft_write(char *s, long m, int c)
{
	while (m != 0)
	{
		s[--c] = (char)((m % 10) + 48);
		m = m / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int			count;
	char		*str;
	int			sign;
	long int	nb;

	nb = (long int)n;
	count = count_nbr(nb);
	sign = 1;
	if (nb < 0)
	{
		sign = -1;
		nb *= -1;
		count += 1;
	}
	if (nb == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[count] = '\0';
	str = ft_write(str, nb, count);
	return (str);
}

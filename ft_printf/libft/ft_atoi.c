/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarcevs <gkarcevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:05:22 by gkarcevs          #+#    #+#             */
/*   Updated: 2024/06/22 13:21:06 by gkarcevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow( int base, int power)
{
	int	i;
	int	initial_base;

	initial_base = base;
	i = power;
	if (power == 0)
		return (1);
	while (i > 1)
	{
		base = base * initial_base;
		i--;
	}
	return (base);
}

static char	*build_nums(const char *str, int i, char *nums, int *nums_i)
{
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nums[(*nums_i)++] = str[i];
		else
			break ;
		i++;
	}
	nums[*nums_i] = '\0';
	return (nums);
}

static int	is_minus(const char *str, int minus_count, int *i)
{
	if (str[*i] == '-')
	{
		minus_count = 1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (minus_count);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		minus_count;
	char	nums[1024];
	int		nums_i;
	int		result;

	result = 0;
	nums_i = 0;
	i = 0;
	minus_count = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	minus_count = is_minus(str, minus_count, &i);
	build_nums(str, i, nums, &nums_i);
	i = ft_strlen(nums) -1 ;
	nums_i = 0;
	while (i >= 0)
		result += (nums[nums_i++] - 48) * (ft_pow(10, i--));
	if (minus_count == 1)
		return (result - (result * 2));
	return (result);
}

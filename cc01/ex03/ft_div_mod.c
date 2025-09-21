/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mju-ferr <mju-ferr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 09:19:30 by mju-ferr          #+#    #+#             */
/*   Updated: 2025/09/20 19:38:15 by mju-ferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 16;
	b = 0;
	ft_div_mod(a, b, &div, &mod);

	printf("Div of %d and %d is: %d\n", a, b, div);
	printf("Mod of %d and %d is: %d\n", a, b, mod);
}

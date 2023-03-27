/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:27:37 by lle-bret          #+#    #+#             */
/*   Updated: 2023/03/27 13:48:59 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_double_vect	scalar_mult(t_double_vect v, double lambda)
{
	v.x *= lambda;
	v.y *= lambda;
	return (v);
}

t_double_vect	comp_mult(t_double_vect u, t_double_vect v)
{
	t_double_vect	res;

	res.x = u.x * v.x;
	res.y = u.y * v.y;
	return (res);
}

double	scalar_product(t_double_vect u, t_double_vect v)
{
	return (u.x * v.x + u.y * v.y);
}

t_double_vect	vect_sum(t_double_vect u, t_double_vect v)
{
	t_double_vect	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	return (res);
}

t_double_vect	set_vect(double x, double y)
{
	t_double_vect v;

	v.x = x;
	v.y = y;
	return (v);
}

t_double_vect	step(t_double_vect v)
{
	t_double_vect	i;

	i.x = (v.x >= 0) - (v.x < 0);
	i.y = (v.y >= 0) - (v.y < 0);
	return(i);
}
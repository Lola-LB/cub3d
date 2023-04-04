/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:27:37 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/04 18:24:09 by lle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_double_vect	scalar_mult(t_double_vect v, double lambda)
{
	v.x *= lambda;
	v.y *= lambda;
	return (v);
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
	t_double_vect	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_double_vect	set_step(t_double_vect v)
{
	t_double_vect	i;

	i.x = (v.x >= 0) - (v.x < 0);
	i.y = (v.y >= 0) - (v.y < 0);
	return (i);
}

t_double_vect	rotate_vect(t_data *data, t_double_vect vect, int left)
{
	t_double_vect	new_vect;

	if (left)
	{
		new_vect.x = data->rc->rot.x * vect.x
			- data->rc->rot.y * vect.y;
		new_vect.y = data->rc->rot.y * vect.x
			+ data->rc->rot.x * vect.y;
	}
	else
	{
		new_vect.x = data->rc->rot.x * vect.x
			+ data->rc->rot.y * vect.y;
		new_vect.y = -data->rc->rot.y * vect.x
			+ data->rc->rot.x * vect.y;
	}
	return (new_vect);
}

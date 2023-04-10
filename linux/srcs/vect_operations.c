/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-bret <lle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:27:37 by lle-bret          #+#    #+#             */
/*   Updated: 2023/04/05 13:20:03 by lle-bret         ###   ########.fr       */
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

t_double_vect	rotate_vect(t_data *data, t_double_vect v, double alpha)
{
	t_double_vect	rot;
	t_double_vect	u;

	rot.x = cos(alpha * data->rotate_speed / (double) WINDOW_HEIGHT);
	rot.y = sin(alpha * data->rotate_speed / (double) WINDOW_HEIGHT);
	u.x = rot.x * v.x - rot.y * v.y;
	u.y = rot.y * v.x + rot.x * v.y;
	return (u);
}

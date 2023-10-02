/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:01:36 by victofer          #+#    #+#             */
/*   Updated: 2023/10/02 11:39:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_vector	sum_vectors(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	return (result);
}

t_vector	sub_vectors(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	return (result);
}

t_player	get_cam(t_core core, t_player pl)
{
	t_vector	res;

	res = sum_vectors(core.player.pos, core.player.direction);
	res = sub_vectors(res, core.player.plane);
	pl.cam_start = res;
	res = sum_vectors(core.player.pos, core.player.direction);
	res = sum_vectors(res, core.player.plane);
	pl.cam_end = res;
	res = sum_vectors(core.player.pos, core.player.direction);
	pl.cam_center = res;
	return (pl);
}

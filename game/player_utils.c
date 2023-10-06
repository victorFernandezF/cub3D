/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:01:36 by victofer          #+#    #+#             */
/*   Updated: 2023/10/06 10:09:40 by victofer         ###   ########.fr       */
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

	res = sum_vectors(core.player.pos, core.player.dir);
	res = sub_vectors(res, core.player.plane);
	pl.cam.start = res;
	res = sum_vectors(core.player.pos, core.player.dir);
	res = sum_vectors(res, core.player.plane);
	pl.cam.end = res;
	res = sum_vectors(core.player.pos, core.player.dir);
	return (pl);
}

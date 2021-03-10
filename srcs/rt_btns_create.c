/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:10:30 by belhatho          #+#    #+#             */
/*   Updated: 2021/03/09 15:10:39 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <rt.h>



void		square_fill(t_rt *data, int color, t_vec pos, t_vec size)
{
	int		i;
	int		j;

	i = (int)pos.x - 1;
	while (++i < (int)size.x)
	{
		j = pos.y - 1;
		while (++j < size.y)
			mlx_pixel_put(data->mlx, data->win, i, j, color);
	}
}

void		square_str(t_rt *data, char *str, t_vec pos, t_vec size)
{
	t_vec	t;

	t.x = pos.x + 10;
	t.y = pos.y + 10;
	mlx_string_put(data->mlx, data->win, t.x, t.y, 0xFFFFFF, str);
}

void		ctrl_name(t_rt *data)
{
	square_fill(data, 0xeeeeee00, (t_vec){700, 10}, (t_vec){900, 50});
	// ft_putendl(data->scene->sl_obj->name);
	//mlx_string_put(data->mlx, data->win, 750, 20, 0xFFFFFF, data->scene->sl_obj->name);
	square_str(data, data->scene->sl_obj->name , (t_vec){700, 10}, (t_vec){900, 50});
}

void	swap_void(void *dflt, void *img, size_t n)
{
	void *p;

	// p = malloc(n);
	// ft_memcpy(p, dflt, n);
	// ft_memcpy(dflt, img, n);
	// ft_memcpy(img, p, n);
	// free(p);
	p = dflt;
	dflt = img;
	img = p;
}

void	swap_button_by_id(int	id, t_rt *rt)
{
	// swap_void(rt->bt[id]->deflt_data, rt->bt[id]->img_data,
	// sizeof(int) * rt->bt[id]->w * rt->bt[id]->h);
	void *p;
	p = rt->bt[id]->data_data;
	rt->bt[id]->data_data = rt->bt[id]->img;
	rt->bt[id]->img = p;
	mlx_put_image_to_window(rt->mlx, rt->win, rt->bt[id]->data_data, (int)rt->bt[id]->pos.x, (int)rt->bt[id]->pos.y);	
}

t_button	*save_button(t_rt *rt)
{
	t_button *ret;

	ret = (t_button *)malloc(sizeof(t_button));
	ret->name = ft_strdup("save");
	ret->pos = vec(1270, 752, 0);
	ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/save0.xpm", &ret->w, &ret->h);
	ret->img = mlx_xpm_file_to_image(rt->mlx ,"buttons/save_no.xpm", &ret->w, &ret->h);
	ret->data_data = mlx_xpm_file_to_image(rt->mlx ,"buttons/save0.xpm", &ret->w, &ret->h);
	if (!ret->img || !ret->deflt || !ret->data_data)
	{
		rt_exit(rt, 0, "buttons : img unfound", EXIT_FAILURE);
	}
	ret->deflt_data = (int*)mlx_get_data_addr(ret->deflt, &ret->bpp, &ret->size, &ret->endian);
	ret->img_data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	ret->data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	mlx_put_image_to_window(rt->mlx, rt->win, ret->deflt, (int)ret->pos.x, (int)ret->pos.y);
	return (ret);
}

t_button	*mvmnt_button(t_rt *rt)
{
	t_button *ret;

	ret = (t_button *)malloc(sizeof(t_button));
	ret->name = ft_strdup("A_button");
	ret->pos = vec_add(rt->btns_up, vec(15, 10, 0));
	ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/stop.xpm", &ret->w, &ret->h);
	ret->img = mlx_xpm_file_to_image(rt->mlx ,"buttons/play.xpm", &ret->w, &ret->h);
	ret->data_data = mlx_xpm_file_to_image(rt->mlx ,"buttons/stop.xpm", &ret->w, &ret->h);
	ret->deflt_data = (int*)mlx_get_data_addr(ret->deflt, &ret->bpp, &ret->size, &ret->endian);
	ret->img_data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	ret->data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	mlx_put_image_to_window(rt->mlx, rt->win, ret->deflt, (int)ret->pos.x, (int)ret->pos.y);
	return (ret);
}

t_button	*cam_button(t_rt *rt)
{
	t_button *ret;

	ret = (t_button *)malloc(sizeof(t_button));
	ret->name = ft_strdup("cam_button");
	ret->pos = vec_add(rt->btns_up, vec(25, 140, 0));
	ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/c_off0.xpm", &ret->w, &ret->h);
	ret->img = mlx_xpm_file_to_image(rt->mlx ,"buttons/c_on.xpm", &ret->w, &ret->h);
	ret->data_data = mlx_xpm_file_to_image(rt->mlx ,"buttons/c_off.xpm", &ret->w, &ret->h);
	ret->deflt_data = (int*)mlx_get_data_addr(ret->deflt, &ret->bpp, &ret->size, &ret->endian);
	ret->img_data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	ret->data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	mlx_put_image_to_window(rt->mlx, rt->win, ret->deflt, (int)ret->pos.x, (int)ret->pos.y);
	return (ret);
}


t_button	*light_button(t_rt *rt)
{
	t_button *ret;

	ret = (t_button *)malloc(sizeof(t_button));
	ret->name = ft_strdup("light_button");
	ret->pos = vec_add(rt->btns_up, vec(17, 250, 0));
	if (rt->scene->light)
		ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/lon.xpm", &ret->w, &ret->h);
	else
		ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/loff1.xpm", &ret->w, &ret->h);
	ret->img = mlx_xpm_file_to_image(rt->mlx ,"buttons/loff1.xpm", &ret->w, &ret->h);
	ret->data_data = mlx_xpm_file_to_image(rt->mlx ,"buttons/lon.xpm", &ret->w, &ret->h);
	ret->deflt_data = (int*)mlx_get_data_addr(ret->deflt, &ret->bpp, &ret->size, &ret->endian);
	ret->img_data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	ret->data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	mlx_put_image_to_window(rt->mlx, rt->win, ret->deflt, (int)ret->pos.x, (int)ret->pos.y);
	return (ret);
}


t_button	*damier_button(t_rt *rt)
{
	t_button *ret;

	ret = (t_button *)malloc(sizeof(t_button));
	ret->name = ft_strdup("damier_button");
	ret->pos = rt->btns_noi;
	ret->deflt = mlx_xpm_file_to_image(rt->mlx ,"buttons/damier.xpm", &ret->w, &ret->h);
	ret->img = mlx_xpm_file_to_image(rt->mlx ,"buttons/damier.xpm", &ret->w, &ret->h);
	ret->data_data = mlx_xpm_file_to_image(rt->mlx ,"buttons/damier.xpm", &ret->w, &ret->h);
	ret->deflt_data = (int*)mlx_get_data_addr(ret->deflt, &ret->bpp, &ret->size, &ret->endian);
	ret->img_data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	ret->data = (int*)mlx_get_data_addr(ret->img, &ret->bpp, &ret->size, &ret->endian);
	mlx_put_image_to_window(rt->mlx, rt->win, ret->deflt, (int)ret->pos.x, (int)ret->pos.y);
	return (ret);
}

void	create_buttons(int	size, t_rt *rt)
{
	t_button **b;

	rt->btns_up = vec (10, 100, 0);
	rt->btns_noi = vec(25, 470, 0);
	b = (t_button **)malloc(size * sizeof(t_button *));
	b[SAVE_BTN] = save_button(rt);
	b[MVT_BTN] = mvmnt_button(rt);
	b[CAM_BTN] = cam_button(rt);
	b[LGHT_BTN] = light_button(rt);
	b[DAME_BTN] = damier_button(rt);
	b[CIRC_BTN] = circles_button(rt);
	b[V1_BTN] = voronoi1_button(rt);
	b[V2_BTN] = voronoi2_button(rt);
	b[V3_BTN] = voronoi3_button(rt);
	rt->bt = b;
	rt->size_bt = size;
}

void	select_button(int x, int y, t_rt *rt)
{
	int i = 0;
	while (i < rt->size_bt)
	{
		if (((int)rt->bt[i]->pos.x <= x && x <= (int)rt->bt[i]->pos.x + rt->bt[i]->w) && ((int)rt->bt[i]->pos.y <= y && y <= (int)rt->bt[i]->pos.y + rt->bt[i]->h))
		{
			swap_void(rt->bt[i]->deflt_data, rt->bt[i]->img_data, sizeof(int) * rt->bt[i]->w * rt->bt[i]->h);
			mlx_put_image_to_window(rt->mlx, rt->win, rt->bt[i]->deflt, (int)rt->bt[i]->pos.x, (int)rt->bt[i]->pos.y);
		}
		i++;
	}
}



int		get_selected_button(int x, int y, t_rt *rt)
{
		int i = 0;
	while (i < rt->size_bt)
	{
		if (((int)rt->bt[i]->pos.x <= x && x <= (int)rt->bt[i]->pos.x + rt->bt[i]->w) && ((int)rt->bt[i]->pos.y <= y && y <= (int)rt->bt[i]->pos.y + rt->bt[i]->h))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

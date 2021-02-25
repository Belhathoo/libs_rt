/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_shading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belhatho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:54:57 by belhatho          #+#    #+#             */
/*   Updated: 2021/02/18 15:55:03 by belhatho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int				rt_shading(t_thread *th, t_hit record, t_light *l, t_vec lo, t_vec *col)
{
	t_hit	    rec;
	t_object	*o;
	t_vec	out_n;
	float	ior;
	t_ray	sr;


	sr = rt_ray(vec_add(record.p, vec_pro_k(lo, 0.001)), vec_unit(lo));

	if (rt_hit(th->rt->scene, &sr, &rec))
	{
		o = rec.curr_obj;
		if (o->refr == 0)
			return (1);
		else
		{
			rt_refraction(th, &sr, rec.curr_obj, MAX_DEPTH);
			if (th->rec.curr_obj == rec.curr_obj)
{				if (vec_dot(rec.ray->dir, vec_unit(vec_sub(rec.p, l->pos))) >= 0)
			{
				*col = vec_pro_k(vec3(1.0), vec_dot(rec.ray->dir,\
				vec_unit(vec_sub(rec.p, l->pos))));
				return(0);
			}
}				// {
				// 	*col = vec_add(*col, vec_pro_k(l->col,\
				// 	ffmax(0.0, vec_dot(rec.ray->dir, rec.n))));
				// 	return(1);
				// }
				else
					return (0);
		}
		// 	else
		// 		*col = vec_add(*col, vec_pro_k(*col, ffmax(0.0, vec_dot(sr.dir, lo))));
		// 		return (1);
		// }
	}
	return (0);
}

void			rt_ambient(t_light *l, t_hit rec, t_vec *col)
{
	t_object	*o;
	double		ia;
	t_vec		c;
	/*
	   recheck !!
	   */
	c = vec(0.0, 0.0, 0.0);
	o = rec.curr_obj;

	ia = 0.025;//th->rt->scene->ambient;
	*col = vec_pro_k(rec.col, ia);

	// ia *= (!l) ? 1 : l->intensity ;
	// if (!l)
	// 	*col = vec_prod(*col, vec_pro_k(o->mat.ka, ia));
	// else
	// 	*col = vec_prod(*col, vec_prod(l->col, vec_pro_k(o->mat.ka, ia)));
}

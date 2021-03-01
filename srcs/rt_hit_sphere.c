
#include <rt.h>

void		sphere_uv(t_object *o, t_hit *rec)
{
	double	phi;
	double	theta;
	t_vec	p;
    
 	 p = vec_pro_k(vec_sub(rec->p, o->pos), 1.0); 
	 p = vec(vec_dot(p, o->vec1), vec_dot(p, o->vec2), vec_dot(p, o->rot));
	phi = atan2(p.z, p.x);
	theta = asin(p.y / o->size);
	rec->u = (phi + M_PI) / (2.0 * M_PI); 
	rec->v = (theta + M_PI / 2.0) / M_PI ;
	rec->u = rt_frac(rec->u);
	rec->v = rt_frac(rec->v);
	return;
}

int     rt_sphere_params(t_object *obj, t_ray *ray, t_hit *rec)
{
	rec->or = vec_sub(ray->origin, obj->pos);
	rec->a = vec_dot(ray->dir, ray->dir);
	rec->b = 2.0 * vec_dot(rec->or, ray->dir); 
	rec->c = vec_dot(rec->or, rec->or) - (obj->size * obj->size);
	rec->delta = rec->b * rec->b - 4.0 * rec->a * rec->c;
	if (rec->delta >= 0.0)
	{
		rec->t0 = (-rec->b - sqrt(rec->delta)) / (2 * rec->a);
		rec->t1 = (-rec->b + sqrt(rec->delta)) / (2 * rec->a);
		(rec->t0 < rec->t1) ? 0 : ft_float_swap(&rec->t0, &rec->t1);
		return (1);
	}
	return (0);
}

int		rt_hit_sphere(t_object *obj, t_ray *ray, t_hit *rec)
{
	if (rt_sphere_params(obj, ray, rec))
	{
		if (obj->is_sliced == 1 && rt_slicing(obj, ray, rec) == 0)
			return (0);
		if (negative(rec) == 0)
			return (0);
		if (rec->t > EPS && rec->t < rec->closest)
		{
			rec->p = vec_ray(ray, rec->t);
			if (rec->t == obj->sl_sl)
				rec->n = vec_pro_k(obj->sl_vec , -1);
			else if (rec->t == rec->negative[1])
				rec->n = rec->negative_normal;
			else
				rec->n = vec_div_k(vec_sub(rec->p, obj->pos), obj->size);
			sphere_uv(obj, rec);
			return (1);
		}
	}
	return (0);
}
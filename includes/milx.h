/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anchenni <anchenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:37:03 by famacama          #+#    #+#             */
/*   Updated: 2021/05/04 12:43:30 by anchenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MILX_H
# define MILX_H

// #include "parse.h"
#include "../lib/libft/libft.h"
//#include "../lib/minilibx_mms/mlx.h"
#include "../lib/minilibx_opengl/mlx.h"
#include "ggl_mlx_define.h"


// typedef struct s_dir_vec
// {
//     double x;
//     double y;
// }               t_dir_vec;

// typedef struct s_vec2
// {
//     int       *vec;
// };              t_vec2;
// typedef struct s_vec
// {
//     float  x;
//     float  y;
// }               t_vec;

typedef struct s_param{
	int		x;
	int		y;
}              t_param;

typedef struct	s_img
{
    void        *img_ptr;
    int         *data;
    int         size_l;
    int         bpp;
    int         endian;
}				t_img;

// typedef struct s_param{
// 	int		xp;
// 	int		yp;
// 	char	str[3];
// }				t_param;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
    float         xp;
    float         yp;
    float       dxp;
    float       dyp;
    float       ap;
}				t_mlx;

t_img   g_img;
t_mlx   g_mlx;


# endif

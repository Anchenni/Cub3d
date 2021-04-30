/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:37:03 by famacama          #+#    #+#             */
/*   Updated: 2020/12/09 20:58:41 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MILX_H
# define MILX_H

// #include "parse.h"
#include "../lib/libft/libft.h"
//#include "../lib/minilibx_mms/mlx.h"
#include "../lib/minilibx_opengl/mlx.h"
#include "ggl_mlx_define.h"


typedef struct	s_img
{
    void        *img_ptr;
    int         *data;
    int         size_l;
    int         bpp;
    int         endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

t_img   g_img;
t_mlx   g_mlx;

int	close_program(void *param);

# endif

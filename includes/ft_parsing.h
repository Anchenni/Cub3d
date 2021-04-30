#ifndef FT_PARSING_H
# define FT_PARSING_H

// #include "parse.h"
#include "../lib/libft/libft.h"
//#include "../lib/minilibx_mms/mlx.h"
#include "../lib/minilibx_opengl/mlx.h"
#include "ggl_mlx_define.h"



typedef struct s_resolution
{
    int                width;
	int				  height;
}               t_resolution;

typedef struct s_color
{
    int r;
    int g;
    int b;
}              t_color;

typedef struct s_texture
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
}           t_texture;


char        **g_tab;
t_resolution  g_reso;
t_color       g_f;
t_color       g_c;
int           g_rows;
int           g_cols;
t_texture     g_texture;
#endif
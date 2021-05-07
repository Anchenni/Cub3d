#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../includes/milx.h"
#include "../includes/ft_parsing.h"
#include "../utils/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md

# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
#define PI 3.1415926535

void    draw_dir_ray(t_mlx *mlx, float angle, int x,int y)
{
   
    // float    ray_x;
    // float    ray_y;
    // double    dx;
    // double    dy;

    float    max_value;
    
    // ray_x = mlx->xp;
    // ray_y = mlx->yp;
    // printf("angle = %f\n", angle);
    mlx->dxp = cos(angle) * tan(mlx->xp/mlx->ap) - sin(angle) * tan(mlx->yp/mlx->ap);
    mlx->dyp = sin(angle) * tan(mlx->xp/mlx->ap) + cos(angle) * tan(mlx->yp/mlx->ap);
    
    max_value = fmax(fabs(mlx->dxp), fabs(mlx->dyp));
    //  printf("\nmax_value = %f\n",max_value);
    if (max_value != 0)
    {
        mlx->dxp /= max_value;
        mlx->dyp /= max_value;
    }
    


    while (1)
    {
        //  printf("1helo\n");
        //  printf("ray_x = %f and ray_y = %f\n", mlx->xp, mlx->yp);
        if (mlx->img.data[y * g_reso.width + x] != 0x0000FF){
            // printf("hhhhh\n");
            mlx->img.data[y * g_reso.width + x] =  0xFF0000;
        }
        // if (mlx->img.data[g_reso.width * (int)floor(ray_y) + (int)floor(ray_x)] != 0x0000FF)
        //         mlx->img.data[g_reso.width * (int)floor(ray_y) + (int)floor(ray_x)] = 0xFF0000;
        else
            break;
        

        mlx->xp += mlx->dxp;
        mlx->yp += mlx->dyp;
        // printf("dx = %f and dy = %f\n", mlx->dxp, mlx->dyp);
        //  printf("2helo\n");
    }
    
}
 
// void    draw_ray(t_mlx *mlx)
// {
     
//     // double angle;
 
//     // angle = 0;
//     while (mlx->ap < PI/6)
//     {
         
//         draw_dir_ray(mlx, mlx->ap);
//         printf("2hey\n");
//         draw_dir_ray(mlx, -mlx->ap);
//         printf("3hey\n");
//         mlx->ap += PI/72;
//     }
//     // mlx_put_image_to_window(mlx->mlx, game->win, game->map_img.img, 0, 0);
// }
 
// void    rotate_matrix(t_mlx *mlx, float angle)
// {
    
//     float    tmp_x;
 
//     tmp_x = cos(angle) * mlx->xp - sin(angle) * mlx->yp;
//     mlx->yp = sin(angle) * mlx->xp + cos(angle) * mlx->yp;
//     mlx->xp = tmp_x;
// }

// float degToRad(int a) 
// {
//     return a*M_PI/180.0;
// }
// int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

int		deal_key(int key_code, t_mlx *mlx)
{
    // int a = 1;
	// printf("")
    if (key_code == KEY_A)
    {
        mlx->ap -= 0.1;
        if (mlx->ap < 0)
            mlx->ap += 2 * PI;
        mlx->dxp = cos(mlx->ap) * 5;
        mlx->dyp = sin(mlx->ap) * 5; 
        // rotate_matrix(mlx, PI/36);
    }
    
        // mlx->xp++;
    else if (key_code == KEY_D)
    {
        mlx->ap += 0.1;
        if (mlx->ap > 2 * PI)
            mlx->ap -= 2 * PI;
        mlx->dxp = cos(mlx->ap) * 5;
        mlx->dyp = sin(mlx->ap) * 5; 
        // rotate_matrix(mlx, -PI/36);
    }
        // mlx->xp--;
    else if (key_code == KEY_W)
    {
        mlx->xp -= mlx->dxp;
        mlx->yp -= mlx->dyp;
    }
        // mlx->yp++;
    else if (key_code == KEY_S)
    {
        mlx->xp += mlx->dxp;
        mlx->yp += mlx->dyp;
    }
        // mlx->yp--;
    else if (key_code == KEY_ESC)
		exit(0);
    
    
    printf("\ndxp = %f and dyp = %f\n", mlx->dxp, mlx->dyp);
    printf("xp: %f --", mlx->xp);
    printf("yp: %f\n", mlx->yp);
    printf("ap: %f\n", mlx->ap);
	return (0);
}


int	find_leng_d(size_t d)
{
	ssize_t	number;
    int value;

    value = 0;
	number = d;
	if (number <= -2147483647)
		value++;
	value = 0;
	if (number <= 0)
	{
		number *= -1;
		value = 1;
	}
	while (number > 0)
	{
		number /= 10;
		value++;
	}
	return (value);
}

void       check_r_f_c(char *line, int i)
{
    if (line[0] == 'R')
    {
        
        while (!ft_isdigit(line[i]))
            i++;
        g_reso.width = ft_atoi(line + i);
        g_reso.height = ft_atoi(line + 2 + find_leng_d(g_reso.width));
        // printf("\nreso h = %d and reso de w = %d\n", g_reso.height, g_reso.width);

    }
    else if ((line[0] == 'F' || line[0] == 'C'))
    {
        while (!ft_isdigit(line[i]) && line[i] != '-')
		    i++;
        // if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
        //     printf("error");
        if (line[0] == 'F')
            g_f.r = ft_atoi(line + i);
        else
            g_c.r = ft_atoi(line + i);
        while (ft_isdigit(line[i]))
            i++;
        while (!ft_isdigit(line[i]) && line[i] != '-')
            i++;
        // if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
        //     printf("error");
        if (line[0] == 'F')
            g_f.g = ft_atoi(line + i);
        else
            g_c.g= ft_atoi(line + i);
        while (ft_isdigit(line[i]))
            i++;
        while (!ft_isdigit(line[i]) && line[i] != '-')
            i++;
        // if (ft_atoi(line + i) > 255 || ft_atoi(line + i) < 0)
        //     printf("error");
        if (line[0] == 'F')
            g_f.b = ft_atoi(line + i);
        else
            g_c.b= ft_atoi(line + i);
    }
}

// char    ft_cpy_str(char *line, int i)
// {
//     char text_no[ft_strlen(line)];
//     int j;

//     j = 0;
//     while(line[i] != '\0')
//     {
//         text_no[j] = line[i];
//         i++;
//         j++;
//     }
//     text_no[j] = '\0';
//     return (text_no);
// }

void    check_texture(char *line)
{
    int i;
    int j;
    char text[ft_strlen(line)];
    // char text_so[ft_strlen(line)];
    i = 0;
    j = 0;
    if(line[0] == 'N' && line[1] == 'O')
    {
        i = 2;
        while(ft_strchr("\t\v\r\f ",line[i]))
            i++;
        while(line[i] != '\0')
        {
            text[j] = line[i];
            i++;
            j++;
        }
        text[j] = '\0';
        g_texture.no = text;
        
    }
    else if(line[0] == 'S' && line[1] == 'O')
    {
        i = 2;
        while(ft_strchr("\t\v\r\f ",line[i]))
            i++;
        while(line[i] != '\0')
        {
            text[j] = line[i];
            i++;
            j++;
        }
        text[j] = '\0';
        g_texture.so = text;
        // printf("\nso=%s\n", g_texture.so);
    }
    else if(line[0] == 'W' && line[1] == 'E')
    {
        i = 2;
        while(ft_strchr("\t\v\r\f ",line[i]))
            i++;
        while(line[i] != '\0')
        {
            text[j] = line[i];
            i++;
            j++;
        }
        text[j] = '\0';
        g_texture.we = text;
        // printf("\nwe=%s\n", g_texture.so);
    }
    else if(line[0] == 'E' && line[1] == 'A')
    {
        i = 2;
        while(ft_strchr("\t\v\r\f ",line[i]))
            i++;
        while(line[i] != '\0')
        {
            text[j] = line[i];
            i++;
            j++;
        }
        text[j] = '\0';
        g_texture.ea = text;
        // printf("\nwe=%s\n", g_texture.so);
    }
    else if(line[0] == 'S')
    {
        i = 1;
        while(ft_strchr("\t\v\r\f ",line[i]))
            i++;
        while(line[i] != '\0')
        {
            text[j] = line[i];
            i++;
            j++;
        }
        text[j] = '\0';
        g_texture.s = text;
    }
}


char					*ft_strsub(char *str, int start, int len)
{
	int					i;
	char				*output;

	i = 0;
	if (!str)
		return (NULL);
	if (!(output = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && (str[start + i] != '\n'))
	{
		output[i] = str[start + i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

int			count_char(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
void count_len_map(void)
{
	int i;
    int j;

	i = 0;
    while (g_tab[i])
    {
        j = 0;
        while (g_tab[i][j])
            j++;
        i++;
    }
	g_rows = i;
	g_cols = j;
}
void add_value_map(char *line, int fd)
{
    char *src;
    int r;
    int o;

    o = 1;
    src ="";
    src = ft_strjoin(src, line);
    src = ft_strjoin(src, "\n");
    while ((r = get_next_line(fd, &line)) || (o == 1))
    {
        src = ft_strjoin(src, line);
        src = ft_strjoin(src, "\n");

        if (r == 0)
        {
            g_tab = ft_split(src, '\n');
            o = 0;
        }
    }
    // printf("src = \n%s\n", src);
    // int i = 0;
    // int j = 0;
    // while (g_tab[i])
    // {
    //     j = 0;
    //     while (g_tab[i][j])
    //     {
    //         printf("--%c", g_tab[i][j]);
    //         j++;
    //     }
    //     printf("**\n");
    //     i++;
    // }
    count_len_map();
}
// void init_window(void)
// {
//     mlx.mlx_ptr = mlx_init();
//     g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_reso.width, g_reso.height, "cub3d");
// }

void	draw_rectangle(t_mlx *mlx, int x, int y)
{
    // printf("\nb\n");
	int i;
	int j;
	// float tile_size;

	// tile_size = 58;
    // tile_size = ((g_reso.height + g_reso.width) / (g_rows + g_cols));
	x *= tile_size;
	y *= tile_size;
	i = 0;
	// printf("test f\n");
	while (i < tile_size)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_size)
		{
			
			mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] = 0x0000FF;
			j++;
		}
		i++;
	}
}
// void			param_init(t_mlx *mlx)
// {
// 	mlx->xp = 0;
// 	mlx->yp = 0;
	
// }


void	draw_sprite(t_mlx *mlx, int x, int y)
{
    // printf("\nb\n");
	int i;
	int j;
	// float tile_size;

	// tile_size = 58;
    // tile_size = ((g_reso.height + g_reso.width) / (g_rows + g_cols));
	x *= tile_size;
	y *= tile_size;
	i = 0;
	// printf("test f\n");
	while (i < tile_size)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_size)
		{
			
			mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] = 0xFF0000;
			j++;
		}
		i++;
	}
}

void	draw_vide(t_mlx *mlx, int x, int y)
{
    // printf("\nb\n");
	int i;
	int j;
	// float tile_size;

	// tile_size = 58;
    // tile_size = ((g_reso.height + g_reso.width) / (g_rows + g_cols));
	x *= tile_size;
	y *= tile_size;
	i = 0;
	// printf("test f\n");
	while (i < tile_size)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_size)
		{
			
			mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] = 0x000000;
			j++;
		}
		i++;
	}
}
void	draw_position(t_mlx *mlx, float x, float y)
{
    // printf("\nb\n");
	int i;
	int j;
    // mlx->xp = x;
    // mlx->yp = y;
   
    // printf("\nx = %d and y = %d\n", x, y);
	int tile_sizee;
    // draw_rectangle(mlx, x, y);
	tile_sizee = 8;
   
    // tile_size = ((g_reso.height + g_reso.width) / (g_rows + g_cols));
	x *= tile_size - mlx->xp ;
	y *= tile_size - mlx->yp ;
	i = 0;
	// printf("test f\n");
    
	while (i < tile_sizee)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_sizee)
		{
			mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] = 0xFFD700;
			j++;
		}
		i++;
	}
    
    // printf("x: %d\n", mlx->xp);
    // printf("\ni = %d and j = %d\n", i, j);
}
void        draw_cam(t_mlx *mlx, float x, float y)
{
    

	int i = 0;
	int j = 0;
    // mlx->xp = x;
    // mlx->yp = y;
    
    // printf("\nx = %d and y = %d\n", x, y);
	int tile_sizee;
    // draw_rectangle(mlx, x, y);
	tile_sizee = 3;
    
    // tile_size = ((g_reso.height + g_reso.width) / (g_rows + g_cols));
	x  *= tile_size - mlx->xp - mlx->dxp;
    // x += mlx->dxp;
	y *= tile_size - mlx->yp  - mlx->dyp;
    while (1)
    {
        if (mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] != 0x0000FF)
            {
    // y += mlx->dyp;
                    i = 0;
    //                 x  *= tile_size - mlx->xp - mlx->dxp;
    // // x += mlx->dxp;
	//                 y *= tile_size - mlx->yp  - mlx->dyp;

    //  probleme vient de la !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    // if (mlx->ap < PI*2){
                    //     x = x - mlx->dxp ;
                    //     y = y - mlx->dyp ;
                    // }
                    // else if (mlx->ap > 0 ){
                    //     x = x + mlx->dxp ;
                    //     y = y + mlx->dyp ;
                    // }
                    // x++;
                    // y++;
                     
                    // printf("test f\n");
                    
                    while (i < tile_sizee)
                    {
                        
                        // printf("test g\n");
                        j = 0;
                        while (j < tile_sizee)
                        {
                            
                            mlx->img.data[(int)(y + i) * g_reso.width + (int)(x + j)] = 0xFF0000;
                            j++;
                        }
                        i++;
                    }
            }
            else
                break;
           x += mlx->dxp;
		   y += mlx->dyp;
    }
    // // printf("x: %d\n", mlx->xp);
    // printf("\ni = %d and j = %d\n", i, j);
}
void	draw_rectangles(t_mlx *mlx)
{
	int		i;
	int		j;
    float     a;
    float     b;
	i = 0;
	while (i < g_rows)                                                   
	{
		j = 0;
		while (j < g_cols)
		{    
			if (g_tab[i][j] == '1')
				draw_rectangle(mlx,j, i);
            else if (g_tab[i][j] == '0')
                draw_vide(mlx,j,i);
            else if (g_tab[i][j] == 'N')
            {
                draw_vide(mlx,j,i);
                // draw_position(mlx,j,i);
                 a = i;
                 b = j;
            }
            else if (g_tab[i][j] == '2')
                draw_sprite(mlx,j, i);  
			j++;
		}
		i++;
	}
    draw_position(mlx,b,a);
    // printf("dxp = %d and dyp = %d", mlx->dxp, mlx->dyp);
    // printf(" ici b = %d and a = %d\n", b,a);
    // while  (mlx->ap <  PI/ 6 )
    // {
    //     draw_dir_ray (mlx, mlx->ap, b,a);
    //     draw_dir_ray (mlx, -mlx->ap, b, a);
    //     mlx->ap +=  PI/ 72 ;
    // }
    draw_cam(mlx,b,a);
    

    
}
void			param_init(t_mlx *mlx)
{
	mlx->xp = 0;
	mlx->yp = 0;
    mlx->dxp = 0.198669;
    mlx->dyp = 0.198669;
    mlx->ap = 0.1;
	// param->str[0] = 'a';
	// param->str[1] = 'b';
	// param->str[2] = '\0';

}

int 	close()
{
		exit(0);
}

void	window_init(t_mlx *mlx)
{
    param_init(mlx);
	mlx->mlx_ptr = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx_ptr, g_reso.width, g_reso.height, "anwar");
}
void	img_init(t_mlx *mlx)
{
    mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, g_reso.width, g_reso.height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp, &mlx->img.size_l, &mlx->img.endian);
 
}

//Draw the line by DDA algorithm
void	draw_line(t_mlx *mlx, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		mlx->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_cols)
	{
		draw_line(mlx, i * tile_size, 0, i * tile_size, g_reso.height);
		i++;
	}
	draw_line(mlx, g_cols * tile_size - 1, 0, g_cols * tile_size - 1, g_reso.height);
	j = 0;
	while (j < g_rows)
	{
		draw_line(mlx, 0, j * tile_size, g_reso.width, j * tile_size);
		j++;
	}
	draw_line(mlx, 0, g_rows * tile_size - 1, g_reso.width, g_rows * tile_size - 1);
}

int		main_loop(t_mlx *mlx)
{

	draw_rectangles(mlx);
    // 
	draw_lines(mlx);
    
    // printf("hey\n");
    // draw_ray(mlx);
	//  printf("hey je suis passe pa r la\n");
    
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img.img_ptr, 0, 0);
	return (0);
}

int     main(int ac, char **av)
{
    int fd;
    int ret;
    char *line;
    int i;
    t_mlx mlx;
    

    i = 0;
    ret = 0;
	line = NULL;
    if (ac > 2 || ac < 2)
    {
        printf("Error\nMutch arg");
        return (0);
    }
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\ncannot open file", 0);
        return (0);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (ft_strchr("RFC", line[0]))
		{
			check_r_f_c(line, 0);

		}
        else if (ft_strchr("NSWES", line[0]))
        {
            check_texture(line);
        }
        else if (ft_strchr(line, '1'))
        {
            add_value_map(line,fd);
        }
	}
    param_init(&mlx);
    window_init(&mlx);
    img_init(&mlx);
        // printf("\ntile_size = %d\n",((g_reso.height + g_reso.width) / (g_rows + g_cols)));
    
	// mlx_hook(mlx.win, X_EVENT_KEY_EXIT, 0, &close, &mlx);
    mlx_hook(mlx.win, X_EVENT_KEY_PRESS, 0, &deal_key, &mlx);
    mlx_loop_hook(mlx.mlx_ptr, &main_loop, &mlx);
    mlx_loop(mlx.mlx_ptr);
    return (0);
}
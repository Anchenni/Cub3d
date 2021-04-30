#include <stdio.h>
#include "../includes/milx.h"
#include "../includes/ft_parsing.h"
#include "../utils/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
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
        // printf("\n!we=%s!\n", g_texture.so);
    }
}

// int     int_tab(char *line)
// {

// }

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
void init_window(void)
{
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_reso.width, g_reso.height, "cub3d");
}

void	draw_rectangle(int x, int y)
{
    printf("\nb\n");
	int i;
	int j;
	int tile_size;

	tile_size = 32;
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
			// printf("test h\n");
			// printf("y + i = %d\n", (y + i));
			// printf("x + j = %d\n", (x + j));
			// printf("===%d===\n", ((y + i) * g_dotcube.reso_w + (x + j)));
			g_mlx.img.data[(y + i) * g_reso.width + (x + j)] = 0xFFFFFF;
			// printf("test i\n");
			j++;
		}
		i++;
	}
}
void    draw_position(int x, int y)
{
//  printf("\nb\n");
	int i;
	int j;
	int tile_size;

	tile_size = 32;
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
			// printf("test h\n");
			// printf("y + i = %d\n", (y + i));
			// printf("x + j = %d\n", (x + j));
			// printf("===%d===\n", ((y + i) * g_dotcube.reso_w + (x + j)));
			g_mlx.img.data[(y + i) * g_reso.width + (x + j)] = 0x0000FF;
			// printf("test i\n");
			j++;
		}
		i++;
	}
}

void    draw_sprite(int x, int y)
{
//  printf("\nb\n");
	int i;
	int j;
	int tile_size;

	tile_size = 32;
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
			// printf("test h\n");
			// printf("y + i = %d\n", (y + i));
			// printf("x + j = %d\n", (x + j));
			// printf("===%d===\n", ((y + i) * g_dotcube.reso_w + (x + j)));
			g_mlx.img.data[(y + i) * g_reso.width + (x + j)] = 0xFF0000;
			// printf("test i\n");
			j++;
		}
		i++;
	}
}
void	draw_rectangles(void)
{
   
	int		i;
	int		j;

	i = 0;
	while (i < g_rows)                                                   
	{
        
		j = 0;
		while (j < g_cols)
		{
             
			if (g_tab[i][j] == '1'){
                 printf("\na\n");
				draw_rectangle(j, i);
            }
            // find position player if (ft_strchr("ENSW",g_tab[i][j])){
            //     draw_position()
            // }
            else if (g_tab[i][j] == '2')
                draw_sprite(j, i);
            else if (ft_strchr("NWES",g_tab[i][j]))
                draw_position(j, i);
			j++;
		}
		i++;
	}
}



int     main(int ac, char **av)
{
    int fd;
    int ret;
    char *line;
    // char tab[100][100];
    int i;
    int x;
	int y;
	int rows;
	int cols;
	int tile_size;

    
	tile_size = 32;
	
    // int j;
    // int old_len; 
    // int new_len;
    // tab = NULL;
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
        
       
        // else if (ft_strchr("012NWSE",line[0]) || ft_strchr("\t\v\r\f ", line[0]))
        else if (ft_strchr(line, '1'))
        {
        //      old_len = ft_strlen(line);
	    //     new_len = old_len - count_char(line, ' ');
	    //    tab = malloc(sizeof(char) * (new_len + 1));
                        
            // while(ft_strchr("\t\v\r\f ",line[i]))
            //     i++;
            add_value_map(line,fd);
            
        }

            // printf("\ni = %d\n", i);
        //     while(line[i] != '\0')
        //     {
        //         j = 0;
        //         while(line[j] != '\0')
        //         {
        //             tab[i][j] = line[j];
        //             printf("%c", tab[i][j]);
        //             j++;
        //         }
        //         printf("\n");
        //         tab[i][j] = '\0';
        //         i++;
        //         break;
        //     }   
        //     tab[i][j] = '\0';
        // }
        // printf("\n tab = %s\n", tab);
        
		// free(line);
	}
    // init_window();
    // g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_reso.width, g_reso.height, "cub3d");
    // g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_reso.width, g_reso.height);
    // g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
    // printf("\na\n");
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_reso.width, g_reso.height, "anwar");
    g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_reso.width, g_reso.height);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
    // printf("\nb\n");
    rows = g_reso.height / tile_size;
    // printf("\nreso h = %d and reso de w = %d\n", g_reso.height, g_reso.width);
	cols = g_reso.width / tile_size;
    x = 0;
    while (x < rows)
	{
        
		// printf("test b\n");
		y = 0;
		while (y < cols)
		{
			// printf("test c\n");
			// printf("g_cols = %d\n", g_cols);
			// printf("i = %d et j %d\n", i, j);
			// printf("g_tab de j = %c\n", g_tab[i][j]);
			if (g_tab[x][y] == '1')
			{
                
				// printf("test d\n");
				// printf("g_tab de j = %c\n", g_tab[i][j]);
				draw_rectangles();
				// printf("test e\n");
			}
			y++;
		}
		x++;
	}

    mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
    mlx_loop(g_mlx.mlx_ptr);
    return (0);
}
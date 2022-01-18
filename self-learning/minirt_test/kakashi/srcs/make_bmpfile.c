/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmpfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:36:39 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 16:37:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static int	create_file(char *name, int i, int j)
{
	char	*tmp;
	char	*bmpname;
	int		fd;

	i = get_file_name(name);
	bmpname = ft_strdup("images/");
	j = get_sub_len(&name[i]);
	tmp = ft_substr(name, i, j);
	name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	bmpname = ft_strjoin(bmpname, name);
	if (!((fd = open(bmpname, O_WRONLY | O_CREAT | O_TRUNC,
						S_IRWXU)) > 0))
		error_check(7, "bmp file can not open");
	printf("%s\n", bmpname);
	free(bmpname);
	return (fd);
}

static void	create_header(t_scene data, t_bmphead *header, t_dibhead *dib)
{
	header->type[0] = 0x42;
	header->type[1] = 0x4D;
	header->size = (data.xres * data.yres * 4) + 54;
	header->reserved = 0x00000000;
	header->offset = 0x36;
	dib->size = 40;
	dib->width = data.xres;
	dib->height = -data.yres;
	dib->colplanes = 1;
	dib->bpp = 32;
	dib->compression = 0;
	dib->img_size = (data.xres * data.yres * 4);
	dib->x_ppm = 2835;
	dib->y_ppm = 2835;
	dib->color_number = 0;
	dib->important_color = 0;
}

static void	write_header(int fd, t_bmphead header, t_dibhead dib)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &dib.size, 4);
	write(fd, &dib.width, 4);
	write(fd, &dib.height, 4);
	write(fd, &dib.colplanes, 2);
	write(fd, &dib.bpp, 2);
	write(fd, &dib.compression, 4);
	write(fd, &dib.img_size, 4);
	write(fd, &dib.x_ppm, 4);
	write(fd, &dib.y_ppm, 4);
	write(fd, &dib.color_number, 4);
	write(fd, &dib.important_color, 4);
}

static void	write_file(int fd, t_scene data, t_mlx mlx)
{
	char	*pixel_array;
	int		image_size;
	int		i;
	int		j;

	pixel_array = (char *)err_malloc(mlx.cam->size_line * data.yres);
	image_size = data.xres * data.yres;
	i = 0;
	j = 0;
	while (i < image_size)
	{
		pixel_array[j++] = mlx.cam->px_img[i] & 255;
		pixel_array[j++] = (mlx.cam->px_img[i] & 255 << 8) >> 8;
		pixel_array[j++] = (mlx.cam->px_img[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	write(fd, pixel_array, mlx.cam->size_line * data.yres);
	free(pixel_array);
}

void		make_bmp(t_mlx mlx, t_scene data, char *name)
{
	t_bmphead	header;
	t_dibhead	dib;
	int			fd;
	int			i;
	int			j;

	i = 0;
	j = 0;
	fd = create_file(name, i, j);
	create_header(data, &header, &dib);
	write_header(fd, header, dib);
	write_file(fd, data, mlx);
	close(fd);
}
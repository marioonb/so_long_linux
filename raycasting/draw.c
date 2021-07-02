/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*void			put_element(t_sl *sl)
{
	int			x;
	int			y;
	int			color;
	t_image		min;

	if (!(min.img = mlx_new_image(sl->mlx_ptr,
	(int)sl->resol.width/4, (int)sl->resol.heigth/4)))
		ft_error_div(8);
	min.adrr = mlx_get_data_addr(min.img, &min.bpx, &min.line_l, &min.endian);
	sl->minimap = min;
	color = create_rgb(0, 0, 0);
	y = 0;
	while (y < sl->map.lo)
	{
		x = 0;
		while (x++ < sl->map.la)
			if (sl->old_map.tabmap[y][x] == '1')
				image_pixel(&sl->minimap, x, y, color);
		y++;
	}
	mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
		sl->minimap.img, 0, 0);
}*/



int grep_color(t_texture *text, int x, int y)
{

char *dst;

if (x < 0)
	x = 0;
if (y < 0)
	y = 0;
if (x > text->width)
	x = text->width;
if (y > text->height)
	y = text->height;
dst = text->i.adrr + (y * text->i.line_l + x * text->i.bpx / 8);
return(*(unsigned int*)dst);

}
// cherche le ratio entre la taille et la taille des cases de la map

void fill_sprt_data(t_sl *sl, int i, int j, t_texture *text, int b) // i l emplacement de l element de la map ou on est actuellement, j idem
{
	float top_px;
	float bot_px;
	float case_hei;
	float case_wid;
	float pos_x;
	float text_x;
	float text_y;
	float x;
	float y;
	int color;
	//int background;
	float right_px;

	case_hei = sl->resol.heigth / sl->map.lo; //--> la case en hauteur est egal a la resol en longueur / le mnpmbre de ligne de la map
	case_wid = sl->resol.width / sl->map.la; // --> la case en largeur est egal a la resol en largeur / le nombre de colonne de la map
	right_px = case_wid;
	top_px = i * case_hei; //--> l empacment de l element dans la map fois le nombre de pixel par case --> donne le debut du dessin
	bot_px = (i + 1) * case_hei; // l enmplacement du dernier pixel du dessin
	//printf("la resol est de %d, %d", sl->resol.heigth, sl->resol.width);
	printf("la case doit etre de %f %f\n", case_hei, case_wid);
	//printf("la map est de %d, %d\n", sl->map.lo, sl->map.la);
	pos_x = j * case_wid; // -->
	//pos_x = j * (sl->resol.width / sl->map.la);
	x = -1;
	int k;

	while (pos_x + x < 0)
		x++;
	while (++x <= right_px)
	{
		printf("PIXEL_PUT ---- \n");
		text_x = x * (text->width / case_wid);  // L58
		//text_x = x * (sl->play.width / case_wid);  // L58
		y = top_px - 1;
		k = -1;
		while (++y < bot_px)
		{
			++k;
			text_y = (k * (text->height / case_hei));
			//text_y = (k * (sl->play.height / case_hei));
			if (text_y < 0)
				text_y = 0;
			int background = grep_color(text, 0, 0);; 
			color = grep_color(text, text_x, text_y);
			//color = grep_color(sl->play, 0, 0);
			if (color != background && b == 1 || b == 0)
			//	image_pixel(text.i.img, pos_x + x, y, color);
		//	if ((pos_x + x) >= 0 && (pos_x) + x <= sl->resol.width && y >= 0 && y <= sl->resol.heigth)

				image_pixel(&sl->img, pos_x + x, y, color);
				
	//			printf("BUG %d\n", (int)y);

		}
	}
	//printf("Les resol sont %d, %d\n", sl->resol.width, sl->resol.heigth);
}

void put_background(t_sl *sl)
{
//    t_image     img;
//    int         x;
//    int         y;
    int i = 0;
    int j = 0;	
	sl->img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width, sl->resol.heigth); /////
	sl->img.adrr = mlx_get_data_addr(sl->img.img, &sl->img.bpx, /////////////////
			&sl->img.line_l, &sl->img.endian); //////////////////////////////////
    //x = -1;
	//int ab = sl->resol.width / sl->map.la;
	//int or = sl->resol.heigth / sl->map.lo;
// int img_width;
// int img_height;
//	t_texture xxx;
//	sl->play.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/perso1.xpm", &sl->play.width, &sl->play.height);
//	sl->play.i.adrr = mlx_get_data_addr(sl->play.i.img, &sl->play.i.bpx, &sl->play.i.line_l, &sl->play.i.endian);
	//xxx.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/perso1.xpm", &xxx.width, &xxx.height);
	//xxx.i.adrr = mlx_get_data_addr(xxx.i.img, &xxx.i.bpx, &xxx.i.line_l, &xxx.i.endian);
	//sl->img = xxx.i;
	while (i < sl->map.lo)
	{
		j = 0;
		while (j < sl->map.la)
		{
			printf("\n\nc est a %d, %d \n", i, j);
           	if (sl->map.tabmap[i][j] == '0' || sl->map.tabmap[i][j] == 'P')
				fill_sprt_data(sl, i, j, &sl->back, 0);
			if (sl->map.tabmap[i][j] == 'P')
				fill_sprt_data(sl, i, j, &sl->play, 1);
			else if (sl->map.tabmap[i][j] == 'E')
				fill_sprt_data(sl, i, j, &sl->ex, 0);
			else if (sl->map.tabmap[i][j] == 'C')
				fill_sprt_data(sl, i, j, &sl->col, 0);
			else if (sl->map.tabmap[i][j] == '1')
				fill_sprt_data(sl, i, j, &sl->wal, 0);
            j++;
        }
    i++;
    }
	//mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
    //  		sl->img.img, 0, 0);
}




/*void            put_background(t_sl *sl)
{
    t_image     img;
    int         x;
    int         y;
    int i = 0;
    int j = 0;
    int yy;
    int l;
    int k;
    int jaune = create_rgb(255, 255, 0);
    int rouge = create_rgb(255, 0, 0);
    int     img_width;
    int     img_height;
    int ab = sl->resol.width / sl->map.la;
    int or = sl->resol.heigth / sl->map.lo;
    int xx = 0;
    //int vert = create_rgb(0, 128, 0);
    int gris = create_rgb(128, 128, 128);
    //dprintf (1,"ab = %d -- or == %d\n", ab, or);
    sl->color_ceiling.color_hex = create_rgb(250, 300, 150); // AJOUT
    int color = create_rgb(0,0,0);
    int color2 = create_rgb(250,250,250);
    x = -1;
    //if (!(img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width,
    //  sl->resol.heigth)))
    //  ft_error_div(8);
    //img.adrr = mlx_get_data_addr(img.img, &img.bpx, &img.line_l, &img.endian);
    //sl->img = img;
    //while (++x < sl->resol.width)
    x = 0;
    xx = 0;
    if (sl->point <= 0)
    {
        img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/dead.xpm", &img_width, &img_height);
        img.adrr = mlx_get_data_addr(img.img, &img.bpx,
        &img.line_l, &img.endian);
        sl->img = img;
        mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
        sl->img.img, 200, 200);
        mlx_string_put(sl->mlx_ptr, sl->win_ptr, 215, 298, rouge, "YOU DEAD !!!!");
    }
    else if (sl->loose == 1)
    {
        img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/loose.xpm", &img_width, &img_height);
        img.adrr = mlx_get_data_addr(img.img, &img.bpx,
        &img.line_l, &img.endian);
        sl->img = img;
        mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
        sl->img.img, 200, 200);
        mlx_string_put(sl->mlx_ptr, sl->win_ptr, 215, 298, rouge, "YOU LOOSE !!");
    }
        else if (sl->win == 1)
    {
        img.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/win.xpm", &img_width, &img_height);
        img.adrr = mlx_get_data_addr(img.img, &img.bpx,
        &img.line_l, &img.endian);
        sl->img = img;
        mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
        sl->img.img, 200, 200);
        mlx_string_put(sl->mlx_ptr, sl->win_ptr, 215, 298, rouge, "YOU WIN !!!!");
    }
    else{
            if (!(img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width,
        sl->resol.heigth)))
        ft_error_div(8);
    img.adrr = mlx_get_data_addr(img.img, &img.bpx, &img.line_l, &img.endian);
    sl->img = img;
         //
    while (x < sl->resol.heigth)
    {
        //printf("on passe a la ligne %d\n", x);
        j = 0;
        y = 0;
        while (y < sl->resol.width)// / 2)
        {
            if (j < sl->map.la && i < sl->map.lo)// && sl->map.tabmap[i][j] == '1')
            {
                l = 0;
                yy = y;
                xx = x;
                while (l < or)
                {
                    k = 0;
                    y = yy;
                    while (k < ab)
                    {
                        if (sl->map.tabmap[i][j] == '1')
                            image_pixel(&img, y, xx, color);
                        else if (sl->map.tabmap[i][j] == '0')
                            image_pixel(&img, y, xx, sl->color_ceiling.color_hex);
                        else if (sl->map.tabmap[i][j] == 'P')
                        	image_pixel(&img, y, xx, color2);
                        else if (sl->map.tabmap[i][j] == 'C')
                            image_pixel(&img, y, xx, jaune);
                        else if (sl->map.tabmap[i][j] == 'E')
                            image_pixel(&img, y, xx, gris);
                        else if (sl->map.tabmap[i][j] == 'X')
                            image_pixel(&img, y, xx, rouge);
                        y++;
                        k++;
                    }
                    l++;
                    xx++;
                }//
            }//
        j++;
        }
        i++;
        x = xx;
    }
    }//
    //put_element(sl);
    //put_minimap(sl);
    //exit(EXIT_SUCCESS);
    //ft_read_tab_char(sl->map.tabmap);
}*/

/*void			ft_draw_walls(t_sl *c)
{
	c->ray.y = c->ray.draw_start;
	if (c->ray.side == 0)
		c->ray.wall_x = c->player.y + c->ray.pwd * c->ray.raydir_y;
	else
		c->ray.wall_x = c->player.x + c->ray.pwd * c->ray.raydir_x;
	c->ray.wall_x -= floor((c->ray.wall_x));
	c->ray.textposx = (int)(c->ray.wall_x * (double)(64));
	if (c->ray.side == 0 && c->ray.raydir_x > 0)
		c->ray.textposx = 64 - c->ray.textposx - 1;
	if (c->ray.side == 1 && c->ray.raydir_y < 0)
		c->ray.textposx = 64 - c->ray.textposx - 1;
	c->ray.step = 1.0 * 64 / c->ray.line_heigth;
	c->ray.position = (c->ray.y - c->resol.heigth / 2 +
		c->ray.line_heigth / 2) * c->ray.step;
	while (++c->ray.y < c->ray.draw_end)
		calcul_wall_orientation(c);
}*/

/*void			calcul_wall_orientation(t_sl *c)
{
	c->ray.textposy = (int)c->ray.position & (64 - 1);
	c->ray.position += c->ray.step;
	if (c->ray.raydir_x > 0 && !c->ray.side)
		c->ray.color = my_mlx_pixel_get(c->player.i, c->ray.textposx,
			c->ray.textposy);
	if (c->ray.raydir_x < 0 && !c->ray.side)
		c->ray.color = my_mlx_pixel_get(c->t_so.i, c->ray.textposx,
			c->ray.textposy);
	if ((c->ray.raydir_x > 0 && c->ray.side && c->ray.raydir_y > 0)
		|| (c->ray.side && c->ray.raydir_y > 0))
		c->ray.color = my_mlx_pixel_get(c->t_ea.i, c->ray.textposx,
			c->ray.textposy);
	if ((c->ray.raydir_x > 0 && c->ray.side && c->ray.raydir_y < 0)
		|| (c->ray.side && c->ray.raydir_y < 0))
		c->ray.color = my_mlx_pixel_get(c->t_we.i, c->ray.textposx,
			c->ray.textposy);
	image_pixel(&c->img, c->ray.x, c->ray.y, c->ray.color);
}*/

/*void			put_minimap(t_sl *sl)
{
	int			x;
	int			y;
	int			color;
	t_image		min;

	if (!(min.img = mlx_new_image(sl->mlx_ptr,
		(int)sl->resol.width / 8, (int)sl->resol.heigth / 8)))
		ft_error_div(8);
	min.adrr = mlx_get_data_addr(min.img, &min.bpx, &min.line_l, &min.endian);
	sl->minimap = min;
	color = create_rgb(255, 0, 0);
	y = 0;
	while (y < sl->map.lo)
	{
		x = 0;
		while (x++ < sl->map.la)
			if (sl->old_map.tabmap[y][x] == '1')
				image_pixel(&sl->minimap, x, y, color);
		y++;
	}
	mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
		sl->minimap.img, 0, 0);
}*/

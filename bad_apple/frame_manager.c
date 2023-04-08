/*
** EPITECH PROJECT, 2023
** gol
** File description:
** frame manager
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gol.h"
#include "bad_apple.h"

void update_grid_to_frame(apple_t *apple, grid_t *grid, graphics_t *win)
{
    sfColor color;
    int width = 1920 / grid->cell->cell_size_x;
    int height = 1080 / grid->cell->cell_size_y;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            color = sfImage_getPixel(apple->frame, x * grid->cell->cell_size_x , y * grid->cell->cell_size_y);
            if (color.r >= 240 && color.g >= 240 && color.b >= 240)
                grid->grid[y][x] = 1;
            change_color(grid, y, x, sfWhite, sfBlack);
            sfRenderWindow_drawRectangleShape(win->window, grid->rect_array[y][x], NULL);
        }
    }
}

int set_frame(apple_t *apple)
{
    sfImage_destroy(apple->frame);
    my_int_to_str(apple->frame_nb, apple->nb_str);
    apple->path = strcpy(apple->path, "vid_frames/image-");
    apple->path = strcat(apple->path, apple->nb_str);
    apple->path = strcat(apple->path, ".png");
    apple->frame = sfImage_createFromFile(apple->path);
    if (apple->frame == NULL)
        return 84;
    apple->frame_nb++;
    return 0;
}
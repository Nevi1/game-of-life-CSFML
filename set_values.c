/*
** EPITECH PROJECT, 2023
** game of life
** File description:
** create_grid
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "gol.h"

int set_window(graphics_t *win)
{
    win->mode.width = 1920;
    win->mode.height = 1080;
    win->mode.bitsPerPixel = 32;
    win->window = sfRenderWindow_create(win->mode, "Game of Life",
    sfClose, NULL);
    if (!win->window)
        return 84;
    return 0;
}

void set_rect(grid_t *grid, int i, int j)
{
    sfVector2f size = {grid->cell->cell_size_x, grid->cell->cell_size_y};
    sfVector2f pos = {j * grid->cell->cell_size_x,
    i * grid->cell->cell_size_y};

    grid->rect_array[i][j] = sfRectangleShape_create();
    sfRectangleShape_setSize(grid->rect_array[i][j], size);
    sfRectangleShape_setPosition(grid->rect_array[i][j], pos);
    sfRectangleShape_setFillColor(grid->rect_array[i][j], sfWhite);
    if (grid->cell->cell_size_x > 10 && grid->cell->cell_size_y > 10) {
        sfRectangleShape_setOutlineThickness(grid->rect_array[i][j], 3);
        sfRectangleShape_setOutlineColor(grid->rect_array[i][j], sfBlack);
    }
}

void create_rect_array(grid_t *grid)
{
    grid->rect_array = malloc(sizeof(sfRectangleShape **) * grid->cells_y);
    for (int i = 0; i < grid->cells_y; i++) {
        grid->rect_array[i] =
        malloc(sizeof(sfRectangleShape *) * grid->cells_x);
        for (int j = 0; j < grid->cells_x; j++) {
            set_rect(grid, i, j);
        }
    }
}

void put_pattern(grid_t *grid, pattern_t *pattern, int i, int j)
{
    int mid_x = grid->cells_x / 2;
    int mid_y = grid->cells_y / 2;
    int pat_mid_x = 0;
    int pat_mid_y = 0;

    if (pattern != NULL) {
        pat_mid_x = pattern->size_x / 2;
        pat_mid_y = pattern->size_y / 2;
    }
    if (pattern->pattern_int != NULL
    && pattern->size_x <= grid->cells_x && pattern->size_y <= grid->cells_y
    && i >= mid_y - pat_mid_y && i <= mid_y + pat_mid_y
    && j >= mid_x - pat_mid_x && j <= mid_x + pat_mid_x) {
        grid->grid[i][j] = 
        pattern->pattern_int[i - (mid_y - pat_mid_y)][j - (mid_x - pat_mid_x)];
    } else {
        grid->grid[i][j] = 0;
    }
}

int set_grid(grid_t *grid, graphics_t *win, pattern_t *pattern)
{
    grid->cells_x = win->mode.width / grid->cell->cell_size_x + 1;
    grid->cells_y = win->mode.height / grid->cell->cell_size_y + 1;
    grid->grid = malloc(sizeof(int *) * grid->cells_y);
    for (int i = 0; i < grid->cells_y; i++) {
        grid->grid[i] = malloc(sizeof(int) * grid->cells_x);
        for (int j = 0; j < grid->cells_x; j++) {
            put_pattern(grid, pattern, i, j);
        }
    }
    return 0;
}

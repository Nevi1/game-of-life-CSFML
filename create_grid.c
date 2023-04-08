/*
** EPITECH PROJECT, 2023
** Game of life
** File description:
** grid
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/View.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "gol.h"

void free_grid(grid_t *grid)
{
    for (int i = 0; i < grid->cells_y; i++)
        free(grid->grid[i]);
    free(grid->grid);
}

void clear_grid(grid_t *grid)
{
    for (int i = 0; i < grid->cells_y; i++) {
        for (int j = 0; j < grid->cells_x; j++) {
            grid->grid[i][j] = 0;
        }
    }
}

void change_state(grid_t *grid, sfEvent *event)
{
    int i = event->mouseButton.y / grid->cell->cell_size_y;
    int j = event->mouseButton.x / grid->cell->cell_size_x;

    if (event->type == sfEvtMouseMoved) {
        i = event->mouseMove.y / grid->cell->cell_size_y;
        j = event->mouseMove.x / grid->cell->cell_size_x;
        if (sfMouse_isButtonPressed(sfMouseLeft) && i >= 0)
            grid->grid[i][j] = 1;
        if (sfMouse_isButtonPressed(sfMouseRight) && i >= 0)
            grid->grid[i][j] = 0;
    }
}

void change_color(grid_t *grid, int i, int j, sfColor alive, sfColor dead)
{
    if (grid->grid[i][j] == 0)
        sfRectangleShape_setFillColor(grid->rect_array[i][j], dead);
    else
        sfRectangleShape_setFillColor(grid->rect_array[i][j], alive);
}

void fill_grid(grid_t *grid, graphics_t *win, sfColor alive, sfColor dead)
{
    for (int i = 0; i < grid->cells_y; i++) {
        for (int j = 0; j < grid->cells_x; j++) {
            change_color(grid, i, j, alive, dead);
            sfRenderWindow_drawRectangleShape(win->window, grid->rect_array[i][j], NULL);
        }
    }
}
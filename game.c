/*
** EPITECH PROJECT, 2023
** game of life
** File description:
** Gameplay (or not)
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include "gol.h"

int count_neighbours(grid_t *grid, int **temp, int x, int y)
{
    int neighbours = 0;

    if (x > 0 && y > 0 && temp[y - 1][x - 1] == 1)
        neighbours++;
    if (y > 0 && temp[y - 1][x] == 1)
        neighbours++;
    if (x < grid->cells_x - 1 && y > 0 && temp[y - 1][x + 1] == 1)
        neighbours++;
    if (x > 0 && temp[y][x - 1] == 1)
        neighbours++;
    if (x < grid->cells_x - 1 && temp[y][x + 1] == 1)
        neighbours++;
    if (x > 0 && y < grid->cells_y - 1 && temp[y + 1][x - 1] == 1)
        neighbours++;
    if (y < grid->cells_y - 1 && temp[y + 1][x] == 1)
        neighbours++;
    if (x < grid->cells_x - 1 && y < grid->cells_y - 1 && temp[y + 1][x + 1] == 1)
        neighbours++;
    return neighbours;
}

int **copy_grid(grid_t *grid)
{
    int **tmp_grid = NULL;

    tmp_grid = malloc(sizeof(int *) * grid->cells_y);
    for (int i = 0; i < grid->cells_y; i++) {
        tmp_grid[i] = malloc(sizeof(int) * grid->cells_x);
        for (int j = 0; j < grid->cells_x; j++) {
            tmp_grid[i][j] = grid->grid[i][j];
        }
    }
    return tmp_grid;
}

void update_grid(grid_t *grid, int **tmp_grid, int i, int j)
{
    int neighbours = 0;

    neighbours = count_neighbours(grid, tmp_grid, j, i);
    if (tmp_grid[i][j] == 1 && (neighbours < 2 || neighbours > 3))
        grid->grid[i][j] = 0;
    if (tmp_grid[i][j] == 0 && neighbours == 3)
        grid->grid[i][j] = 1;
}

void next_iteration(grid_t *grid)
{
    int **tmp_grid = copy_grid(grid);
    for (int i = 0; i < grid->cells_y; i++) {
        for (int j = 0; j < grid->cells_x; j++) {
            update_grid(grid, tmp_grid, i, j);
        }
    }
}

void game_of_life(grid_t *grid, game_t *game)
{
    float timer = 0;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->running_speed < 10)
        timer = 1 - (float)game->running_speed / 10;
    else
        timer = 0.1 - (float)game->slow_speed / 100;
    if (timer < 0)
        timer = 0;
    if (game->is_playing == 1 && game->seconds > timer) {
        next_iteration(grid);
        sfClock_restart(game->clock);
    }
    if (game->is_playing == 0)
        sfClock_restart(game->clock);
}
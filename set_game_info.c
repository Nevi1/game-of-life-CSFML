/*
** EPITECH PROJECT, 2023
** Game of life
** File description:
** additional setting
*/

#include <stdlib.h>
#include <stdio.h>
#include "gol.h"

void set_game_info(game_t *game)
{
    game->is_playing = 0;
    game->is_running = 0;
    game->running_speed = 0;
    game->slow_speed = 0;
    game->nb_iterations = 0;
    game->seconds = 0;
}

void press_buttons(game_t *game, graphics_t *win, grid_t *grid, sfEvent *event)
{
    unsigned int mouseX = event->mouseButton.x;
    unsigned int mouseY = event->mouseButton.y;

    if (mouseX >= win->mode.width / 2 - 65 && mouseX <= win->mode.width / 2 - 65 + 100 
        && mouseY <= 100) {
        game->is_running = 1;
        if (game->is_playing == 0)
            game->is_playing = 1;
        else
            game->is_playing = 0;
    }
    if (mouseX >= win->mode.width / 2 + 30 && mouseX <= win->mode.width / 2 + 130
        && mouseY <= 100 && game->is_playing == 0)
            next_iteration(grid);
    if (mouseX >= win->mode.width / 2 - 180 && mouseX <= win->mode.width / 2 - 180 + 100
        && mouseY <= 100) {
            clear_grid(grid);
            game->is_playing = 0;
            game->is_running = 0;
        }
    if (mouseX >= win->mode.width / 2 + 140 && mouseX <= win->mode.width / 2 + 140 + 100
        && mouseY <= 100 && game->is_playing == 1 && game->slow_speed < 10) {
        if (game->running_speed < 10)
            game->running_speed += 1;
        else
            game->slow_speed += 1;
    }
    if (mouseX >= win->mode.width / 2 - 260 && mouseX <= win->mode.width / 2 - 260 + 100
        && mouseY <= 100 && game->running_speed > 0 && game->is_playing == 1) {
        if (game->slow_speed > 0)
            game->slow_speed -= 1;
        else
            game->running_speed -= 1;
        }
}
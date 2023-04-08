/*
** EPITECH PROJECT, 2023
** game of life
** File description:
** main file
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gol.h"

int set_all(grid_t *grid, graphics_t *win, game_t *game, pattern_t *pattern)
{
    game->clock = sfClock_create();
    set_window(win);
    set_grid(grid, win, pattern);
    create_rect_array(grid);
    set_buttons_textures(game);
    set_buttons_sprites(game);
    set_buttons_positions(game, win);
    set_game_info(game);
    return 0;
}

int help()
{
    printf("USAGE\n");
    printf("\t./my_gol [cell_size] [pattern] OR ./my_gol bad_apple\n\n");
    printf("PARAMETERS\n");
    printf("\tcell_size:\tsize of a cell in pixels, determines the grid size, must be higher than 3\n\n");
    printf("\tpattern:\tfile representing the initial state of the grid\n");
    printf("\t\t\tif not specified, the grid will be empty\n");
    printf("\t\t\tthe file must be a rectangle containing only 0s and 1s\n");
    printf("\t\t\t1s being alive cells and 0s being dead cells\n");
    printf("\t\t\tif the file contains a wrong pattern, the program will exit\n");
    printf("\t\t\tif the file is too large for the grid, the grid will be empty\n\n");
    printf("\tbad_apple:\tlaunch the bad apple video mixed with a game of life\n\n");
    printf("DESCRIPTION\n");
    printf("\tThis program simulates the game of life.\n");
    printf("\tIt is a cellular automaton, meaning that each cell is affected by its neighbors.\n");
    printf("\tEach cell has 8 neighbors, which are the cells directly above, below, left, right and diagonally adjacent to it.\n");
    printf("\tEach cell has 2 states: alive or dead.\n");
    printf("\tAt each iteration, the state of each cell is determined by the state of its neighbors.\n");
    printf("\tIf a cell is alive, it will stay alive if it has 2 or 3 alive neighbors.\n");
    printf("\tIf a cell is dead, it will come back to life if it has exactly 3 alive neighbors.\n\n");
    printf("CONTROLS\n");
    printf("\tMake the cell alive by clicking on it with the left mouse button\n");
    printf("\tMake the cell dead by clicking on it with the right mouse button\n");
    printf("\tYou can change the state of the cells while the simulation is running\n");
    printf("\tStart the simulation by clicking on the play button\n");
    printf("\tPause the simulation by clicking on the pause button\n");
    printf("\tReset the grid by clicking on the reset button\n");
    printf("\tChange the speed of the simulation by clicking on the speed buttons\n");
    printf("\tGo to the next iteration of the simulation by clicking on the button next to the play/pause button\n");
    printf("\tYou can't go to the next iteration while the simulation is running\n");

    return 0;
}

int main(int ac, char **av)
{
    graphics_t *win = malloc(sizeof(graphics_t));
    grid_t *grid = malloc(sizeof(grid_t));
    game_t *game = malloc(sizeof(game_t));
    pattern_t *pattern = malloc(sizeof(pattern_t));
    int cell_size = 0;

    game->visuals = malloc(sizeof(game_visuals_t));
    grid->cell = malloc(sizeof(cell_t));
    if (ac == 1) {
        printf("Use -h to see the help\n");
        return 84;
    }
    if (ac >= 2) {
        if (strcmp(av[1], "bad_apple") == 0)
            return bad_apple(win, grid);
        else if (strcmp(av[1], "-h") == 0)
            return help();
        else {
            cell_size = atoi(av[1]);
            if (cell_size <= 3)
                return 84;
            grid->cell->cell_size_x = cell_size;
            grid->cell->cell_size_y = cell_size;
        }
    }
    if (ac == 3)
        if (is_valid_map(av[2], pattern))
            return 84;
    set_all(grid, win, game, pattern);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        while (sfRenderWindow_pollEvent(win->window, &win->event)) {
            if (win->event.type == sfEvtClosed)
                sfRenderWindow_close(win->window);
            if (win->event.type == sfEvtMouseButtonPressed)
                press_buttons(game, win, grid, &win->event);
            change_state(grid, &win->event);
        }
        if (game->is_running == 1)
            game_of_life(grid, game);
        fill_grid(grid, win, sfBlack, sfWhite);
        display_sprites(game, win);
        sfRenderWindow_display(win->window);
    }
    sfRenderWindow_destroy(win->window);
    return 0;
}
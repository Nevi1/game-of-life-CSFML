/*
** EPITECH PROJECT, 2023
** Gol
** File description:
** bad_apple because its really funny
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

int set_apple(graphics_t *win, grid_t *grid, apple_t *apple)
{
    sfMusic *music = NULL;

    grid->cell->cell_size_x = 8;
    grid->cell->cell_size_y = 8;
    apple->frame_nb = 1;
    set_window(win);
    sfRenderWindow_setFramerateLimit(win->window, 30);
    set_grid(grid, win, malloc(sizeof(pattern_t)));
    create_rect_array(grid);
    set_frame(apple);
    music = sfMusic_createFromFile("assets/bad_apple_music.ogg");
    if (!music)
        return 84;
    sfMusic_play(music);
    return 0;
}

int bad_apple(graphics_t *win, grid_t *grid)
{
    apple_t *apple = malloc(sizeof(apple_t));
    apple->nb_str = malloc(sizeof(char) * 5);
    apple->path = malloc(sizeof(char) * 30);

    set_apple(win, grid, apple);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        while (sfRenderWindow_pollEvent(win->window, &win->event)) {
            if (win->event.type == sfEvtClosed)
                sfRenderWindow_close(win->window);
        }
        if (set_frame(apple) == 84)
            return 0;
        update_grid_to_frame(apple, grid, win);
        next_iteration(grid);
        sfRenderWindow_display(win->window);
    }
    sfRenderWindow_destroy(win->window);
    return 0;
}
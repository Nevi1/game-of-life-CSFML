/*
** EPITECH PROJECT, 2023
** game
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include "gol.h"

int set_buttons_textures(game_t *game)
{
    game->visuals->play_button_texture = sfTexture_createFromFile("assets/play.png", NULL);
    game->visuals->pause_button_texture = sfTexture_createFromFile("assets/pause.png", NULL);
    game->visuals->next_it_texture = sfTexture_createFromFile("assets/next.png", NULL);
    game->visuals->reset_button_texture = sfTexture_createFromFile("assets/reset.png", NULL);
    game->visuals->speed_button_texture = sfTexture_createFromFile("assets/fast.png", NULL);
    if (!game->visuals->play_button_texture ||
            !game->visuals->pause_button_texture ||
            !game->visuals->reset_button_texture ||
            !game->visuals->speed_button_texture ||
            !game->visuals->next_it_texture) {
        return 84;
    }
    return 0;
}

void set_buttons_sprites(game_t *game)
{
    game->visuals->play_button = sfSprite_create();
    game->visuals->pause_button = sfSprite_create();
    game->visuals->next_it = sfSprite_create();
    game->visuals->reset_button = sfSprite_create();
    game->visuals->speed_button = sfSprite_create();
    game->visuals->slow_button = sfSprite_create();
    sfSprite_setTexture(game->visuals->play_button,
        game->visuals->play_button_texture, sfTrue);
    sfSprite_setTexture(game->visuals->pause_button,
        game->visuals->pause_button_texture, sfTrue);
    sfSprite_setTexture(game->visuals->next_it,
        game->visuals->next_it_texture, sfTrue);
    sfSprite_setTexture(game->visuals->reset_button,
        game->visuals->reset_button_texture, sfTrue);
    sfSprite_setTexture(game->visuals->speed_button,
        game->visuals->speed_button_texture, sfTrue);
    sfSprite_setTexture(game->visuals->slow_button,
        game->visuals->speed_button_texture, sfTrue);
}

void set_buttons_positions(game_t *game, graphics_t *win)
{
    sfVector2f play_button_pos = {win->mode.width / 2 - 100, 0};
    sfVector2f pause_button_pos = {win->mode.width / 2 - 75, -10};
    sfVector2f next_it_pos = {win->mode.width / 2 + 30, 0};
    sfVector2f reset_button_pos = {win->mode.width / 2 - 180, 0};
    sfVector2f speed_button_pos = {win->mode.width / 2 + 130, 0};
    sfVector2f slow_button_pos = {win->mode.width / 2 - 260, 10};

    sfSprite_setPosition(game->visuals->play_button, play_button_pos);
    sfSprite_setScale(game->visuals->play_button, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(game->visuals->pause_button, pause_button_pos);
    sfSprite_setScale(game->visuals->pause_button, (sfVector2f){0.25, 0.25});
    sfSprite_setPosition(game->visuals->next_it, next_it_pos);
    sfSprite_setScale(game->visuals->next_it, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(game->visuals->reset_button, reset_button_pos);
    sfSprite_setScale(game->visuals->reset_button, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(game->visuals->speed_button, speed_button_pos);
    sfSprite_setScale(game->visuals->speed_button, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(game->visuals->slow_button, slow_button_pos);
    sfSprite_setOrigin(game->visuals->slow_button, (sfVector2f){200, 200});
    sfSprite_setRotation(game->visuals->slow_button, 180);
    sfSprite_setScale(game->visuals->slow_button, (sfVector2f){0.5, 0.5});
}

void display_sprites(game_t *game, graphics_t *win)
{
    if (game->is_playing == 1)
        sfRenderWindow_drawSprite(win->window, game->visuals->pause_button, NULL);
    else
        sfRenderWindow_drawSprite(win->window, game->visuals->play_button, NULL);
    sfRenderWindow_drawSprite(win->window, game->visuals->next_it, NULL);
    sfRenderWindow_drawSprite(win->window, game->visuals->reset_button, NULL);
    sfRenderWindow_drawSprite(win->window, game->visuals->speed_button, NULL);
    sfRenderWindow_drawSprite(win->window, game->visuals->slow_button, NULL);
}
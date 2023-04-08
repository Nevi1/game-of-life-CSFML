/*
** EPITECH PROJECT, 2023
** game of life
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#ifndef GOL_H
    #define GOL_H

    #define CELL_SIZE 8

    typedef struct game_visuals {
        sfTexture *play_button_texture;
        sfSprite *play_button;
        sfTexture *pause_button_texture;
        sfSprite *pause_button;
        sfTexture *next_it_texture;
        sfSprite *next_it;
        sfTexture *reset_button_texture;
        sfSprite *reset_button;
        sfTexture *speed_button_texture;
        sfSprite *speed_button;
        sfSprite *slow_button;
        sfText *nb_it;
    }game_visuals_t;

    typedef struct game {
        int is_running;
        int is_playing;
        int nb_iterations;
        int running_speed;
        int slow_speed;
        sfClock *clock;
        sfTime time;
        float seconds;
        game_visuals_t *visuals;
    }game_t;

    typedef struct pattern {
        char **pattern;
        int **pattern_int;
        int size_x;
        int size_y;
    }pattern_t;

    typedef struct cell {
        int state;
        float cell_size_x;
        float cell_size_y;
    }cell_t;

    typedef struct grid {
        int **grid;
        sfRectangleShape ***rect_array;
        int cells_x;
        int cells_y;
        cell_t *cell;
    }grid_t;
    
    typedef struct graphics {
        sfRenderWindow *window;
        sfVideoMode mode;
        sfEvent event;
        sfView *view;
    }graphics_t;

    int is_valid_map(char *, pattern_t *);
    void char_array_to_int_array(pattern_t *);
    void change_color(grid_t *, int, int, sfColor, sfColor);
    void fill_grid(grid_t *, graphics_t *, sfColor, sfColor);
    int set_grid(grid_t *, graphics_t *, pattern_t *);
    void create_rect_array(grid_t *);
    void change_state(grid_t *, sfEvent *);
    int set_window(graphics_t *);
    void set_buttons_sprites(game_t *);
    int set_buttons_textures(game_t *);
    void set_buttons_positions(game_t *, graphics_t *);
    void set_game_info(game_t *);
    void display_sprites(game_t *, graphics_t *);
    void press_buttons(game_t *, graphics_t *, grid_t *, sfEvent *);
    void clear_grid(grid_t *);
    void next_iteration(grid_t *);
    void game_of_life(grid_t *, game_t *);
    void set_camera(graphics_t *);
    void update_camera(graphics_t *);

    int bad_apple(graphics_t *, grid_t *);

#endif /* !GOL_H */

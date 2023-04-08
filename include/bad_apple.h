/*
** EPITECH PROJECT, 2023
** bad_apple
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>


#ifndef BAD_APPLE_H
    #define BAD_APPLE_H

    typedef struct apple {
        sfImage *frame;
        int frame_nb;
        char *path;
        char *nb_str;
    } apple_t;

    char *my_int_to_str(int, char *);
    void update_grid_to_frame(apple_t *, grid_t *, graphics_t *);
    int set_frame(apple_t *);
#endif /* !BAD_APPLE_H */

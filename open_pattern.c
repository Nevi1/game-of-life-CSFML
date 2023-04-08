/*
** EPITECH PROJECT, 2023
** gol
** File description:
** open pattern
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gol.h"

void print_char_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        printf("%s", array[i]);
}

void print_int_array(int **array, int size_x, int size_y)
{
    for (int i = 0; i < size_y; i++) {
        for (int j = 0; j < size_x; j++)
            printf("%d", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

int open_map(char *filepath, pattern_t *pattern)
{
    FILE *file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;

    if (file == NULL)
        return 0;
    pattern->size_x = 0;
    pattern->size_y = 0;
    pattern->pattern = malloc(sizeof(char *) * 1);
    for (int i = 0; getline(&line, &len, file) != -1; i++) {
        pattern->pattern[i] = malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(pattern->pattern[i], line);
        pattern->pattern = realloc(pattern->pattern, sizeof(char *) * (i + 2));
        pattern->size_y += 1;
    }
    pattern->pattern[pattern->size_y] = NULL;
    fclose(file);
    return 1;
}

int is_valid_char(char *str, int width)
{
    for (int i = 0; i < width; i++)
        if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != '\0')
            return 0;
    return 1;
}

void char_array_to_int_array(pattern_t *pattern)
{
    pattern->pattern_int = malloc(sizeof(int *) * (pattern->size_y + 1));
    for (int i = 0; i < pattern->size_y; i++) {
        pattern->pattern_int[i] = malloc(sizeof(int) * (pattern->size_x + 1));
        for (int j = 0; j < pattern->size_x; j++)
            pattern->pattern_int[i][j] = pattern->pattern[i][j] - '0';
        pattern->pattern_int[i][pattern->size_x] = 0;
    }
}

int is_valid_map(char *filepath, pattern_t *pattern)
{
    int len = 0;

    if (open_map(filepath, pattern) == 0)
        return 84;
    if (pattern->size_y == 0)
        return 84;
    pattern->size_x = strlen(pattern->pattern[0]) - 1;
    for (int i = 0; i < pattern->size_y; i++) {
        len = strlen(pattern->pattern[i]) - 1;
        if (len != pattern->size_x)
            return 84;
        if (is_valid_char(pattern->pattern[i], pattern->size_x) == 0)
            return 84;
    }
    char_array_to_int_array(pattern);
    return 0;
}

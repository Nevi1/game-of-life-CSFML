/*
** EPITECH PROJECT, 2022
** itn to str
** File description:
** lib
*/

char *my_int_to_str(int nbr, char *contain)
{
    int len = 0;
    int tmp = nbr;
    int i = 0;

    while (tmp > 0) {
        tmp /= 10;
        len++;
    }
    for (i = 0; i < len; i++){
        contain[len - 1 - i] = nbr % 10 + '0';
        nbr /= 10;
    }
    contain[i] = '\0';
    return contain;
}

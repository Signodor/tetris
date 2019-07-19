/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** change_highscore
*/

#include "prototypes.h"

int compt_int_len(int x)
{
    if (x == 0)
        return (1);
    int j = 0;
    for (; x > 0; j++)
        x = x / 10;
    return (j);
}

char *int_in_char(int score)
{
    int len_score = compt_int_len(score);
    char *string = malloc(sizeof(char) * len_score + 1);

    for (int i = 0; i <= len_score - 1; i++) {
        string[len_score - i - 1] = score % 10 + 48;
        score = score / 10;
    }
    string[len_score] = '\0';
    return (string);
}

void create_highscore(void)
{
    int fd = open("highscore.txt", O_WRONLY | O_CREAT, 0666);

    write(fd, "0", 1);
    close(fd);
}

int recup_highscore(void)
{
    int fd = open("highscore.txt", O_RDONLY);
    char *ret = my_strdup("");
    char *fin;
    char buf[2] = {0};
    int i = 0;
    int highscore;

    if (fd == -1) {
        create_highscore();
        fd = open("highscore.txt", O_RDONLY);
    }
    while (read(fd, buf, 1)) {
        fin = my_strconcat(ret, buf);
        free(ret);
        ret = fin;
    }
    highscore = my_getnbr(ret);
    free(ret);
    close(fd);
    return (highscore);
}

void change_highscore(tetris_t *player)
{
    int fd = open("highscore.txt", O_WRONLY);

    if (player->score == player->highscore) {
        write(fd, int_in_char(player->highscore),
        compt_int_len(player->highscore));
    }
    close(fd);
}
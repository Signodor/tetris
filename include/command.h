/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "vector.h"

typedef enum
{
    RSTANDARD,
    RFILE,
    RPIPE,
} redir_t;

typedef struct
{
    redir_t type;

    char append;
    char *filename;

    struct command *to;

    int fd;
} redirect_t;

enum
{
    BUILTIN,
    BINARY,
    PROGRAM,
};

typedef struct command
{
    char *brut;
    vector_t *args;
    char *path;

    int type;

    redirect_t in;
    redirect_t out;

    pid_t pid;
} command_t;

int divise_commands(char *command, vector_t *vec);

command_t *command_create(char *content, command_t *in,
vector_t *env, vector_t *pipefd);

int command_parser(command_t *command, char *content, vector_t *env);

command_t *piping_command(char *str, vector_t *env, vector_t *pipes);

int launch_commands(command_t *command, vector_t *env, vector_t *pipefd);

#endif /* !COMMAND_H_ */

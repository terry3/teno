#ifndef TENO_CLI_H
#define TENO_CLI_H

#define MAX_CMD_LEN           1024
#define MAX_CMD_ARGS_SIZE     16
#define MAX_CMD_ARGS_LEN      16

#define TENO_CMD_FUNC static

typedef struct _teno_str TENO_STR;

/* teno command struct */
typedef struct _teno_cmd
{
    TENO_STR  s_cmd;                             /* command name */
    TENO_STR  as_args[MAX_CMD_ARGS_SIZE];        /* args, has max value */
    T_UINT32  ul_args_size;                      /* args size */
}TENO_CMD;

typedef F_RET (*TENO_F_CMD_HANDLE)(TENO_CMD *);

/* teno command handler struct */
typedef struct _teno_cmd_handle
{
    T_CHAR            *pc_cmd;  /* command name */
    TENO_F_CMD_HANDLE  f_cmd_handle; /* command handle */
}TENO_CMD_HANDLE;

extern F_RET teno_cli_init();

#endif /* TENO_CLI_H */

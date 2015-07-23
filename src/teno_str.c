#include "teno_pub.h"
#include "teno_cli.h"
#include "teno_str.h"

F_RET teno_str_get_str_between /* avoid memory alloc&free take ps_teno_str to args */
(T_CHAR *pc_str, T_CHAR c_x, TENO_STR *ps_teno_str) {
    T_UINT32 ul_index   = 0;
    T_UINT32 ul_cmd_len = 0;
    T_UINT32 ul_begin   = 0;
    T_UINT32 ul_end     = 0;
    PN_RET(pc_str, T_ERR);
    PN_RET(ps_teno_str, T_ERR);


    ul_cmd_len = strlen(pc_str);

    PN_RET(0 != ul_cmd_len, T_ERR); /* check if out of bound */

    while(pc_str[ul_index] != TENO_STR_TERM
          && ul_cmd_len && pc_str[ul_index] == c_x)
        ul_index++;
    /* if (ul_index <= ul_cmd_len && pc_str[ul_index] == TENO_STR_TERM) { */
    /* } */
    ul_begin = ul_index;

    while(pc_str[ul_index] != TENO_STR_TERM
          && pc_str[ul_index] != c_x)
        ul_index++;
    /* PN_RET(ul_index <= ul_cmd_len, T_ERR); /\* check if out of bound *\/ */

    ul_end = ul_index;
    ps_teno_str->len = ul_end - ul_begin;
    /* if len is 0, set NULL to str. */
    ps_teno_str->str = ps_teno_str->len ? pc_str + ul_begin : T_NULL;

    if (!ps_teno_str->len) {
        /* return error when no valid string find */
        return T_ERR;
    }

    return T_OK;
}

/* create teno_str with string and length */
TENO_STR* teno_str_create_with_len(T_CHAR *pc_str, T_UINT32 ul_len) {
    TENO_STR *ps_str = T_NULL;
    T_CHAR   *pc_cpy_str = T_NULL;

    PN_RET(pc_str, T_NULL);
    ps_str = (TENO_STR*)malloc(sizeof(*ps_str));
    PN_RET(ps_str, T_NULL);

    pc_cpy_str = (T_CHAR*)malloc(ul_len); /* don't check the str len */
    PN_RET(ps_str, T_NULL);

    strcpy(pc_cpy_str, pc_str);

    ps_str->str = pc_cpy_str;
    ps_str->len = ul_len;
    return T_NULL;
}

/* create a teno str */
TENO_STR* teno_str_create(T_CHAR *pc_str) {
    return teno_str_create_with_len(pc_str, strlen(pc_str));
}

/* free teno_str */
T_VOID teno_str_free(TENO_STR *ps_str) {
    PN_RET_N(ps_str);

    /* free inside memory */
    if (ps_str->str) {
        free(ps_str->str);
    }

    free(ps_str);
    return;
}

/* split the command */
F_RET teno_str_split_cmd(T_CHAR *pc_cmd, TENO_CMD *ps_cmd) {
    T_UINT32 ul_index   = 0;
    T_UINT32 ul_str_len = 0;
    F_RET    ul_ret = 0;
    T_CHAR  *pc_cmd_tmp = T_NULL;

    PN_RET(pc_cmd, T_ERR);
    PN_RET(ps_cmd, T_ERR);

    pc_cmd_tmp = pc_cmd;
    ul_str_len = strlen(pc_cmd);

    /* split the pc_cmd according blank' ' */
    /* between first non-blank to first blank is the cmd name */
    /* get the cmd name, first str in th pc_cmd */
    ul_ret = teno_str_get_str_between(pc_cmd_tmp, ' ', &(ps_cmd->s_cmd));
    FR_RET(ul_ret);
    pc_cmd_tmp += ps_cmd->s_cmd.len;

    while(!teno_str_get_str_between(pc_cmd_tmp, ' ', &(ps_cmd->as_args[ul_index]))
          && ul_index < MAX_CMD_ARGS_SIZE) {
        pc_cmd_tmp = ps_cmd->as_args[ul_index].str + ps_cmd->as_args[ul_index].len;
        ul_index++;
        /* increment the args size */
        ps_cmd->ul_args_size++;
    }

    return T_OK;
}

/* alloc memory inside, remember to free */
T_CHAR* teno_str_cpy2(T_CHAR *pc_src) {
    T_CHAR *t_des = T_NULL;
    T_UINT32 ul_len = 0;

    PN_RET(pc_src, T_NULL);

    ul_len = strnlen(pc_src, MAX_CMD_LEN);
    t_des = (T_CHAR*)malloc(ul_len + 1);
    PN_RET(pc_src, T_NULL);

    strncpy(t_des, pc_src, ul_len);
    t_des[ul_len] = '\0';       /* do not forget the terminator */
    return t_des;
}

T_VOID teno_safe_free(T_CHAR *pc_src) {
    if (!pc_src) {
        return;
    }
    free(pc_src);
    return;
}

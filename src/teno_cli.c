#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_str.h"
#include "teno_var.h"

/* command line execute */
/* contain the command string handle */

/* just exit */
TENO_CMD_FUNC
F_RET teno_cli_cmd_exit(TENO_CMD *ps_cmd) {
    F_UNUSED(ps_cmd);
    exit(0);
}

/* print the input command & args */
TENO_CMD_FUNC
T_VOID teno_cli_print_cmd(TENO_CMD *ps_cmd) {
    F_RET    ul_ret   = 0;
    T_UINT32 ul_index = 0;
    T_CHAR ac_tmp[MAX_CMD_LEN];

    PN_RET_N(ps_cmd);
    /* set all 0 */
    F_BZERO(ac_tmp, sizeof(ac_tmp));

    strncpy(ac_tmp, ps_cmd->s_cmd.str, ps_cmd->s_cmd.len);
    printf("command name:[%s], args:[%d]\n", ac_tmp, ps_cmd->ul_args_size);
    for (ul_index = 0; ul_index < ps_cmd->ul_args_size; ul_index++) {
        ul_ret = teno_str_cvt_char(&(ps_cmd->as_args[ul_index]),
                                   ac_tmp,
                                   sizeof(ac_tmp));
        /* unused variable ul_ret */
        F_UNUSED(ul_ret);  // TODO: CHECK THIS!
        printf("args [%d] value:[%s]\n", ul_index, ac_tmp);
    }
    return;
}

/* display service state: msg queue capacity etc.*/
TENO_CMD_FUNC
F_RET teno_cli_cmd_display_service_state(TENO_CMD *ps_cmd) {
    F_RET       ul_ret        = T_OK;
    T_UINT32    ul_servied_id = 0;
    T_CHAR      ac_args[MAX_CMD_ARGS_LEN];

    F_BZERO(ac_args, sizeof(ac_args));

    PN_RET(ps_cmd, T_ERR);

    printf("GLOBAL_MSG_QUEUE_SIZE:[%d]\n", g_s_queue.ul_size);

    if (ps_cmd->ul_args_size == 0) {
        printf("Not assign service id\n");
        return T_OK;
    }
    /* conver TENO_STR to char array */
    memcpy(ac_args,
           ps_cmd->as_args[0].str,
           ps_cmd->as_args[0].len);

    ul_servied_id = atoi(ac_args);
    if (ul_servied_id >= TENO_SERVICE_BUTT) {
        printf("Input service id is error.[%d]\n", ul_servied_id);
        return T_OK;
    }

    if (!g_s_service[ul_servied_id].b_used) {
        printf("Input service id is not used.[%d]\n", ul_servied_id);
        return T_OK;
    }

    /* print service state */
    printf("SERVICE_ID:[%d]\n", ul_servied_id);
    printf("SERVICE_MSG_QUEUE_SIZE:[%d]\n",
           g_s_service[ul_servied_id].s_msg_queue.ul_size);
    printf("SERVICE_MSG_HANDLED:[%d]\n",
           g_s_service[ul_servied_id].ul_msg);

    return ul_ret;
}

/* implements customize command */
TENO_CMD_HANDLE as_cmd_handler[] =
{
 /* name       handler */
    {"exit",   teno_cli_cmd_exit},
    {"state",  teno_cli_cmd_display_service_state},
    {"setvar", teno_var_setvar_handler},
    {"getvar", teno_var_getvar_handler},
    // TODO: Add some new command to set/get variable in teno
};

/* execute command */
F_RET teno_cli_exec_cmd(T_CHAR *pc_cmd) {
    T_CHAR   *pc_cpy   = T_NULL;
    F_RET     ul_ret   = 0;
    T_UINT32  ul_index = 0;
    T_UINT32  ul_cmd_handle_len = 0;
    TENO_CMD  st_cmd;
    PN_RET(pc_cmd, T_ERR);

    /* nothing to execute, no command */
    if (pc_cmd[0] == TENO_STR_TERM) {
        return T_OK;
    }

    /* make a dup of input pc_cmd, do not forget to free. */
    pc_cpy = teno_str_cpy2(pc_cmd);
    PN_RET(pc_cmd, T_ERR);
    F_BZERO(&st_cmd, sizeof(st_cmd));

    /* split the pc_cmd to TENO_CMD according pc_cpy */
    ul_ret = teno_str_split_cmd(pc_cmd, &st_cmd);
    FR_RET(ul_ret);

    teno_cli_print_cmd(&st_cmd);
    ul_cmd_handle_len = sizeof(as_cmd_handler) / sizeof(as_cmd_handler[0]);
    /* match the right command */
    for(ul_index = 0;ul_index < ul_cmd_handle_len;ul_index++) {
        if (!strncmp(as_cmd_handler[ul_index].pc_cmd,
                     st_cmd.s_cmd.str, st_cmd.s_cmd.len)) {
            /* parse the input command */
            (T_VOID)as_cmd_handler[ul_index].f_cmd_handle(&st_cmd);
            /* break when handle done */
            break;
        }
    }
    /* quit teno */
    T_SAFE_FREE(pc_cpy);
    return T_OK;
}

/* filter the message type */
F_RET teno_cli_proc(T_MSG *ps_msg) {
    F_RET ul_ret = T_OK;
    PN_RET(ps_msg, T_ERR);

    switch (ps_msg->ul_type) {
        /* cli message type handle */
    case TENO_MSG_CLI_CMD:
        teno_cli_exec_cmd((T_CHAR*)(ps_msg->data));
        break;
    default:
        break;
    }

    return ul_ret;
}

/* init cli service */
F_RET teno_cli_init() {
    F_RET ul_ret = NULL_UINT32;
    /* service command line interface */
    ul_ret = teno_service_init_service(TENO_SERVICE_CLI,
                                       teno_cli_proc,
                                       T_NULL);
    return ul_ret;
}

#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_var.h"
#include "teno_str.h"

T_UINT32 gul_log_level;         /* log level */
T_TOGGLE gul_trace_t;           /* trace toggle */

TENO_VAR gast_teno_var[] = {
    DEFINE_VAR(var_log_level, 0),
    DEFINE_VAR(var_trace_t, 0),    /* _t means toggle, trace msg toggle */
    DEFINE_VAR(var_msg_chk_t, 0),  /* msg check valid toggle */
};

/* set var value */
F_RET teno_set_var(T_CHAR *pc_var_name, T_UINT32 ul_var_value) {
    F_RET    ul_ret = T_ERR;
    T_UINT32 ul_var_array_len = sizeof(gast_teno_var) / sizeof(gast_teno_var[0]);
    T_UINT32 ul_index = 0;
    PN_RET(pc_var_name, T_ERR);
    for (ul_index = 0; ul_index < ul_var_array_len; ul_index++) {
        if (0 == strcmp(gast_teno_var[ul_index].pc_var_name, pc_var_name)) {
            /* set the var value */
            gast_teno_var[ul_index].ul_var_value = ul_var_value;
            return T_OK;
        }
    }
    /* can not find the right var according 'pc_var_name' */
    return ul_ret;
}

/* get var value */
T_UINT32 teno_get_var(T_CHAR *pc_var_name) {
    T_UINT32 ul_var_array_len = sizeof(gast_teno_var) / sizeof(gast_teno_var[0]);
    T_UINT32 ul_index = 0;
    PN_RET(pc_var_name, T_ERR);
    for (ul_index = 0; ul_index < ul_var_array_len; ul_index++) {
        if (0 == strcmp(gast_teno_var[ul_index].pc_var_name, pc_var_name)) {
            /* return the var value */
            return gast_teno_var[ul_index].ul_var_value;
        }
    }
    /* can not find the right var according 'pc_var_name' */
    return NULL_UINT32;
}

/* setvar teno command handler */
F_RET teno_var_setvar_handler(TENO_CMD *ps_cmd)
{
    F_RET  ul_ret = 0;
    T_CHAR ac_tmp_var_name[MAX_CMD_LEN];
    T_CHAR ac_tmp_var_value[MAX_CMD_LEN];

    /* args most more than 2 */
    PN_RET(ps_cmd->ul_args_size > 1, T_ERR);
    ul_ret = teno_str_cvt_char
        (&(ps_cmd->as_args[0]), ac_tmp_var_name, sizeof(ac_tmp_var_name));
    F_UNUSED(ul_ret);
    ul_ret = teno_str_cvt_char
        (&(ps_cmd->as_args[1]), ac_tmp_var_value, sizeof(ac_tmp_var_value));
    F_UNUSED(ul_ret);
    ul_ret = teno_set_var(ac_tmp_var_name, atoi(ac_tmp_var_value));
    FR_RET(ul_ret);
    return T_OK;
}

/* getvar teno command handler */
T_UINT32 teno_var_getvar_handler(TENO_CMD *ps_cmd)
{
    F_RET  ul_ret = 0;
    T_CHAR ac_tmp_var_name[MAX_CMD_LEN];

    /* args most more than 2 */
    PN_RET(ps_cmd->ul_args_size > 0, T_ERR);
    ul_ret = teno_str_cvt_char
        (&(ps_cmd->as_args[0]), ac_tmp_var_name, sizeof(ac_tmp_var_name));
    F_UNUSED(ul_ret);

    ul_ret = teno_get_var(ac_tmp_var_name);
    return ul_ret;
}

/* variables set/get service proc */
F_RET teno_var_proc(T_MSG *ps_msg)
{
    F_RET ul_ret = T_OK;
    PN_RET(ps_msg, T_ERR);

    return ul_ret;
}

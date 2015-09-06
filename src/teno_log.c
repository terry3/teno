#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_str.h"
#include "teno_var.h"
#include "teno_log.h"

/* main log function */
T_VOID teno_log(T_CHAR *pc_fmt, char *fmt, ...) {
    /* print log */
    return;
}

/* log service initial */
F_RET teno_log_init() {
    return T_OK;
}

/* write log */
F_RET teno_log_proc(T_MSG *ps_msg) {
    F_RET ul_ret = T_OK;
    PN_RET(ps_msg, T_ERR);

    F_UNUSED(ul_ret);
    return ul_ret;
}

/* init logging service */
F_RET teno_log_init() {
    F_RET ul_ret = NULL_UINT32;
    /* service command line interface */
    ul_ret = teno_service_init_service(TENO_SERVICE_LOG,
                                       teno_log_proc,
                                       teno_log_init);
    return ul_ret;
}


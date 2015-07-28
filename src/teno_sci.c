#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_str.h"
#include "teno_sci.h"

F_RET teno_sci_service_init() {
    F_RET  ul_ret = NULL_UINT32;
    // TODO: waiting for virtualbox xubuntu
    return ul_ret;
}

F_RET teno_sci_init() {
    F_RET ul_ret = NULL_UINT32;
    /* service command line interface */
    ul_ret = teno_service_init_service(TENO_SERVICE_SCI,
                                       teno_sci_proc,
                                       T_NULL);
    return ul_ret;
}

/* sci service process handle */
F_RET teno_sci_proc(T_MSG *ps_msg) {
    F_RET ul_ret = T_OK;
    F_UNUSED(ps_msg);
    return ul_ret;
}

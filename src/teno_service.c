#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_trace.h"

TENO_SERVICE g_s_service[TENO_SERVICE_BUTT];

F_RET teno_service_init_service
(
    T_UINT32      ul_sid,
    SERVICE_PROC  f_proc,
    SERVICE_INIT  f_init       /* service init func */
)
{
    F_RET  ul_ret = 0;
    F_UNUSED(ul_ret);
    CHK_RET(ul_sid < TENO_SERVICE_BUTT, T_ERR);
    CHK_RET(T_TRUE != g_s_service[ul_sid].b_used, T_ERR);

    g_s_service[ul_sid].ul_sid = ul_sid;
    /* create service thread */
    (T_VOID)T_THREAD_CREATE(g_s_service[ul_sid].s_tid,
                            teno_service_proc,
                            g_s_service[ul_sid].ul_sid);
    ul_ret = teno_mq_init_queue(&(g_s_service[ul_sid].s_msg_queue));
    g_s_service[ul_sid].f_proc = f_proc;
    g_s_service[ul_sid].b_used = T_TRUE;
    g_s_service[ul_sid].f_init = f_init;
    return T_OK;
}

/* service process framwork, invoke f_init() and f_proc() */
T_VOID* teno_service_proc(T_VOID *p_param)
{
    T_UINT32      ul_sid        = 0;
    TENO_SERVICE *ps_service    = T_NULL;
    T_MSG        *ps_msg        = T_NULL;
    T_MSG_QUEUE  *ps_msg_queue  = T_NULL; /* msg queue */
    PN_RET(p_param, T_NULL);
    ul_sid = *(T_UINT32*)p_param;
    CHK_RET(ul_sid < TENO_SERVICE_BUTT, T_NULL);
    ps_service = &(g_s_service[ul_sid]);
    ps_msg_queue = &(ps_service->s_msg_queue);
    /* init service */
    if (ps_service->f_init) {
        ps_service->f_init();
    }
    for (;;) {
        /* pop bolcked */
        ps_msg = (T_MSG*)teno_mq_pop_queue(ps_msg_queue);

        if (ps_service->f_proc) {
            /* the hook do not care ps_msg memory */
            ps_service->f_proc(ps_msg);
        }
        /* free ps_msg */
        teno_msg_free_msg(ps_msg);
    }
}

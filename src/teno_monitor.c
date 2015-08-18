#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_msg.h"
#include "teno_monitor.h"


T_VOID* teno_monitor_proc
(
    T_VOID *p_param
)
{
    T_MSG       *ps_msg   = T_NULL;
    F_RET        ul_ret   = NULL_UINT32;
    T_MSG_QUEUE *ps_queue = T_NULL;

    F_UNUSED(p_param);
    for (;;) {
        ps_msg = (T_MSG*)teno_mq_pop_queue(&g_s_queue);
        if (!ps_msg) {
            continue;
        }
        //ps_msg = (T_MSG*)(ps_node->p_data);
        ps_queue = &(g_s_service[ps_msg->ul_to_sid].s_msg_queue);
        ul_ret = teno_mq_push_queue(ps_queue, ps_msg);
        if (ul_ret) {
            printf("push queue failure. sid[%d]", ps_msg->ul_to_sid);
        }
    }
}

F_RET teno_monitor_init()
{
    F_RET ul_ret = NULL_UINT32;

    g_s_service[TENO_SERVICE_MONITOR].ul_sid = TENO_SERVICE_MONITOR;
    g_s_service[TENO_SERVICE_MONITOR].f_proc = T_NULL;
    g_s_service[TENO_SERVICE_MONITOR].b_used = T_TRUE;

    memset(&(g_s_service[TENO_SERVICE_MONITOR].s_msg_queue),
           0,
           sizeof(g_s_service[TENO_SERVICE_MONITOR].s_msg_queue));
    ul_ret = teno_mq_init_queue(
             &(g_s_service[TENO_SERVICE_MONITOR].s_msg_queue));
    FR_RET(ul_ret);
    /* create service thread */
    (T_VOID)T_THREAD_CREATE(g_s_service[TENO_SERVICE_MONITOR].s_tid,
                            teno_monitor_proc,
                            g_s_service[TENO_SERVICE_MONITOR].s_tid);

    return T_OK;
}

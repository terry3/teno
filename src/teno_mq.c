/* teno_mq.c  */
#include <apr_queue.h>
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"

T_MSG_QUEUE g_s_queue;           /* global queue */

F_RET teno_mq_init_global_queue()
{
    return teno_mq_init_queue(&g_s_queue);
}

/* create apr queue */
F_RET teno_mq_init_queue
(
    T_MSG_QUEUE *ps_queue
)
{
    T_APR_RET   ret    = 0;
	PN_RET(ps_queue, T_ERR);
    /* create apr memory pool */
    ret = apr_pool_create(&(ps_queue->ps_pool), NULL);
	FR_RET(ret);
    /* create apr queue */
    ret = apr_queue_create(&(ps_queue->ps_queue), 
                           TENO_MQ_DEFAULT_SIZE,
                           ps_queue->ps_pool);
    FR_RET(ret);

	return T_OK;
}

/* destroy apr queue */
T_VOID teno_mq_destroy_queue
(
    T_MSG_QUEUE *ps_queue
)
{
    (T_VOID)apr_queue_term(ps_queue->ps_queue);
    (T_VOID)apr_pool_destroy(ps_queue->ps_pool);
}

/* push teno message to the queue. */
F_RET teno_mq_push_queue
(
    T_MSG_QUEUE *ps_queue,
    T_VOID      *p_data
)
{
    return apr_queue_push(ps_queue->ps_queue, p_data);
}

/* pop teno message from the queue. */
T_VOID* teno_mq_pop_queue
(
    T_MSG_QUEUE *ps_queue
)
{
    T_VOID     *p_data = T_NULL;
    T_APR_RET   ret    = 0;
    ret = apr_queue_pop(ps_queue->ps_queue, &p_data);
    if (!ret) {
        return p_data;
    }

    return T_NULL;    /* service_proc() free p_data */
}

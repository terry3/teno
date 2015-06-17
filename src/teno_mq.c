/* teno_mq.c teno的消息队列处理文件 */
#include "teno.h"
#include "teno_mq.h"

T_MSG_LIST g_s_queue;           /* 全局消息队列 */

F_RET teno_mq_init_queue(T_MSG_LIST *ps_queue)
{
    F_RET ul_ret = 0;
    PN_RET(ps_queue);

    ps_queue->ps_head = T_NULL;
    ps_queue->ps_tail = T_NULL;
    ps_queue->ul_size = 0;
    ul_ret = T_MUTEX_INIT(ps_queue->s_mutex, T_NULL); /* use default config */
    FR_RET(ul_ret);
    return T_OK;
}

T_VOID teno_mq_destroy_queue(T_MSG_LIST *ps_queue)
{
    PN_RET(ps_queue);
    /* 清除queue中的每个节点 */
    
    return;
}

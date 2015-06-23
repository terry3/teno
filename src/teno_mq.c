/* teno_mq.c teno的消息队列处理文件 */
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"

T_MSG_QUEUE g_s_queue;           /* 全局消息队列 */

F_RET teno_mq_init_global_queue()
{
    return teno_mq_init_queue(&g_s_queue);
}

F_RET teno_mq_init_queue
(
    T_MSG_QUEUE *ps_queue
)
{
	F_RET ul_ret = 0;
	PN_RET(ps_queue, T_ERR);

	ps_queue->ps_head = T_NULL;
	ps_queue->ps_tail = T_NULL;
	ps_queue->ul_size = 0;
	ul_ret = T_F_MUTEX_INIT(&(ps_queue->s_mutex),
                            T_NULL); /* use default config */
	FR_RET(ul_ret);
    ul_ret = T_F_COND_INIT(&(ps_queue->s_cond),
                           T_NULL); /* use default config */
	FR_RET(ul_ret);
    ul_ret = apr_pool_create(&(ps_queue->ps_memp), T_NULL);
	FR_RET(ul_ret);
    ul_ret = apr_queue_create(&(ps_queue->ps_queue), 500000, ps_queue->ps_memp);
	FR_RET(ul_ret);
	return T_OK;
}

T_VOID teno_mq_destroy_queue
(
    T_MSG_QUEUE *ps_queue
)
{
	T_MSG_NODE *ps_node = T_NULL;
	T_MSG_NODE *ps_next = T_NULL;
	PN_RET_N(ps_queue);

	T_LOCK(ps_queue->s_mutex);

	ps_node = ps_queue->ps_head;
	ps_next = ps_node;
	while(ps_node)              /* 循环整个链表，逐个释放内存 */
	{
		ps_next = ps_node->ps_next;
		/* 释放的时候需要先释放内部的message */
		T_SAFE_FREE(ps_node->p_data);
		T_SAFE_FREE(ps_node);
		ps_node = ps_next;
	}

	T_UNLOCK(ps_queue->s_mutex);
	T_DESTORY_MUTEX(&(ps_queue->s_mutex));

	return;
}

F_RET teno_mq_push_queue
(
    T_MSG_QUEUE *ps_queue,
    T_VOID      *p_data
)
{
    T_UINT32 ul_ret = 0;
	PN_RET(ps_queue, T_ERR);
    ul_ret = apr_queue_push(ps_queue->ps_queue, p_data);
    ps_queue->ul_size = apr_queue_size(ps_queue->ps_queue);
    /* ul_ret = apr_queue_size(ps_queue->ps_queue); */
    return T_OK;
}

T_VOID* teno_mq_pop_queue
(
    T_MSG_QUEUE *ps_queue
)
{
    T_UINT32 ul_ret = 0;
    T_VOID  *p_data = T_NULL;
	PN_RET(ps_queue, T_NULL);
    ul_ret = apr_queue_pop(ps_queue->ps_queue, &p_data);
    ps_queue->ul_size = apr_queue_size(ps_queue->ps_queue);
    return p_data;    /* 由service_proc释放 */
}

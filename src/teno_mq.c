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
	while(ps_node) {      /* 循环整个链表，逐个释放内存 */
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
	T_MSG_NODE *ps_node = T_NULL;
    T_MSG_NODE *ps_tail = T_NULL;
	PN_RET(ps_queue, T_ERR);
	PN_RET(p_data, T_ERR);

	ps_node = (T_MSG_NODE*)malloc(sizeof(*ps_node));
	PN_RET(ps_node, T_ERR);
    ps_node->ps_next   = T_NULL;
    ps_node->p_data    = p_data; /* 初始化node，赋值data */
    ps_node->ul_length = 0;      /* 暂时初始化为0 */
    T_LOCK(ps_queue->s_mutex);
    ps_tail = ps_queue->ps_tail;
    if (T_NULL == ps_tail) {
        ps_queue->ps_tail = ps_node;
        ps_queue->ps_head = ps_node;
        ps_queue->ul_size++;
    } else {
        ps_tail->ps_next = ps_node;
        ps_queue->ps_tail = ps_node;
        ps_queue->ul_size++;
    }
    T_F_SINGAL(&(ps_queue->s_cond));    /* 解除等待线程的阻塞 */
    T_UNLOCK(ps_queue->s_mutex);
    return T_OK;
}

T_VOID* teno_mq_pop_queue
(
    T_MSG_QUEUE *ps_queue
)
{
    T_MSG_NODE *ps_node = T_NULL;
    T_MSG_NODE *ps_head = T_NULL;
    T_VOID     *p_data  = T_NULL;

	PN_RET(ps_queue, T_NULL);
    T_LOCK(ps_queue->s_mutex);
    while (!(ps_queue->ps_head)) {
        /* 队列为空时阻塞在这里 */
        pthread_cond_wait(&(ps_queue->s_cond),
                          &(ps_queue->s_mutex));
    }

    ps_head           = ps_queue->ps_head;
    ps_node           = ps_head->ps_next;
    p_data            = ps_head->p_data;
    ps_queue->ps_head = ps_node;
    ps_queue->ul_size--;
    if (0 == ps_queue->ul_size) {
        ps_queue->ps_tail = T_NULL;
    }
    T_UNLOCK(ps_queue->s_mutex);
    T_SAFE_FREE(ps_head);
    return p_data;    /* 由service_proc释放 */
}

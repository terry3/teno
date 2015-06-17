#ifndef TENO_MQ_H
#define TENO_MQ_H


typedef struct _t_msg_node T_MSG_NODE;
#define T_MUTEX       pthread_mutex_t
#define T_NUTEX_INIT  pthread_mutex_init



struct _t_msg_node
{
    T_MSG_NODE *ps_next;
    T_VOID     *p_data;
};

typedef struct
{
    T_MSG_NODE *ps_head;
    T_MSG_NODE *ps_tail;
    T_UINT32    ul_size;
    T_MUTEX     s_mutex;
}T_MSG_LIST;

#endif /* TENO_MQ_H */

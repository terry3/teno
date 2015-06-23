#ifndef TENO_MQ_H
#define TENO_MQ_H


typedef struct _t_msg_node T_MSG_NODE;
#define T_THREAD_T        pthread_t
#define T_MUTEX           pthread_mutex_t
#define T_COND            pthread_cond_t
#define T_F_MUTEX_INIT    pthread_mutex_init
#define T_F_COND_INIT     pthread_cond_init
#define T_F_LOCK          pthread_mutex_lock
#define T_F_UNLOCK        pthread_mutex_unlock
#define T_F_DESTROY_MUTEX pthread_mutex_destroy
#define T_F_THREAD_CREATE pthread_create
#define T_F_SINGAL        pthread_cond_signal
#define T_MEMP            

#define T_LOCK(_mutex) \
    T_F_LOCK(&(_mutex))
#define T_UNLOCK(_mutex) \
    T_F_UNLOCK(&(_mutex))
#define T_THREAD_CREATE(_id, f_proc, _param)     \
    T_F_THREAD_CREATE(&(_id), T_NULL, f_proc, &(_param))

#define T_DESTORY_MUTEX(_mutex) \
    T_F_DESTROY_MUTEX((_mutex))


struct _t_msg_node
{
    T_MSG_NODE *ps_next;
    T_VOID     *p_data;
    T_UINT32    ul_length;
};

typedef struct
{
    T_MSG_NODE      *ps_head;
    T_MSG_NODE      *ps_tail;
    T_UINT32         ul_size;
    apr_pool_t      *ps_memp;
    T_MUTEX          s_mutex;
    T_COND           s_cond;
    apr_queue_t     *ps_queue;
}T_MSG_QUEUE;


/* variable declare */
extern T_MSG_QUEUE g_s_queue;

/* function declare */
extern F_RET teno_mq_init_queue
(
    T_MSG_QUEUE *ps_queue
);

extern T_VOID teno_mq_destroy_queue
(
    T_MSG_QUEUE *ps_queue
);

extern F_RET teno_mq_push_queue
(
    T_MSG_QUEUE *ps_queue,
    T_VOID      *p_data
);

extern T_VOID* teno_mq_pop_queue
(
    T_MSG_QUEUE *ps_queue
);

extern F_RET teno_mq_init_global_queue();

#endif /* TENO_MQ_H */

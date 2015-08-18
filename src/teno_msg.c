/* teno_msg.c */
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_msg.h"

/* alloc teno message, failure return NULL */
T_MSG* teno_msg_alloc_msg(T_UINT32 ul_length)
{
    T_MSG *ps_msg = T_NULL;

    ps_msg = (T_MSG*)malloc(sizeof(*ps_msg) + ul_length);
    PN_RET(ps_msg, T_NULL);
    memset(ps_msg, 0, sizeof(*ps_msg) + ul_length);

    return ps_msg;
}

/* free teno message */
T_VOID teno_msg_free_msg(T_MSG *ps_msg)
{
    PN_RET_N(ps_msg);
    free(ps_msg);
    return;
}

/* send teno message, just push the message to que global queue */
F_RET teno_msg_send(T_MSG *ps_msg)
{
    /* printf("send msg\n"); */
    teno_mq_push_queue(&g_s_queue, ps_msg);
    return T_OK;
}

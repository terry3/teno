/* teno_msg.c */
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_msg.h"

/* check teno message valid */
F_RET teno_msg_check(T_MSG *ps_msg)
{
    /* pointer */
    PN_RET(ps_msg, T_ERR);
    /* length */
    PN_RET(ps_msg->ul_length != 0, T_ERR);
    return T_OK;
}

/* print teno message */
T_VOID teno_msg_print(T_MSG *ps_msg)
{
    T_UINT32 ul_index = 0;
    PN_RET_N(ps_msg);
    printf("from_sid[%d], to_sid[%d], length[%d], type[%d]\n",
           ps_msg->ul_from_sid,
           ps_msg->ul_to_sid,
           ps_msg->ul_length,
           ps_msg->ul_type);
    printf("body[");
    /* print message body in memory */
    for (ul_index = 0;ul_index < ps_msg->ul_length;ul_index++) {
        printf("%x ", ps_msg->data[ul_index]);
    }
    printf("]\n");
}

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
    F_RET ul_ret = 0;
    PN_RET(ps_msg, T_ERR);
    ul_ret = teno_msg_check(ps_msg);
    FR_RET(ul_ret);
    /* printf("send msg\n"); */
    teno_msg_print(ps_msg);
    /* if teno message length is 0, return error */
    teno_mq_push_queue(&g_s_queue, ps_msg);
    return T_OK;
}

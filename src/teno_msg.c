/* teno_msg.c teno中消息的处理函数 */
#include "teno.h"
#include "teno_msg.h"

T_MSG* teno_msg_alloc_msg(T_UINT32 ul_length)
{
    T_MSG *ps_msg = T_NULL;

    ps_msg = (T_MSG*)malloc(T_MSG_HEAD_LEN + ul_length);

    return ps_msg;
}

T_VOID teno_msg_free_msg(T_MSG *ps_msg)
{
    PN_RET_N(ps_msg);
    free(ps_msg);
    return;
}

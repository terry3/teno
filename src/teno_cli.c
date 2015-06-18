#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"

F_RET teno_cli_query_service_state()
{
    F_RET       ul_ret    = T_OK;
    T_UINT32    ul_index  = 0;

    printf("GLOBAL_MSG_QUEUE_SIZE:[%d]\n", g_s_queue.ul_size);


    for (ul_index = 0;
         ul_index < TENO_SERVICE_BUTT;
         ul_index++)
    {
        if (!g_s_service[ul_index].b_used)
        {
            continue;
        }

        printf("SERVICE_ID:[%d]\n", ul_index);
        printf("SERVICE_MSG_QUEUE_SIZE:[%d]\n",
               g_s_service[ul_index].s_msg_queue.ul_size);
    }

    return ul_ret;
}

F_RET teno_cli_proc(T_MSG *ps_msg)
{
    F_RET ul_ret = T_OK;
    PN_RET(ps_msg, T_ERR);

    switch (ps_msg->ul_type)
    {
    case TENO_MSG_QUERY_SERVICE_STATE:
        teno_cli_query_service_state();
        break;
    default:
        break;
    }

    return ul_ret;
}

F_RET teno_cli_init()
{
    F_RET ul_ret = NULL_UINT32;
    /* service command line interface */
    ul_ret = teno_service_init_service(TENO_SERVICE_CLI,
                                       teno_cli_proc);
    return T_OK;
}

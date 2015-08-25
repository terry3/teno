/* teno.c */
#include <apr_pools.h>
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"
#include "teno_cli.h"

F_RET teno_init() 
{
    F_RET       ret_fr = 0;
    T_APR_RET   ret    = 0;

    /* initialize apr */
    ret = apr_initialize();
	FR_RET(ret);
    /* initialize apr pool */
    ret = apr_pool_initialize();
	FR_RET(ret);
    /* Clear variable to 0 */
    F_BZERO(g_s_service, sizeof(g_s_service));
    F_BZERO(&g_s_queue, sizeof(g_s_queue));
    /* Init global message queue */
    ret_fr = teno_mq_init_global_queue();
	FR_RET(ret);
    /* Create monitor thread */
    ret_fr = teno_monitor_init();
	FR_RET(ret);
    /* The built-in service in teno */
    ret_fr = teno_cli_init();
	FR_RET(ret);

    return T_OK;
}

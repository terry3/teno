/* teno.c */
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"
#include "teno_cli.h"

F_RET teno_init() {
    /* Clear variable to 0 */
    F_BZERO(g_s_service, sizeof(g_s_service));
    F_BZERO(&g_s_queue, sizeof(g_s_queue));
    /* Init global message queue */
    teno_mq_init_global_queue();
    /* Create monitor thread */
    teno_monitor_init();
    /* The built-in service in teno */
    teno_cli_init();
    return T_OK;
}

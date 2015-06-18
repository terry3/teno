/* teno.c 包含teno主要实现及对外接口函数 */
#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"



F_RET teno_init()
{
    /* 全局变量清0 */
    memset(g_s_service, 0, sizeof(g_s_service));
    memset(&g_s_queue, 0, sizeof(g_s_queue));
    /* 初始化全局队列 */
    teno_mq_init_global_queue();
    /* 初始化monitor线程 */
    teno_monitor_init();
    return T_OK;
}

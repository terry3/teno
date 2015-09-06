#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"

#define MAX_CNT (10000 * 100)
static T_UINT32 stat = 0;


#ifdef T_ENABLE_CLI
#define CLI_TOGGLE 1
#else
#define CLI_TOGGLE 0
#endif

F_RET test_proc(T_MSG *ps_msg)
{
    stat++;
    /* printf("recv msg is [%s], stat[%d]\n", ps_msg->data, stat); */


    if (stat == MAX_CNT)
    {
        /* printf("run time [%d]\n", dwEnd - dwStart); */
    }
    return T_OK;
}

T_VOID* test_cli(T_VOID *p_param)
{
    T_MSG *ps_msg = T_NULL;
    T_CHAR buffer[1024] = "";

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 1023, stdin);
        ps_msg = teno_msg_alloc_msg(100 + 1);
        PN_RET(ps_msg, 0);
        ps_msg->ul_to_sid = TENO_SERVICE_CLI;
        ps_msg->ul_type = TENO_MSG_CLI_CMD;
        strcpy(ps_msg->data, buffer);
        ps_msg->data[strlen(ps_msg->data) - 1] = '\0';
        ps_msg->ul_length = 100 + 1;
        /* dwStart = GetTickCount(); */
        teno_msg_send(ps_msg);
    }

    return T_OK;
}

int main(int argc, char *argv[])
{
    T_MSG *ps_msg = T_NULL;
    T_UINT32 index = 0;
    T_THREAD_T      s_tid;      /* service thread id */

    teno_init();
    teno_service_init_service(TENO_SERVICE_TEST,
                              test_proc,
                              T_NULL);

    stat = 0;
    ps_msg = teno_msg_alloc_msg(100 + 1);

    for (index =0 ; index < MAX_CNT; index++)
    {
        ps_msg->ul_to_sid = 1;
        sprintf(ps_msg->data, "%d", index);
        test_proc(ps_msg);
    }

    stat = 0;

    /* create service thread */
    (T_VOID)T_THREAD_CREATE(s_tid,
                            test_cli,
                            index);


    for (index =0 ; index < MAX_CNT; index++)
    {
        ps_msg = teno_msg_alloc_msg(100 + 1);
        F_BZERO(ps_msg, 100 + 1);
        PN_RET(ps_msg, 0);
        ps_msg->ul_to_sid = TENO_SERVICE_TEST;
        sprintf(ps_msg->data, "123123 123 123 %d", index);
        ps_msg->ul_length = strlen(ps_msg->data) + 1;
        teno_msg_send(ps_msg);
    }


    pthread_join(g_s_service[TENO_SERVICE_CLI].s_tid, T_NULL);

    return 0;
}

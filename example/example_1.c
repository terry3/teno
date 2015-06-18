#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"
#include <windows.h>
#include <time.h>

#define MAX_CNT (10000 * 100)
DWORD dwStart;
DWORD dwEnd;
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
        dwEnd = GetTickCount();
        printf("run time [%d]\n", dwEnd - dwStart);
    }
    return T_OK;
}

int main(int argc, char *argv[])
{
    T_MSG *ps_msg = T_NULL;
    T_CHAR a[10] = "1234";
    T_CHAR buffer[1024] = "";
    T_UINT32 index = 0;
    teno_init();
    teno_service_init_service(1, test_proc);
    teno_service_init_service(TENO_SERVICE_JUST_PRINT, test_proc);
    teno_service_init_service(TENO_SERVICE_CLI, T_NULL);

    dwStart = GetTickCount();
    stat = 0;
    ps_msg = teno_msg_alloc_msg(100 + 1);

    for (index =0 ; index < MAX_CNT; index++)
    {
        ps_msg->ul_to_sid = 1;
        sprintf(ps_msg->data, "%d\0", index);
        test_proc(ps_msg);
    }

    dwStart = GetTickCount();
    stat = 0;

    for (index =0 ; index < MAX_CNT; index++)
    {
        ps_msg = teno_msg_alloc_msg(100 + 1);
        PN_RET(ps_msg, 0);
        ps_msg->ul_to_sid = 1;
        sprintf(ps_msg->data, "%d\0", index);
        teno_msg_send(ps_msg);
    }

    while (CLI_TOGGLE)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, 1023, stdin);
        ps_msg = teno_msg_alloc_msg(100 + 1);
        PN_RET(ps_msg, 0);
        ps_msg->ul_to_sid = 1;
        strcpy(ps_msg->data, buffer);
        ps_msg->data[strlen(ps_msg->data) - 1] = '\0';
        dwStart = GetTickCount();
        teno_msg_send(ps_msg);
    }

    pthread_join(g_s_service[1].s_tid, T_NULL);

    return 0;
}

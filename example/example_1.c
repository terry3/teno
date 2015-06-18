#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"
#include <windows.h>
#include <time.h>

#define MAX_CNT (10000 * 1000)
DWORD dwStart;
DWORD dwEnd;


F_RET test_proc(T_MSG *ps_msg)
{
    static T_UINT32 stat = 0;
    stat++;
    /* printf("recv msg is [%s], stat[%d]\n", ps_msg->data, stat); */

    if (stat == MAX_CNT - 1)
    {
        dwEnd = GetTickCount();
        printf("run time [%d]", dwEnd - dwStart);
    }
    return T_OK;
}

int main(int argc, char *argv[])
{
    T_MSG *ps_msg = T_NULL;
    T_CHAR a[10] = "1234";
    T_UINT32 index = 0;
    teno_init();
    teno_service_init_service(1, test_proc);

    dwStart = GetTickCount();

    for (index =0 ; index < MAX_CNT; index++)
    {
        ps_msg = teno_msg_alloc_msg(100 + 1);
        ps_msg->ul_to_sid = 1;
        sprintf(ps_msg->data, "%d\0", index);
        PN_RET(ps_msg, 0);
        teno_msg_send(ps_msg);
    }


    pthread_join(g_s_service[1].s_tid, T_NULL);

    return 0;
}

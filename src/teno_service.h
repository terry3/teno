#include "teno_msg.h"

#ifndef TENO_SERVICE_H
#define TENO_SERVICE_H

typedef F_RET (*SERVICE_PROC)(T_MSG* ); /* Service回调函数原型 */

typedef enum _teno_service_type
{
    TENO_SERVICE_MONITOR = 0,
    TENO_SERVICE_TIMER,

    TENO_DO_NOT_MODIFY_UP,
    TENO_SERVICE_BUTT,
}TENO_SERVICE_TYPE;


typedef struct _teno_service
{
    T_UINT32        ul_sid;     /* service id */
    T_THREAD_T      s_tid;      /* service thread id */
    T_MSG_QUEUE     s_msg_queue; /* msg queue */
    SERVICE_PROC    f_proc;      /* service callback */
    T_TOGGLE        b_used;      /* is used */
}TENO_SERVICE;


/* varialbe declare */
extern TENO_SERVICE g_s_service[TENO_SERVICE_BUTT];



/* function declare */
extern T_VOID* teno_service_proc(T_VOID *p_param);
extern F_RET teno_service_init_service
(
    T_UINT32      ul_sid,
    SERVICE_PROC  f_proc
);

#endif /* TENO_SERVICE_H */

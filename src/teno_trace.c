#include "teno.h"
#include "teno_msg.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_cli.h"
#include "teno_trace.h"

<<<<<<< HEAD
/* Trace the message */
/* Just print now, will modified to enhanced. */
=======
/* trace the message */
/* just print now, will modified to enhanced. */
>>>>>>> f7e919cd6cd80271e7cba7cddcf079203eb032b1
T_VOID teno_msg_trace(T_MSG *ps_msg) {
    PN_RET_N(ps_msg);
    printf("fs=[%d], ts=[%d], fp=[%d], tp=[%d], T=[%d], L=[%d]\n",
           ps_msg->ul_from_sid,
           ps_msg->ul_to_sid,
           ps_msg->ul_from_pid,
           ps_msg->ul_to_pid,
           ps_msg->ul_type,
           ps_msg->ul_length);
    return;
}


#include "teno.h"
#include "teno_pub.h"
#include "teno_mq.h"
#include "teno_service.h"
#include "teno_monitor.h"
#include "teno_msg.h"

extern F_RET teno_server();

int main() {
    teno_server();
    return 0;
}



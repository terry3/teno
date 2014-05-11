#include "log_def.h"
#include "log_api.h"
#include "log_var.h"

F_RET log_set_level(T_UINT32 level)
{

    if (level >= LOG_LEVEL_BUTT)
    {
        level = DEBUG;
    }
    gulLogLevel = level;
    printf("set log level to [%u]\n", gulLogLevel);
    return T_OK;
}

F_RET log_get_level(T_UINT32 *level)
{
    P_NULL_RET(level, T_ERR);
    printf("log level is [%u]\n", gulLogLevel);
    return T_OK;
}



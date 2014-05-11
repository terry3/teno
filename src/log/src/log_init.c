/* log story init */
#include "log_def.h"
#include "log_init.h"
#include "log_var.h"
#include "log_api.h"

/*
 * set log story init var
 * maybe config in a ini file
 */

/*
 * log story init
 */
F_RET log_init()
{
    T_UINT32 log_level = LOG_LEVEL_BUTT;
    printf ("log_init success.\n");
    printf ("log_init gulLogFileSize=[%d].\n", gulLogFileSize);
    log_set_level(DEBUG);
    log_get_level(&log_level);
    return F_SUCCESS;
}

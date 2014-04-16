/* log api declare. */

#include "pub_inc.h"
#ifndef _LOG_API_H_
#define _LOG_API_H_


#define T_LOG(LEVEL, CONTENT, ...) 1

/* set log level */
extern F_RET log_set_level() ;

#endif /* _LOG_API_H_ */

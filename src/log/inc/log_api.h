/* log api declare. */

#include "pub_inc.h"
#ifndef _LOG_API_H_
#define _LOG_API_H_


#ifdef __cplusplus
extern "C"{
#endif
#define T_LOG(LEVEL, CONTENT, ...) 1

/* set log level */
extern F_RET log_set_level() ;

/* get log level */
extern F_RET log_get_level(T_UINT32 *level);

#ifdef __cplusplus
}
#endif


#endif /* _LOG_API_H_ */

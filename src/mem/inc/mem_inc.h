#include "pub_def.h"

#ifndef _MEM_INC_H_
#define _MEM_INC_H_


#ifdef __cplusplus
extern "C"{
#endif
#define MODE_NAME_LEN 16

/* memory control poiot struct */
typedef struct
{
    T_UINT32 t_mode_mem_id;
    T_UINT32 t_mode_mem_size;
    T_CHAR   t_mode_name[MODE_NAME_LEN];
}T_MEM_P;

#ifdef __cplusplus
}
#endif

#endif /* _MEM_INC_H_ */

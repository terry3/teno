#include "pub_def.h"

#ifndef _MEM_INC_H_
#define _MEM_INC_H_


#define MODE_NAME_LEN 16
/* memory control poiot struct */
typedef struct
{
    U_UINT32 t_mode_mem_id;
    U_UINT32 t_mode_mem_size;
    T_CHAR   t_mode_name[MODE_NAME_LEN];
}T_MEM_P;

#endif /* _MEM_INC_H_ */

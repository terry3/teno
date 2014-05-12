#include "base_init.h"
#include "mem_inc.h"

F_RET b_init()
{
    T_UINT32 ret = T_OK;
    ret = stl_list_create(&g_teno_list);
    T_CHECK_RET(ret, T_OK, T_ERR);
    P_NULL_RET(g_teno_list, T_ERR);
    return T_OK;
}

F_RET b_add_mode(T_UINT32 mode_id, T_CHAR *mode_name)
{
    T_MEM_P t_mem_p = {0};
    T_UINT32 ret = T_OK;
    P_NULL_RET(mode_name, T_ERR);

    t_mem_p.t_mode_mem_id = mode_id;
    t_mem_p.t_mode_mem_size = 0;
    strncpy(&t_mem_p.t_mode_mem_size, mode_name, MODE_NAME_LEN);

    ret = stl_list_insert(g_teno_list, (void*)&t_mem_p, sizeof(t_mem_p));
    T_CHECK_RET(ret, T_OK, T_ERR);

    return T_OK;
}




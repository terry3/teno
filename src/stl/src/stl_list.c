#include "pub_def.h"
#include "stl_list.h"


F_RET stl_list_create(T_LIST **stl_list)
{
    T_LIST *t_list = T_NULL;
    P_NULL_RET(stl_list, F_FAILURE);

    t_list = (T_LIST *)malloc(sizeof(t_list));
    P_NULL_RET(t_list, F_FAILURE);

    t_list->head = T_NULL;
    t_list->size = 0;

    /* set list */
    *stl_list = t_list;
    return F_SUCCESS;
}

F_RET stl_list_insert(T_LIST *stl_list, T_VOID *stl_node, T_UINT32 node_size)
{
    T_LIST_NODE *tmp_node = T_NULL;
    T_LIST_NODE *t_node = (T_LIST_NODE *)malloc(sizeof(t_node) + node_size);
    T_LIST_NODE *t_head = T_NULL;

    P_NULL_RET(stl_list, F_FAILURE);
    P_NULL_RET(stl_node, F_FAILURE);

    P_NULL_RET(t_node, F_FAILURE);
    t_node->next = T_NULL;
    memcpy(t_node->data, stl_node, node_size);

    t_head = stl_list->head;

    if (T_NULL == t_head)
    {
        stl_list->head = t_node;
    }
    else
    {
        /* swap node */
        tmp_node = stl_list->head;
        stl_list->head = t_node;
        t_node->next = tmp_node;
    }
    stl_list->size++;
    return F_SUCCESS;
}

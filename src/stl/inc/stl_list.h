#include "pub_def.h"

#ifndef _T_LIST_H_
#define _T_LIST_H_


/* just a simple list. */

/* list node*/
typedef struct _list_node
{
    struct _list_node *next;
    T_UINT8 data[0];
}T_LIST_NODE;

/* list */
typedef struct
{
    T_LIST_NODE *head;
    T_UINT32     size;
}T_LIST;


/* function declare here */
extern F_RET stl_list_create(T_LIST **stl_list);
extern F_RET stl_list_insert(T_LIST *stl_list, T_VOID *stl_node, T_UINT32 node_size);

#endif /* _T_LIST_H_ */

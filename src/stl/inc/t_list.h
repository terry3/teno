#include "pub_def.h"

#ifndef _T_LIST_H_
#define _T_LIST_H_

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


#endif /* _T_LIST_H_ */

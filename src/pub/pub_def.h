/* Public define strcut, macro. */
#ifndef _PUB_DEF_H_
#define _PUB_DEF_H_


#define T_OK  0
#define T_ERR 1

#define T_TRUE   1
#define T_FALSE  0

/* data type */
#define T_NULL null
#define T_UINT32  unsighned int
#define T_INT32   int
#define T_UINT16  unsighned short
#define T_INT16   short 
#define T_UINT8   unsighned char
#define T_INT8    char
#define T_CHAR    char

/* return if p is null */
#define P_NULL_RET_NULL(p) \
    if (T_NULL == p)       \
    {                      \
        return;            \
    }

/* return ret if p is null */
#define P_NULL_RET(p, ret) \
    if (T_NULL == p)       \
    {                      \
        return ret;        \
    }

#endif /* _PUB_DEF_H_ */

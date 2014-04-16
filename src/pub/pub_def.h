/* Public define strcut, macro. */
#ifndef _PUB_DEF_H_
#define _PUB_DEF_H_


#define T_OK  0
#define T_ERR 1

#define T_TRUE   1
#define T_FALSE  0

/* data type */
#define T_NULL    null
typedef unsigned int   T_UINT32;
typedef int            T_INT32;
typedef unsigned short T_UINT16;
typedef short          T_INT16;
typedef unsigned char  T_UINT8;
typedef char           T_INT8;
typedef char           T_CHAR;
typedef unsigned int   F_RET;

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

/* teno_pub.h */
#ifndef TENO_PUB_H
#define TENO_PUB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_OK  0
#define T_ERR 1

#define T_TRUE   1
#define T_FALSE  0

/* function return type */
typedef enum E_F_RET_TYPE
{
    F_SUCCESS,
    F_FAILURE,
    F_BUTT,
}F_RET_TYPE;

/* data type */
#define T_NULL         NULL
#define T_VOID         void
typedef unsigned int   T_UINT32;
typedef int            T_INT32;
typedef unsigned short T_UINT16;
typedef short          T_INT16;
typedef unsigned char  T_UINT8;
typedef char           T_INT8;
typedef char           T_CHAR;
typedef unsigned int   F_RET;
typedef unsigned char  T_TOGGLE;

#define NULL_UINT32 0xFFFFFFFF
#define NULL_UINT16 0xFFFF
#define NULL_UINT8  0xFF

/* return if p is null */
#define PN_RET_N(p)                             \
    if (!(p))                          \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return;                                 \
    }

/* return ret if p is null */
#define PN_RET(_p, _ret)                        \
    if (!(_p))                                  \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return (_ret);                          \
    }

#define F_NCHK_RET(_t, _d, _ret)                \
    if ((_d) != (_t))                           \
    {                                           \
        return (_ret);                          \
    }

#define F_CHK_RET(_t, _d, _ret)                 \
    if ((_d) == (_t))                           \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return (_ret);                          \
    }

#define FR_RET(_ret)                            \
    if (T_OK != (_ret))                         \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return (_ret);                          \
    }

#define FR_BRK(_ret)                            \
    if (T_OK != (_ret))                         \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        break;                                  \
    }

#endif /* TENO_PUB_H */
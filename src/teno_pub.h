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
#define T_NULL NULL
#define T_VOID void
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

#define TENO_STR_TERM '\0'

/* teno string define */
typedef struct _teno_str
{
    T_CHAR   *str;              /* str do not have '\0' at last position */
    T_UINT32  len;
}TENO_STR;

/* return if p is null */
#define PN_RET_N(p)                             \
    if (!(p))                                   \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return;                                 \
    }

#define PN_BRK(p)                               \
    if (!(p))                                   \
    {                                           \
        break;                                  \
    }


/* return ret if p is null */
#define PN_RET(_p, _ret)                        \
    if (!(_p))                                  \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return (_ret);                          \
    }

#define CHK_RET(_p, _ret)                       \
    if (!(_p))                                  \
    {                                           \
  printf("[%s]:[%s]:(%d): " #_p " check failure.\n", \
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
  printf("[%s]:[%s]:(%d):return failured.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        return (_ret);                          \
    }

#define FR_RET_N(_ret)                          \
    if (T_OK != (_ret))                         \
    {                                           \
  printf("[%s]:[%s]:(%d):return not T_OK.\n",   \
  __FILE__, __FUNCTION__, __LINE__);            \
        return;                                 \
    }

#define FR_BRK(_ret)                            \
    if (T_OK != (_ret))                         \
    {                                           \
  printf("[%s]:[%s]:(%d):Null pointer.\n",      \
  __FILE__, __FUNCTION__, __LINE__);            \
        break;                                  \
    }

#define T_SAFE_FREE(_ptr) \
    if ((_ptr))                                 \
    {                                           \
        free((_ptr));                           \
        (_ptr) = T_NULL;                        \
    }

#define F_BZERO(_ptr, _len)                     \
    memset((_ptr), 0, (_len));

#define F_UNUSED(_var) \
    (T_VOID)(_var)



#endif /* TENO_PUB_H */

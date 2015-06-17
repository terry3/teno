#ifndef TENO_MSG_H
#define TENO_MSG_H


#define T_MSG_HEAD_LEN \
    sizeof(5 * sizeof(T_UINT32))

#define T_MSG_HEAD \
    T_UINT32 ul_from_sid;                       \
    T_UINT32 ul_to_sid;                         \
    T_UINT32 ul_from_pid;                       \
    T_UINT32 ul_to_pid;                         \
    T_UINT32 ul_length;                         \

typedef struct
{
    T_MSG_HEAD
    T_VOID   *p_data; /* 内存连续 */
}T_MSG;

#endif /* TENO_MSG_H */

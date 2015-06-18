#ifndef TENO_MSG_H
#define TENO_MSG_H


#define T_MSG_HEAD_LEN \
    sizeof(6 * sizeof(T_UINT32))

#define T_MSG_HEAD \
    T_UINT32 ul_from_sid;                       \
    T_UINT32 ul_to_sid;                         \
    T_UINT32 ul_from_pid;                       \
    T_UINT32 ul_to_pid;                         \
    T_UINT32 ul_length;                         \
    T_UINT32 ul_type;

typedef struct
{
    T_MSG_HEAD
    T_CHAR   data[0]; /* 内存连续 */
}T_MSG;


/* function declare */
extern T_MSG* teno_msg_alloc_msg(T_UINT32 ul_length);
extern T_VOID teno_msg_free_msg(T_MSG *ps_msg);
extern F_RET teno_msg_send(T_MSG *ps_msg);

#endif /* TENO_MSG_H */

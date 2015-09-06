#ifndef TENO_STRING_H
#define TENO_STRING_H

extern T_CHAR* teno_str_cpy2(T_CHAR *pc_src);
extern F_RET teno_str_split_cmd(T_CHAR *pc_cmd, TENO_CMD *ps_cmd);
extern F_RET teno_str_cvt_char
(TENO_STR *ps_str, T_CHAR *pc_buf, T_UINT32 ul_buf_len);

#endif /* TENO_STRING_H */

#ifndef TENO_VAR_H
#define TENO_VAR_H

#define DEFINE_VAR(_name, _value) \
    {#_name, _value}

#define VAR_TRACE_T "var_trace_t"

typedef struct _teno_var {
    T_CHAR   *pc_var_name;
    T_UINT32  ul_var_value;
}TENO_VAR;

extern F_RET teno_set_var(T_CHAR *pc_var_name, T_UINT32 ul_var_value);
extern T_UINT32 teno_get_var(T_CHAR *pc_var_name);
extern F_RET teno_var_getvar_handler(TENO_CMD *ps_cmd);
extern T_UINT32 teno_var_setvar_handler(TENO_CMD *ps_cmd);

#endif /* TENO_VAR_H */

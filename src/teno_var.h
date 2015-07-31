#ifndef TENO_VAR_H
#define TENO_VAR_H

#define DEFINE_VAR(_name, _value) \
    {#_name, _value}

typedef struct _teno_var {
    T_CHAR   *pc_var_name;
    T_UINT32  ul_var_value;
}TENO_VAR;

extern F_RET teno_set_var(T_CHAR *pc_var_name, T_UINT32 ul_var_value);
extern T_UINT32 teno_get_var(T_CHAR *pc_var_name);


#endif /* TENO_VAR_H */

export obj-log = log_api.o

export VPATH += ./src
export VPATH += ./inc

export obj += $(obj-log)

export TENO_INC_PATH = -I./inc -I../pub


$(obj-log): %.o:%.c
#   $(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@
	$(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)

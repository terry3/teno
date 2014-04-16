include ../../var.mk

export TENO_INC_PATH = -I$(abspath ../pub)     \
				       -I$(abspath ./inc)

export TENO_OBJ_PATH = $(abspath ../../obj)

export VPATH += ./src
export VPATH += ./inc

$(obj-log): %.o:%.c
#   $(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@
	$(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)

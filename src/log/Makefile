include ../../var.mk

export TENO_INC_PATH = -I$(abspath ../pub)     \
				       -I$(abspath ./inc)

export TENO_OBJ_PATH = $(abspath ../../obj)

export VPATH += ./src
export VPATH += ./inc

all-obj-log = $(addprefix $(TENO_OBJ_PATH)/, $(obj-log))  

log-all:$(all-obj-log)
	@echo $(notdir $(all-obj-log))

$(all-obj-log):$(TENO_OBJ_PATH)/%.o:%.c
	$(CC) -c $(CFLAGS) $< -o $@ $(TENO_INC_PATH)

.PHONY:clean

clean:
	-rm $(all-obj-log)

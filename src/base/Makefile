include ../../var.mk

export TENO_INC_PATH = -I$(abspath ../pub)     \
					   -I$(abspath ./inc)      \
					   -I$(abspath ../stl/inc) \
					   -I$(abspath ../mem/inc)

export TENO_OBJ_PATH = $(abspath ../../obj)

export VPATH += ./src

export VPATH += ./inc
export VPATH += ../stl/inc

export VPATH += ../pub



all-obj-base = $(addprefix $(TENO_OBJ_PATH)/, $(obj-base))

base-all:$(all-obj-base)
	@echo $(notdir $(all-obj-base))

$(all-obj-base):$(TENO_OBJ_PATH)/%.o:%.c %.h $(TENO_PUB_HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ $(TENO_INC_PATH)

.PHONY:clean

clean:
	-rm $(all-obj-base)

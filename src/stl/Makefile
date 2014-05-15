include ../../var.mk

export TENO_INC_PATH = -I$(abspath ../pub)     \
					   -I$(abspath ./inc)

export TENO_OBJ_PATH = $(abspath ../../obj)

export VPATH += ./src
export VPATH += ./inc
export VPATH += ../pub



all-obj-stl = $(addprefix $(TENO_OBJ_PATH)/, $(obj-stl))

stl-all:$(all-obj-stl)
	@echo $(notdir $(all-obj-stl))

$(all-obj-stl):$(TENO_OBJ_PATH)/%.o:%.c %.h $(TENO_PUB_HEADER)
	$(CC) -c $(CFLAGS) $< -o $@ $(TENO_INC_PATH)

.PHONY:clean

clean:
	-rm $(all-obj-stl)

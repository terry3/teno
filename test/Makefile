EXE=teno

export VPATH += ../src
export VPATH += ../obj
export VPATH += ../src/pub
include ../var.mk	
obj-test = main.o

export TENO_SRC_PATH = $(abspath ../src)
export TENO_OBJ_PATH = $(abspath ../obj)
export TENO_BUILD_PATH = $(abspath ../build)

export TENO_INC_PATH += -I$(abspath ../src/pub) \
						-I$(abspath ../src/log/inc)

$(EXE): $(obj-test) $(obj-log)
	cd $(TENO_SRC_PATH) && $(MAKE)
	$(CC) -o  $(TENO_BUILD_PATH)/$@ $(TENO_OBJ_PATH)/$^

$(obj-test): %.o:%.c
	$(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)


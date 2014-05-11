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

T_EXE = $(addprefix $(TENO_BUILD_PATH)/, $(EXE))

all-obj-log = $(addprefix $(TENO_OBJ_PATH)/, $(obj-log))

VPATH += $(TENO_SRC_PATH)/pub
VPATH += $(TENO_SRC_PATH)/log/inc
VPATH += $(TENO_SRC_PATH)/log/src

all-files = $(notdir $(wildcard $(TENO_SRC_PATH)/pub/*.h)) \
        $(notdir $(wildcard $(TENO_SRC_PATH)/log/inc/*.h)) \
        $(notdir $(wildcard $(TENO_SRC_PATH)/log/src/*.c)) 

$(T_EXE): $(obj-test) $(all-files)
	cd $(TENO_SRC_PATH) && $(MAKE)
	$(CC) $(CFLAGS) $(TENO_OBJ_PATH)/* -o  $@ 

$(obj-test): %.o:%.c $(TENO_PUB_HEADER)
	$(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)

.PHONY:clean

clean:
	-rm $(TENO_OBJ_PATH)/*
	-rm $(TENO_BUILD_PATH)/*


EXE=teno

export VPATH += ../src
export VPATH += ../obj
export VPATH += ../src/pub
export VPATH += ../src/log/inc

obj-log = log_api.o

obj-test = main.o

TENO_SRC_PATH = ../src
TENO_OBJ_PATH = $(abspath ../obj)

TENO_INC_PATH = -I../src/pub -I../src/log/inc

TENO_BUILD_PATH = ../build

$(EXE): $(obj-test) $(obj-log)
	cd $(TENO_SRC_PATH) && $(MAKE)
	$(CC) -o  $(TENO_BUILD_PATH)/$@ $^

$(obj-test): %.o:%.c
	$(CC) -c $(CFLAGS) $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)


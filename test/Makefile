EXE=teno

export VPATH += ../src
export VPATH += ../obj
export VPATH += ../src/pub
include ../var.mk

obj-test = main.o

export TENO_SRC_PATH = $(abspath ../src)
export TENO_OBJ_PATH = $(abspath ../obj)
export TENO_BUILD_PATH = $(abspath ../build)

GTEST_PATH = $(abspath ./gtest-1.7.0)
GTEST_INC_PATH = $(GTEST_PATH)/include
GTEST_LIB_PATH = -L$(GTEST_PATH)/lib/.libs

export TENO_INC_PATH += -I$(abspath ../src/pub)      \
						-I$(abspath ../src/log/inc)	 \
						-I$(abspath ../src/stl/inc)	 \
						-I$(abspath ../src/mem/inc)	 \
						-I$(abspath ../src/base/inc) \
						-I$(abspath $(GTEST_INC_PATH))

T_EXE = $(addprefix $(TENO_BUILD_PATH)/, $(EXE))

all-obj-log = $(addprefix $(TENO_OBJ_PATH)/, $(obj-log))

VPATH += $(TENO_SRC_PATH)/pub
VPATH += $(TENO_SRC_PATH)/log/inc
VPATH += $(TENO_SRC_PATH)/log/src
VPATH += $(TENO_SRC_PATH)/mem/src
VPATH += $(TENO_SRC_PATH)/mem/inc
VPATH += $(TENO_SRC_PATH)/stl/src
VPATH += $(TENO_SRC_PATH)/stl/inc
VPATH += $(TENO_SRC_PATH)/base/src
VPATH += $(TENO_SRC_PATH)/base/inc
VPATH += $(GTEST_INC_PATH)


all-files = $(notdir $(wildcard $(TENO_SRC_PATH)/pub/*.h))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/log/inc/*.h))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/log/src/*.c))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/stl/src/*.c))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/mem/src/*.c))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/base/src/*.c))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/stl/inc/*.h))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/base/inc/*.h))		\
		$(notdir $(wildcard $(TENO_SRC_PATH)/mem/inc/*.h))

$(T_EXE): $(obj-test) $(all-files)
	cd $(TENO_SRC_PATH) && $(MAKE)
	g++ -g  $(TENO_OBJ_PATH)/* -o  $@ $(GTEST_LIB_PATH) -lgtest -lpthread

$(obj-test): %.o:%.c $(TENO_PUB_HEADER)
	g++ -c -g $< -o $(TENO_OBJ_PATH)/$@ $(TENO_INC_PATH)

.PHONY:clean

clean:
	-rm $(TENO_OBJ_PATH)/*
	-rm $(TENO_BUILD_PATH)/*

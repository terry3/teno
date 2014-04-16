EXE=teno
DEPANDS=$(wildcard ./src/pub/*.h)
export VPATH =+ ./pub/

export obj

MAKE = make

export TENO_OBJ_PATH = $(abspath ../obj)

TENO_LOG_PATH = ./log/
TENO_TEST_PATH = ../test/

all:
	cd $(TENO_LOG_PATH) && $(MAKE)

.PHONY : clean
clean :
	-rm  $(TENO_OBJ_PATH)/*

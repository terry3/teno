EXE=teno
DEPANDS=$(wildcard ./src/pub/*.h)
export VPATH =+ ./pub/	
include ../var.mk

all:
	cd $(TENO_LOG_PATH) && $(MAKE)

.PHONY : clean
clean :
	-rm  $(TENO_OBJ_PATH)/*

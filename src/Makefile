EXE=teno
DEPANDS=$(wildcard ./src/pub/*.h)
export VPATH =+ ./pub/
include ../var.mk

TENO_LOG_PATH	= ./log
TENO_STL_PATH	= ./stl
TENO_BASE_PATH	= ./base


TENO_OBJ_PATH = ../obj

export TENO_PUB_HEADER = pub_def.h pub_inc.h

all:
	cd $(TENO_LOG_PATH)			&& $(MAKE)
	cd $(TENO_STL_PATH)			&& $(MAKE)
	cd $(TENO_BASE_PATH)		&& $(MAKE)

.PHONY : clean
clean :
	-rm  $(TENO_OBJ_PATH)/*

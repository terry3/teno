lib=libteno.so
EXP=teno_exp_1
OBJS=example_1.o
CFLAGS=-g -Wall
PUB_HDR=teno.h
DEPS:=$(wildcard ../src/*.c) $(wildcard ../src/*.h)

all:$(EXP)

$(OBJS):%.o:%.c ../src/$(PUB_HDR)
		$(CC) -c $(CFLAGS) $< -o $@ -I../src/

$(EXP):$(OBJS) $(DEPS)
	cd ../src/ && make
	$(CC) -o $@ example_1.o -lteno -lpthread -L../
	cp -p ../libteno.so /usr/lib/
.PHONY : clean
clean :
	-rm  $(OBJS)
	-rm  $(EXP)

lib=libteno.so
EXP_1=teno_exp_1
EXP_2_s=teno_exp_2_server
EXP_2_c=teno_exp_2_client
OBJS=example_1.o example_2_server.o example_2_client.o
CFLAGS=-g -Wall
PUB_HDR=teno.h
DEPS:=$(wildcard ../src/*.c) $(wildcard ../src/*.h)

all:$(EXP_1) $(EXP_2_s) $(EXP_2_c)

$(OBJS):%.o:%.c ../src/$(PUB_HDR)
		$(CC) -c $(CFLAGS) $< -o $@ -I../src/

$(EXP_1):$(OBJS) $(DEPS)
	cd ../src/ && make
	$(CC) -o $@ example_1.o -lteno -lpthread -L../
	cp -p ../libteno.so /usr/lib/

$(EXP_2_s):example_2_server.o $(DEPS)
	cd ../src/ && make
	$(CC) -o $@ example_2_server.o -lteno -lpthread -L../
	cp -p ../libteno.so /usr/lib/
$(EXP_2_c):example_2_client.o $(DEPS)
	cd ../src/ && make
	$(CC) -o $@ example_2_client.o -lteno -lpthread -L../
	cp -p ../libteno.so /usr/lib/

.PHONY : clean
clean :
	-rm  $(OBJS)
	-rm  $(EXP_1) $(EXP_2_s) $(EXP_2_c)

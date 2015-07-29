EXP=teno_exp_1
OBJS=example_1.o
CFLAGS=-g -Wall
PUB_HDR=teno.h

all:$(EXP)

$(OBJS):%.o:%.c ../src/$(PUB_HDR)
		$(CC) -c $(CFLAGS) $< -o $@ -I../src/

$(EXP):$(OBJS) ../libteno.so
	$(CC) -o $@ $^ -lteno -lpthread -L../

.PHONY : clean
clean :
	-rm  $(OBJS)
	-rm  $(EXP)

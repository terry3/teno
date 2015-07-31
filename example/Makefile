<<<<<<< HEAD
lib=libteno.so
=======
>>>>>>> f7e919cd6cd80271e7cba7cddcf079203eb032b1
EXP=teno_exp_1
OBJS=example_1.o
CFLAGS=-g -Wall
PUB_HDR=teno.h
<<<<<<< HEAD
DEPS:=$(wildcard ../src/*.c) $(wildcard ../src/*.h)
=======
>>>>>>> f7e919cd6cd80271e7cba7cddcf079203eb032b1

all:$(EXP)

$(OBJS):%.o:%.c ../src/$(PUB_HDR)
		$(CC) -c $(CFLAGS) $< -o $@ -I../src/

<<<<<<< HEAD
$(EXP):$(OBJS) $(DEPS)
	cd ../src/ && make
	$(CC) -o $@ example_1.o -lteno -lpthread -L../
	ln -s ../libteno.so ./libteno.so
=======
$(EXP):$(OBJS) ../libteno.so
	$(CC) -o $@ $^ -lteno -lpthread -L../

>>>>>>> f7e919cd6cd80271e7cba7cddcf079203eb032b1
.PHONY : clean
clean :
	-rm  $(OBJS)
	-rm  $(EXP)

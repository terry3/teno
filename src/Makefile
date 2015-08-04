lib=libteno.so
PUB_HDR=teno_pub.h teno_type.h teno.h
OBJS=teno.o teno_cli.o teno_service.o teno_mq.o teno_msg.o teno_sci.o \
     teno_str.o teno_var.o teno_trace.o teno_monitor.o teno_socket_unix.o
CFLAGS=-g -Wall -D TENO_DEBUG

all:$(lib)
	mv $(lib) ../

$(OBJS):%.o:%.c %.h $(PUB_HDR)
		$(CC)  -c $(CFLAGS) $< -o $@

$(lib):$(OBJS)
	$(CC) -o $@ -shared $^

.PHONY : clean
clean :
	-rm  $(OBJS)
	-rm  ../$(lib)

check-syntax:
	gcc -o nul -S ${CHK_SOURCES}

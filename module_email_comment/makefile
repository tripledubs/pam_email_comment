P=verify_email
OBJECTS = verify_email.o
DOCDIRS = latex man html
CFLAGS = -Wall -Wpedantic -std=c11 -D_GNU_SOURCE -fPIC -fno-stack-protector
ifdef SPEEDY
    CFLAGS += -O3
else
    CFLAGS += -O0 -g
endif

ifdef DEBUG
	CFLAGS +=-DDEBUG=1
endif
LDLIBS=$(OBJECTS) -lm -lreadline#-lraylib
CC=gcc

verify_email.o: verify_email.c

install:
	ld -x --shared -o /usr/lib/verify_email.so verify_email.o
	ld -x --shared -o /usr/lib32/verify_email.so verify_email.o

docs:
	doxygen docs.config


clean: 
	rm -rf *BAK *o *core vgcore* $P $(OBJECTS) $(DOCDIRS)
	rm -f *~

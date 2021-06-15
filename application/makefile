P=main
OBJECTS= authenticate.o treasure.o
DOCDIRS = latex man html
CFLAGS = -Wall -Wpedantic -std=c11 -D_GNU_SOURCE
ifdef SPEEDY
	CFLAGS += -O3
else
	CFLAGS += -O0 -g3
endif

ifdef DEBUG
	CFLAGS +=-DDEBUG=1
endif

LDLIBS= -lpam -lreadline
CC=gcc10

$(P):$(OBJECTS)

docs:
	doxygen docs.config


clean: 
	rm -rf *BAK *o *core vgcore* $P $(OBJECTS) $(DOCDIRS)
	rm -f *~

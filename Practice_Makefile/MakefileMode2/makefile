SRCS := $(wildcard *.c)
OUTS = $(patsubst %.c,%,$(SRCS))
CC := gcc
.PHONY: clean rebuild all

all : $(OUTS)
% : %.c
	$(CC) $< -o $@ 

clean:
	$(RM) $(OUTS)

rebuild : clean all
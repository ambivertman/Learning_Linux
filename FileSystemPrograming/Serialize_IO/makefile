SRCS:= $(wildcard *.c)
TEMP2:= $(patsubst %.c, %, $(SRCS))
CC:= gcc
all: $(TEMP2)
%: %.c
	$(CC) $< -o $@
.PHONY: clean rebuild
clean:
	$(RM) $(TEMP2)
rebuild: clean main

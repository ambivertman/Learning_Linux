OUT := main
OBJS := main.o my_add.o
CC := gcc

$(OUT):$(OBJS)
	$(CC) $^ -o $@

%.o : %.c my_add.h
	$(CC) -c $< -o $@ 

.PHONY: clean rebuild
clean:
	$(RM) $(OUT) $(OBJS)

rebuild: clean $(OUT)

OUT := main
SRCS := $(wildcard *.c) #将当前目录下的所有.c文件的文件名以空格分割，然后赋值给SRCS变量
OBJS := $(patsubst %.c,%.o,$(SRCS)) #获取当前目录下所有.c文件对应的.o文件，以空格分割
COM_OP := -Wall -g 
CC := gcc        #修改CC的默认值

$(OUT):$(OBJS)
	$(CC) $^ -o $@
%.o : %.c header.h
	$(CC) -c $< -o $@ $(COM_OP)

.PHONY: clean rebuild
clean:
	$(RM) $(OUT) $(OBJS)
rebuild: clean $(OUT)

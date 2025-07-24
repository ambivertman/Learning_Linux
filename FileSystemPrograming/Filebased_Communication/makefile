# ---------------------------------
#      变量定义 (Configuration)
# ---------------------------------
# 使用的编译器
CC = gcc
# 编译选项:
# -Wall: 显示所有警告
# -g:    生成调试信息，方便使用gdb调试
# -I.:   在当前目录(.)寻找头文件(#include "...")
CFLAGS = -Wall -g -I.
# 链接选项 (这里为空，可根据需要添加，如 -lm)
LDFLAGS =
# 删除文件的命令
RM = rm -f


# ---------------------------------
#      目标定义 (Targets)
# ---------------------------------
# 最终要生成的可执行文件
TARGETS = a b

# 定义 'a' 所需的目标文件
A_OBJS = a.o commute.o

# 定义 'b' 所需的目标文件
B_OBJS = b.o commute.o


# ---------------------------------
#      规则 (Rules)
# ---------------------------------

# 默认规则：放在最前面，当执行 `make` 时会默认执行此规则
# .PHONY 告诉 make，'all' 不是一个文件名，而是一个动作
.PHONY: all
all: $(TARGETS)

# --- 链接规则 ---
# 如何从目标文件(.o)生成可执行文件 'a'
a: $(A_OBJS)
	$(CC) $(LDFLAGS) $(A_OBJS) -o a

# 如何从目标文件(.o)生成可执行文件 'b'
b: $(B_OBJS)
	$(CC) $(LDFLAGS) $(B_OBJS) -o b

# --- 编译规则 ---
# 这是一个通用的模式规则，告诉 make 如何从任意 .c 文件生成 .o 文件
# $< 代表第一个依赖项 (即 .c 文件)
# $@ 代表目标文件 (即 .o 文件)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# --- 依赖关系 ---
# 这里是关键！明确指出每个 .o 文件依赖哪些头文件
# 如果任何一个头文件被修改，make 将会重新编译对应的 .o 文件
# 注意: 这里只需要写依赖，不需要写命令，make 会自动使用上面的模式规则
a.o: a.c commute.h header.h
b.o: b.c commute.h header.h
commute.o: commute.c commute.h


# --- 清理规则 ---
# .PHONY 告诉 make，'clean' 不是一个文件名
.PHONY: clean
clean:
	$(RM) $(TARGETS) *.o   
# 删除所有可执行文件和所有.o文件
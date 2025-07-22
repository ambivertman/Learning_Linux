# 1. 使用 wildcard 函数找到当前目录下所有的 .c 文件
SOURCES := $(wildcard *.c)

# 2. 使用 patsubst 函数将 .c 文件名列表替换为 .o 文件名列表
# 例如，如果 SOURCES 是 "main.c utils.c"，OBJECTS 将会是 "main.o utils.o"
OBJECTS := $(patsubst %.c, %.o, $(SOURCES))

# 3. 定义伪目标 "all"，它的依赖是所有的 .o 文件
# 这是默认目标，当直接运行 `make` 命令时会执行它
all: $(OBJECTS)

# 4. 这是核心的模式规则，它告诉 make 如何从任何 .c 文件生成对应的 .o 文件
# %.o: 目标文件的模式
# %.c: 依赖文件的模式
# $<: 代表第一个依赖文件（即 .c 文件）
# $@: 代表目标文件（即 .o 文件）
# 编译命令：gcc -c <源文件名> -o <目标文件名>
%.o: %.c
	gcc -c $< -o $@

# 5. 定义一个 "clean" 规则，用于清理生成的文件
# .PHONY 告诉 make，"clean" 不是一个真实的文件名，而是一个动作
.PHONY: clean

# rm -f 表示强制删除，即使文件不存在也不报错
clean:
	rm -f $(OBJECTS)
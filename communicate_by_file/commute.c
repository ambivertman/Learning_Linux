#include "commute.h"

void send_stdin(int fd, char* buf) {
    ssize_t read_ret = read(STDIN_FILENO, buf, Buf_Size);

    printf("sending:");
    write(fd, buf, read_ret);

    memset(buf, 0, Buf_Size);
}

void receive(int fd, char* buf) {
    ssize_t read_ret;
    while (1) {
        read_ret = read(fd, buf, Buf_Size);
        //read_ret的情况有-1 文件不存在, 0 读到文件末尾,此外0是说明已经读过但是读到尾了,
        //说明文件没有更新
        // 读到n个字节
        //而我需要的是只有读到n个字节才进入流程, 否者就一直阻塞在这里
        //能进入循环说明读取到内容了, 就要打印读取到的内容
        if (read_ret <= 0) {
            continue;
        }
        printf("received:%s\n", buf);
    }
}
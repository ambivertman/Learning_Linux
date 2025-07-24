#include "commute.h"

void send_stdin(char* path, char* buf) {
    int fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0666);
    ssize_t read_ret = read(STDIN_FILENO, buf, Buf_Size);

    printf("sending:");
    write(fd, buf, read_ret);
    close(fd);
    memset(buf, 0, Buf_Size);
}

void receive(char* path, char* buf) {
    while (1) {
        int fd = open(path, O_RDONLY);
        //read_ret的情况有-1 文件不存在
        // 读到n个字节
        //而我需要的是只有读到n个字节才进入流程, 否者就一直阻塞在这里
        //能进入循环说明读取到内容了, 就要打印读取到的内容
        if (fd == -1) {
            sleep(1);
            continue;
        }
        read(fd, buf, Buf_Size);
        printf("received:%s\n", buf);
        close(fd);
        memset(buf, 0, Buf_Size);
        remove(path);
        break; // 读取到内容后跳出循环
    }
}
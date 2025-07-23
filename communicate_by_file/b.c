#include "header.h"
#include "commute.h"



int main(int argc, char* argv[]) {
    //1.先打开需要使用的文件流
    int fd = open("./1.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

    char buf[Buf_Size] = { 0 };
    while (1) {
        printf("B ");
        receive(fd, buf);

        printf("B is ");
        send_stdin(fd, buf);
    }


    return 0;
}


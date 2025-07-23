#include "header.h"
#include "commute.h"



int main(int argc, char* argv[]) {
    //1.先打开需要使用的文件流
    int fd = open("./1.txt", O_RDWR | O_CREAT | O_APPEND, 0666);

    char buf[Buf_Size] = { 0 };
    while (1) {
        //2.读取标准输入并写入文件
        printf("A is ");
        send_stdin(fd, buf);
        //3.等待b发送消息到文件, 接收到之后打印输出,
        //这一步需要解决的流程是:
        //a)获取文件的更新状态, 是否可以通过读文件读到0,
        //b)确定更新后读取, 然后读入并打印
        //receive 是一个阻塞函数
        printf("A ");
        receive(fd, buf);
    }


    return 0;
}


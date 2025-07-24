// a.c
#include "header.h"
#include "commute.h"

int main(int argc, char* argv[]) {
    char buf[Buf_Size] = { 0 };
    while (1) {
        printf("====A's Turn====\n");

        // 1. A 发送消息给 B
        // 使用 a_to_b.txt 文件
        printf("A sends: ");
        send_stdin("./a_to_b.txt", buf);

        // 2. A 等待并接收来自 B 的消息
        // 应该监听 b_to_a.txt 文件
        printf("A is waiting for B...\n");
        receive("./b_to_a.txt", buf);
    }
    return 0;
}
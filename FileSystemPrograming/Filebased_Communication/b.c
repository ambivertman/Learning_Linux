// b.c
#include "header.h"
#include "commute.h"

int main(int argc, char* argv[]) {
    char buf[Buf_Size] = { 0 };
    while (1) {
        printf("====B's Turn====\n");

        // 1. B 等待并接收来自 A 的消息
        // 应该监听 a_to_b.txt 文件
        printf("B is waiting for A...\n");
        receive("./a_to_b.txt", buf);

        // 2. B 发送消息给 A
        // 使用 b_to_a.txt 文件
        printf("B sends: ");
        send_stdin("./b_to_a.txt", buf);
    }
    return 0;
}
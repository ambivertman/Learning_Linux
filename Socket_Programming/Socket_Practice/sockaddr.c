#include<header.h>

int main(void) {
    char* ip = "192.168.0.1";
    char* port = "8080";
    //sockaddr是一种通用的结构体,可以使用
    //sockaddr_in 和 sockaddr_in6分别适配IPv4和IPv6
    struct sockaddr_in  sock = { 0 };
    //AF_INET表示使用IPv4
    sock.sin_family = AF_INET;

    //数据在计算机内一般以小端存储,在网络上采用大段存储
    //所以需要将端口号进行转换
    sock.sin_port = htons(atoi(port));

    //ip地址可以通过inet_addr(const char * p)进行转换
    //sin_addr也是一个结构体需要进一步访问其成员进行赋值
    sock.sin_addr.s_addr = inet_addr(ip);

    return 0;
}
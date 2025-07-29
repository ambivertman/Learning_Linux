#include<header.h>

int main(void) {
    //服务器IP地址与端口号
    char *ip = "10.0.16.6";
    char *port = "8080";
    //创建socket对象,分别设置为IPv4与TCP
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    //构建sockaddr结构体
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = inet_addr(ip);
    socketAddr.sin_port = htons(atoi(port));
    //使用connect进行连接
    connect(socket_fd, (struct sockaddr *)&socketAddr, sizeof(socketAddr));

    while (1) {
        char buf[60] = { 0 };
        //读取标准缓冲区发送给服务器
        read(STDIN_FILENO, buf, sizeof(buf));
        //发送给服务器
        send(socket_fd, buf, strlen(buf), 0);

        //接收服务器的消息
        memset(buf, 0, strlen(buf));
        recv(socket_fd, buf, sizeof(buf), 0);
        //打印收到的消息
        printf("received: %s\n", buf);
    }

    close(socket_fd);
    return 0;
}
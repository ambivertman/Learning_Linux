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

    //创建监听集合
    fd_set set;
    while (1) {
        //初始化监听集合
        FD_ZERO(&set);
        //将需要监听的设备加入监听集合
        FD_SET(STDIN_FILENO, &set);
        FD_SET(socket_fd, &set);

        //调用select()对设备进行监听
        //轮询的数量/监听集合/
        select(socket_fd + 1, &set, NULL, NULL, NULL);

        //判断是哪个设备就绪
        if (FD_ISSET(STDIN_FILENO, &set)) {
            char buf[60] = { 0 };
            //读取键盘输入给客户端发送消息
            read(STDIN_FILENO, buf, sizeof(buf));
            send(socket_fd, buf, strlen(buf), 0);
        }
        if (FD_ISSET(socket_fd, &set)) {
            char buf[60] = { 0 };
            //接收客户端发来的消息
            int ret = recv(socket_fd, buf, sizeof(buf), 0);
            if (ret == 0) {
                //说明对方已经断开连接
                break;
            }
            //打印
            printf("received: %s\n", buf);
        }
    }
    close(socket_fd);
    return 0;
}
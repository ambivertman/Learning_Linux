#include<header.h>

int main(void) {
    char *ip = "10.0.16.6";
    char *port = "8080";
    //创建socket对象
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    //初始化sockaddr结构体
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = inet_addr(ip);
    socketAddr.sin_port = htons(atoi(port));

    //绑定端口IP
    bind(socket_fd, (struct sockaddr *)&socketAddr, sizeof(socketAddr));

    //监听端口, socket_fd, 队列长度
    listen(socket_fd, 10);

    //为完成三次挥手的请求建立一个socket一对一服务
    //accept 返回一个socket对象的文件描述符数组下标
    int client_fd = accept(socket_fd, NULL, NULL);
    printf("Client connected\n");

    //创建监听集合
    fd_set set;
    while (1) {
        //初始化监听集合
        FD_ZERO(&set);
        //将需要监听的设备加入监听集合
        FD_SET(STDIN_FILENO, &set);
        FD_SET(client_fd, &set);

        //调用select()对设备进行监听
        //轮询的数量/监听集合/
        select(client_fd + 1, &set, NULL, NULL, NULL);

        //判断是哪个设备就绪
        if (FD_ISSET(STDIN_FILENO, &set)) {
            char buf[60] = { 0 };
            //读取键盘输入给客户端发送消息
            read(STDIN_FILENO, buf, sizeof(buf));
            send(client_fd, buf, strlen(buf), 0);
        }
        if (FD_ISSET(client_fd, &set)) {
            char buf[60] = { 0 };
            //接收客户端发来的消息
            recv(client_fd, buf, sizeof(buf), 0);
            //打印
            printf("received: %s\n", buf);
        }
    }

    return 0;
}
#include<header.h>
#define MAX_SOCKET 100


int main(void) {
    char *ip = "10.0.16.6";
    char *port = "8080";
    //创建socket对象
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    //实现如果端口被time_wait占用也可以重新使用该端口
    int reuse = 1;
    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    //初始化sockaddr结构体
    struct sockaddr_in socketAddr;
    socketAddr.sin_family = AF_INET;
    socketAddr.sin_addr.s_addr = inet_addr(ip);
    socketAddr.sin_port = htons(atoi(port));

    //绑定端口IP
    bind(socket_fd, (struct sockaddr *)&socketAddr, sizeof(socketAddr));

    //监听端口, socket_fd, 队列长度
    listen(socket_fd, 10);

    //用于监听服务用户的socket
    int fds[MAX_SOCKET] = { 0 };
    int size = 0; //当前监听集大小

    //创建监听集合并初始化
    //base_set用于记录下一次循环需要监听的设备
    fd_set base_set;
    FD_ZERO(&base_set);
    FD_SET(socket_fd, &base_set);


    while (1) {
        //temp_set用于记录当前循环需要监听的设备
        fd_set temp_set;
        memcpy(&temp_set, &base_set, sizeof(base_set));
        //调用select()对设备进行监听
        //轮询的数量/监听集合/
        select(MAX_SOCKET, &temp_set, NULL, NULL, NULL);

        //判断是哪个设备就绪
        //如果是socket_fd说明有新链接进入
        if (FD_ISSET(socket_fd, &temp_set)) {
            fds[size] = accept(socket_fd, NULL, NULL);
            FD_SET(fds[size], &base_set);
            size++;
        }
        //遍历fds查看哪些客户端可读,进行处理
        for (int i = 0;i < size;i++) {
            if (FD_ISSET(fds[i], &temp_set)) {
                char buf[60] = { 0 };
                //接收客户端发来的消息
                ssize_t ret = recv(fds[i], buf, sizeof(buf), 0);

                //如果返回值为0,说明该客户端断开连接
                //需要关闭对于该客户端的监听
                if (ret == 0) {
                    FD_CLR(fds[i], &base_set);
                    close(fds[i]);
                    //调整剩下的socket对象在fds中的位置
                    int temp = fds[size - 1];
                    fds[i] = temp;
                    fds[size - 1] = 0;
                }
                //转发消息
                for (int j = 0;j < size;j++) {
                    if (j == i) {
                        continue;
                    }
                    send(fds[j], buf, strlen(buf), 0);
                }
            }
        }
    }

    return 0;
}
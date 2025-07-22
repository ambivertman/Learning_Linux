#include "header.h"

int main(int argc, char* argv[]) {
    //获取当前工作目录
    char cwd[100] = { 0 };
    getcwd(cwd, sizeof(cwd));
    char src[150] = { 0 };

    sprintf(src, "%s/%s", cwd, argv[1]);
    //通过open打开源文件
    int fd = open(src, O_RDONLY);
    //打开之后要ERROR_CHECK
    ERROR_CHECK(fd, -1, "open source file");

    //通过read将文件中的内容读入到buf
    char buf[50] = { 0 };
    ssize_t read_ret = read(fd, buf, sizeof(buf));
    ERROR_CHECK(read_ret, -1, "read");

    close(fd);

    //通过open创建一个目标文件
    char dst[150] = { 0 };
    sprintf(dst, "%s/%s", cwd, argv[2]);
    fd = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    ERROR_CHECK(fd, -1, "open dest file");

    //将数据写入新的文件
    ssize_t write_ret = write(fd, buf, read_ret);
    ERROR_CHECK(write_ret, -1, "write");

    close(fd);

    return 0;
}


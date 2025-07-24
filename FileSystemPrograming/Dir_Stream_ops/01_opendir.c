#include "header.h"

int main(int argc, char * argv[]){
    //打开目录流, 返回一个指针, 指向一个容器中的第一项
    //容器里面保存着当前目录下的所有目录项
    DIR * dir = opendir("./");
    ERROR_CHECK(dir,NULL,"opendir");

    //读取目录项
    struct dirent * dirent = readdir(dir);
    while(dirent != NULL){
        printf("%s\n",dirent->d_name);
        dirent = readdir(dir);
    }
    closedir(dir);

    return 0;
}


#include "header.h"

void filecmp(char* path1, char* path2) {
    int fd1, fd2;
    fd1 = open(path1, O_RDONLY);
    fd2 = open(path2, O_RDONLY);

    char buf1[100] = { 0 };
    char buf2[100] = { 0 };

    read(fd1, buf1, sizeof(buf1));
    read(fd2, buf2, sizeof(buf2));

    close(fd1);
    close(fd2);
    if (strcmp(buf1, buf2) == 0) {
        printf("%s and %s are the same.\n", path1, path2);
    }
    else {
        printf("%s and %s are different.\n", path1, path2);
    }
}

int main(int argc, char* argv[]) {
    filecmp("./1.txt", "./2.txt");
    filecmp("./1.txt", "./3.txt");

    return 0;
}


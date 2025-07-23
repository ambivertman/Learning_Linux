#include "header.h"
void getdircount(char* pathname, int* count, int* sizeof_txt) {
    DIR* dir = opendir(pathname);
    struct dirent* dent = readdir(dir);

    while (dent != NULL) {
        if (dent->d_type == DT_REG && strcmp(dent->d_name, "1.txt") == 0) {
            char buf[300] = { 0 };
            sprintf(buf, "%s/%s", pathname, dent->d_name);
            struct stat st;
            stat(buf, &st);
            (*sizeof_txt) += st.st_size;
        }
        if (dent->d_type == DT_DIR && dent->d_name[0] != '.') {
            (*count)++;
            char buf[300] = { 0 };
            sprintf(buf, "%s/%s", pathname, dent->d_name);
            getdircount(buf, count, sizeof_txt);
        }
        dent = readdir(dir);
    }
}

int main(int argc, char* argv[]) {
    int num = 0;
    int sizeof_txt = 0;
    getdircount("./", &num, &sizeof_txt);
    printf("count of dir is: %d\n", num);
    printf("size  of all 1.txt is: %d\n", sizeof_txt);
    return 0;
}


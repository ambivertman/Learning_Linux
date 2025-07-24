#include "header.h"

typedef struct {
    char id[6];
    char name[5];
    int score;
}Student;


int main(int argc, char* argv[]) {
    Student student[3] = { 0 };
    char* name[3] = { "zs","ls","wu" };
    for (int i = 0; i < 3; i++) {
        sprintf(student[i].id, "%d", 10000 + i);
        strcpy(student[i].name, name[i]);
        student[i].score = 90 + i;
    }

    int fd = open("./student_info.txt", O_RDWR | O_CREAT, 0666);
    write(fd, student, sizeof(student));
    close(fd);

    fd = open("./student_info.txt", O_RDWR);
    Student student2[3] = { 0 };
    read(fd, student2, sizeof(student2));
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i);
        printf("id: %s\n", student2[i].id);
        printf("name: %s\n", student2[i].name);
        printf("score: %d\n", student2[i].score);
    }
    close(fd);

    return 0;
}

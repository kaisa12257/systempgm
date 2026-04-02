#include <stdio.h>
#include "student.h"

int main(int argc, char* argv[])
{
    struct student rec;
    FILE *fp;

    if (argc != 2) {
        fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "w");
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    while (scanf("%d %s %d", &rec.id, rec.name, &rec.score) == 3) {
        fprintf(fp, "%d %s %d\n", rec.id, rec.name, rec.score);
    }

    fclose(fp);
    return 0;
}
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    DIR *dp;
    char *dir;
    struct dirent *d;
    struct stat st;
    char path[BUFSIZ + 1];

    if (argc == 1) dir = ".";
    else dir = argv[1];

    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    // 헤더 출력 (보기 좋게 정렬)
    printf("%-20s %-12s %-10s\n", "파일명", "i-node 번호", "크기(bytes)");
    printf("----------------------------------------------------------\n");

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0) {
            perror(path);
            continue;
        }
        // d_name(이름), d_ino(i-node), st_size(파일크기) 출력
        printf("%-20s %-12lu %-10ld\n", d->d_name, d->d_ino, st.st_size);
    }

    closedir(dp);
    exit(0);
}

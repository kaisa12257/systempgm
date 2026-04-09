#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    int fd;

    // 명령행 인자로 받은 파일을 읽기/쓰기 모드로 오픈
    if ((fd = open(argv[1], O_RDWR)) == -1) {
        printf("파일 열기 오류\n");
    } else {
        printf("파일 %s 열기 성공 : %d\n", argv[1], fd);
    }

    close(fd);
    exit(0);
}

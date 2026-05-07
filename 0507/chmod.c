#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long strtol();
    int newmode;

    // 인자가 3개 필요함: 프로그램이름, 8진수모드, 파일이름
    if (argc != 3) {
        fprintf(stderr, "사용법: %sh 모드 파일\n", argv[0]);
        exit(1);
    }

    // 8진수 문자열을 숫자로 변환
    newmode = (int) strtol(argv[1], (char **) NULL, 8);

    // chmod 함수로 파일 권한 변경
    if (chmod(argv[2], newmode) == -1) {
        perror(argv[2]);
        exit(1);
    }

    printf("%s 파일의 권한을 %s로 변경했습니다.\n", argv[2], argv[1]);
    exit(0);
}

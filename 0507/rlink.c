#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buffer[1024];
    int nread;

    // 인자가 하나 필요함 (확인할 링크 파일 이름)
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <링크파일명>\n", argv[0]);
        exit(1);
    }

    // readlink: 심볼릭 링크가 가리키는 실제 경로를 읽어옴
    nread = readlink(argv[1], buffer, 1024);

    if (nread > 0) {
        // 읽어온 내용을 화면(표준출력 1번)에 출력
        write(1, buffer, nread);
        printf("\n"); // 보기 좋게 줄바꿈 추가
        exit(0);
    } else {
        fprintf(stderr, "오류 : 해당 링크 없음\n");
        exit(1);
    }
}

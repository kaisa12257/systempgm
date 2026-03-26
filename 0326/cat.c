#include <stdio.h>

/* 텍스트 파일 내용을 표준출력에 출력 */
int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    // 1. 명령줄 인수가 없으면 표준입력(stdin) 사용, 있으면 파일 열기
    if (argc < 2) {
        fp = stdin;
    } else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
            return 1;
        }
    }

    // 2. 파일로부터 문자 읽기 및 출력 루프
    c = getc(fp);
    while (c != EOF) {          // 파일 끝(EOF)이 아니면 반복
        putc(c, stdout);        // 읽은 문자를 표준출력(화면)에 출력
        c = getc(fp);           // 다음 문자 읽기
    }

    // 3. 파일 닫기 및 종료
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

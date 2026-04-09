#include <stdio.h>

// 다른 파일에 있는 함수를 쓰겠다고 미리 선언합니다.
void functionA();
void functionB();

int main() {
    printf("메인 함수 시작!\n");
    functionA();
    functionB();
    printf("메인 함수 종료!\n");
    return 0;
}

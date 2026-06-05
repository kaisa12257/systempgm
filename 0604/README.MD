프로세스 제
-부모 프로세스가 자식 프로세스 생성

fork() 시스템 호출
-부모 프로세스를 똑같이 복제하여 새로운 자식 프로세스를 생성
-자기복제

프로세스 생성
 - fork()는 한 번 호출되면 두 번 리턴한다.
 - 자식 프로세스에게는 0을 리턴하고
 - 부모 프로세스에게는 자식 프로세스 ID를 리턴한다.
 - 부모 프로세스와 자식 프로세스는 병행적으로 각각 실행을 계속한다.

프로세스 생성: fork1.c
#include <stdio.h>
#include <unistd.h>
/* 자식 프로세스를 생성한다. */
int main()
{
int pid;
printf("[%d] 프로세스 시작 \n", getpid());
pid = fork();
printf("[%d] 프로세스 : 리턴값 %d\n", getpid(), pid);
}
6
$ fork1
[15065] 프로세스 시작
[15065] 프로세스 : 반환값 15066
[15066] 프로세스 : 반환값 0

부모 프로세스와 자식 프로세스 구분
- fork() 호출 후에 리턴값이 다르므로 이 리턴값을 이용하여
- 부모 프로세스와 자식 프로세스를 구별하고 서로 다른 일을 하도록 할 수 있다.

fork2.c
#include <stdlib.h>
#include <stdio.h>
/* 부모 프로세스가 자식 프로세스를 생성하고 서로 다른 메시지를 프린트 */
int main()
{
int pid;
pid = fork();
if (pid ==0) { // 자식 프로세스
printf("[Child] : Hello, world pid=%d\n“, getpid());
}
else { // 부모 프로세스
printf("[Parent] : Hello, world pid=%d\n", getpid());
}
}

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

/* 함수 선언 */
char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ+1];

    /* 인자가 없으면 현재 디렉터리(.), 있으면 해당 디렉터리 사용 */
    if (argc == 1)
        dir = ".";
    else
        dir = argv[1];

    /* 디렉터리 열기 */
    if ((dp = opendir(dir)) == NULL) {
        perror(dir);
        exit(1);
    }

    /* 디렉터리 내의 각 파일에 대해 반복 */
    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name); // 전체 경로 만들기
        if (lstat(path, &st) < 0)               // 파일 상태 정보 가져오기
            perror(path);
        else
            printStat(path, d->d_name, &st);    // 상세 정보 출력
    }

    closedir(dp);
    exit(0);
}

/* 파일 상태 정보를 상세히 출력하는 함수 (이미지 45번) */
void printStat(char *pathname, char *file, struct stat *st)
{
    printf("%5ld ", st->st_blocks);           // 할당된 블록 수
    printf("%c%s ", type(st->st_mode), perm(st->st_mode)); // 타입 및 권한
    printf("%3ld ", st->st_nlink);            // 링크 수
    printf("%s %s ", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name); // 소유자/그룹
    printf("%9ld ", st->st_size);             // 파일 크기(바이트)
    printf("%.12s ", ctime(&st->st_mtime) + 4); // 마지막 수정 시간
    printf("%s\n", file);                     // 파일 이름
}

/* 파일 타입을 문자로 반환하는 함수 (이미지 46번) */
char type(mode_t mode)
{
    if (S_ISREG(mode)) return('-');   // 일반 파일
    if (S_ISDIR(mode)) return('d');   // 디렉터리
    if (S_ISCHR(mode)) return('c');   // 문자 장치 파일
    if (S_ISBLK(mode)) return('b');   // 블록 장치 파일
    if (S_ISLNK(mode)) return('l');   // 심볼릭 링크
    if (S_ISFIFO(mode)) return('p');  // FIFO/파이프
    if (S_ISSOCK(mode)) return('s');  // 소켓
    return('?');
}

/* 파일 접근 권한을 문자열로 반환하는 함수 (이미지 47번) */
char* perm(mode_t mode)
{
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++) {
        if (mode & (S_IRUSR >> i*3)) perms[i*3] = 'r';   // 읽기 권한
        if (mode & (S_IWUSR >> i*3)) perms[i*3+1] = 'w'; // 쓰기 권한
        if (mode & (S_IXUSR >> i*3)) perms[i*3+2] = 'x'; // 실행 권한
    }
    return(perms);
}

# 최종 실행 파일 이름
TARGET = test.out

# 컴파일할 목적 파일(Object files)들
OBJS = A.o B.o main.o

# 컴파일러
CC = gcc

# 1. 최종 타겟 생성 (링크)
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# 2. 각 소스 파일을 목적 파일로 컴파일
A.o: A.c
	$(CC) -c A.c

B.o: B.c
	$(CC) -c B.c

main.o: main.c
	$(CC) -c main.c

# 3. 깔끔하게 정리하는 명령어
clean:
	rm -f $(TARGET) $(OBJS)

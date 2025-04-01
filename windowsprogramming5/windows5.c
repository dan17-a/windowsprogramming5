#include <stdio.h>
#include <windows.h>  // SetConsoleCursorPosition을 사용하기 위해 필요

// gotoxy 함수 정의
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;  // 1부터 시작하는 좌표를 0부터 시작하는 좌표로 변환
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // 커서 이동
}

// 패턴 출력 함수
void printPattern() {
    int width = 15, height = 6;  // 가로 길이와 세로 높이 설정
    int x = 1, y = 1;  // 시작 좌표

    // 첫 번째 구분선 출력 (가로로 "-"로 된 줄)
    gotoxy(x, y); // (x, y)로 커서 이동
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' 두 개를 포함하여 구분선 길이 확장
        printf("-");
    }
    y++;  // 다음 행으로 이동

    // 두 번째 줄은 공백 출력
    gotoxy(x, y); // (x, y)로 커서 이동
    printf("|");
    for (int i = 0; i < width * 2 + 1; i++) {
        printf(" ");
    }
    printf("|");
    y++;  // 다음 행으로 이동

    // 세 번째 줄에 구분선 출력
    gotoxy(x, y); // (x, y)로 커서 이동
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' 두 개를 포함하여 구분선 길이 확장
        printf("-");
    }
    y++;  // 다음 행으로 이동

    // 그 다음 부분은 공백이 있는 행 출력
    for (int i = 0; i < height - 3; i++) {  // 높이에서 구분선 2개를 제외한 중간 부분
        gotoxy(x, y); // (x, y)로 커서 이동
        printf("|");
        for (int j = 0; j < width * 2 + 1; j++) {  // 가로 길이 만큼 공백 출력
            printf(" ");
        }
        printf("|");
        y++;  // 다음 행으로 이동
    }

    // 마지막 구분선 출력 (가로로 "-"로 된 줄)
    gotoxy(x, y); // (x, y)로 커서 이동
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' 두 개를 포함하여 구분선 길이 확장
        printf("-");
    }
}

int main() {
    // 고정된 값으로 패턴 출력
    printPattern();

    return 0;
}

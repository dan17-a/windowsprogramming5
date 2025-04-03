#include <stdio.h>
#include <windows.h>
#include <locale.h>

// 콘솔 커서 이동 함수
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 윈도우 속성 구조체 정의
struct Window {
    int width;
    int height;
    int x;
    int y;
    const char* color;  // 색상
};

// 윈도우 출력 함수
void printWindow(struct Window win) {
    // 내부 색상 설정
    const char* bgColor = (strcmp(win.color, "red") == 0) ? "\033[41m" : "\033[44m";

    // 테두리 색상 흰색
    printf("\033[37m");

    // 내부 색상 적용 및 출력
    for (int i = 0; i < win.height; i++) {
        gotoxy(win.x, win.y + i);
        printf("%s", bgColor);  // 배경 색상 적용
        for (int j = 0; j < win.width; j++) printf(" ");
    }

    // 테두리 다시 씌우기 (흰색)
    printf("\033[37m");
    gotoxy(win.x, win.y); printf("┌");
    for (int i = 0; i < win.width - 2; i++) printf("─");
    printf("┐");

    for (int i = 1; i < win.height - 1; i++) {
        gotoxy(win.x, win.y + i);
        printf("│");
        gotoxy(win.x + win.width - 1, win.y + i);
        printf("│");
    }

    gotoxy(win.x, win.y + win.height - 1);
    printf("└");
    for (int i = 0; i < win.width - 2; i++) printf("─");
    printf("┘");

    // "정다은" 출력 (흰색, 두 번째 줄 중앙)
    gotoxy(win.x + win.width / 2 - 2, win.y + 1);
    printf("\033[37m정다은");

    // **세 번째 줄에 "-------" 추가**
    gotoxy(win.x + 1, win.y + 2);
    for (int i = 0; i < win.width - 2; i++) printf("-");

    // 색상 초기화
    printf("\033[0m");
}

// 콘솔 배경색을 초록색으로 설정
void setConsoleGreenBackground() {
    printf("\033[42m");  // 배경 초록색 설정
    system("cls");       // 화면 클리어
}

int main() {
    // 한글 깨짐 방지
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(65001); // UTF-8 설정

    setConsoleGreenBackground(); // 콘솔 배경 초록색으로 설정

    // 첫 번째 (빨간색) 윈도우
    struct Window redWindow = { 20, 7, 10, 3, "red" };
    printWindow(redWindow);

    // 두 번째 (파란색) 윈도우
    struct Window blueWindow = { 20, 7, 15, 5, "blue" };
    printWindow(blueWindow);

    // **왼쪽 아래 검은 점 완벽 제거**
    gotoxy(1, 30);
    for (int i = 0; i < 80; i++) {  // 콘솔 가로폭(80)만큼 초록색 공백 출력
        printf("\033[42m ");
    }

    // 초록색 배경 유지하면서 종료 메시지 내리기
    for (int i = 0; i < 5; i++) {
        printf("\n");
    }

    // 한 줄 개행 추가로 검은 점 방지
    printf("\n");

    // 색상 초기화
    printf("\033[0m");

    return 0;
}

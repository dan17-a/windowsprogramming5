#include <stdio.h>
#include <string.h>

// 색상 정의
#define RESET "\033[0m"
#define WHITE_TEXT "\033[97m"
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

// ANSI 색상 0~7
const char* bg_colors[8] = {
    "\033[40m", "\033[41m", "\033[42m", "\033[43m",  // 3번: 노란색
    "\033[44m", "\033[45m", "\033[46m", "\033[47m"
};

// 바탕화면 + 작업표시줄
void DrawBG(int width, int height) {
    int topBottomMargin = 1;
    int sideMargin = 2;

    int workWidth = width - sideMargin * 2;
    int workHeight = height - topBottomMargin * 2 - 1;

    for (int i = 0; i < topBottomMargin; i++) printf("\n");

    for (int i = 0; i < workHeight; i++) {
        for (int j = 0; j < sideMargin; j++) printf(" ");
        for (int j = 0; j < workWidth; j++) printf("\033[44m \033[0m");
        for (int j = 0; j < sideMargin; j++) printf(" ");
        printf("\n");
    }

    for (int j = 0; j < sideMargin; j++) printf(" ");
    for (int j = 0; j < workWidth; j++) printf("\033[100m \033[0m");
    for (int j = 0; j < sideMargin; j++) printf(" ");
    printf("\n");
}

// 윈도우창 그리기
void drawConsoleWindow(int startX, int startY, int width, int height, const char* title, int color) {
    if (color < 0 || color > 7) color = 0;

    // 윈도우 외부 테두리 그리기
    for (int y = 0; y < height; y++) {
        MOVE_CURSOR(startY + y, startX);
        for (int x = 0; x < width; x++) {
            if (y == 0) {
                if (x == 0) printf("┌");
                else if (x == width - 1) printf("┐");
                else printf("\033[97m─\033[0m");  // 하얀색 '-' 표시
            }
            else if (y == height - 1) {
                if (x == 0) printf("└");
                else if (x == width - 1) printf("┘");
                else printf("\033[97m─\033[0m");  // 하얀색 '-' 표시
            }
            else {
                if (x == 0 || x == width - 1)
                    printf("\033[%dm│\033[0m", color);  // 배경 색상에 맞춰서 세로 테두리
                else
                    printf(" ");
            }
        }
    }

    // 타이틀을 윈도우의 첫 번째 줄에 넣기
    MOVE_CURSOR(startY + 1, startX + 2);  // 첫 번째 줄의 2번째 칸부터 시작
    printf(" %s ", title);

    // X 버튼 (우측 3칸 전)
    MOVE_CURSOR(startY, startX + width - 4);
    printf("\033[41m\033[97m X \033[0m");
}

// 메인 함수
int main() {
    int screenWidth = 80;
    int screenHeight = 25;

    DrawBG(screenWidth, screenHeight);

    int winWidth = 40;
    int winHeight = 10;
    int winX = (screenWidth - winWidth) / 2;
    int winY = (screenHeight - winHeight) / 2;

    drawConsoleWindow(winX, winY, winWidth, winHeight, "나의 멋진 윈도우", 3); // 노란색 배경

    // ↓ 커서를 작업표시줄 아래로 이동시킴
    MOVE_CURSOR(27, 1);
    printf(RESET); // 색상 리셋도 한 번 해주고

    return 0;
}

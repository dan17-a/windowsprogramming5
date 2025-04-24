#include <stdio.h>
#include <string.h>

// ���� ����
#define RESET "\033[0m"
#define WHITE_TEXT "\033[97m"
#define MOVE_CURSOR(row, col) printf("\033[%d;%dH", (row), (col))

// ANSI ���� 0~7
const char* bg_colors[8] = {
    "\033[40m", "\033[41m", "\033[42m", "\033[43m",  // 3��: �����
    "\033[44m", "\033[45m", "\033[46m", "\033[47m"
};

// ����ȭ�� + �۾�ǥ����
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

// ������â �׸���
void drawConsoleWindow(int startX, int startY, int width, int height, const char* title, int color) {
    if (color < 0 || color > 7) color = 0;

    // ������ �ܺ� �׵θ� �׸���
    for (int y = 0; y < height; y++) {
        MOVE_CURSOR(startY + y, startX);
        for (int x = 0; x < width; x++) {
            if (y == 0) {
                if (x == 0) printf("��");
                else if (x == width - 1) printf("��");
                else printf("\033[97m��\033[0m");  // �Ͼ�� '-' ǥ��
            }
            else if (y == height - 1) {
                if (x == 0) printf("��");
                else if (x == width - 1) printf("��");
                else printf("\033[97m��\033[0m");  // �Ͼ�� '-' ǥ��
            }
            else {
                if (x == 0 || x == width - 1)
                    printf("\033[%dm��\033[0m", color);  // ��� ���� ���缭 ���� �׵θ�
                else
                    printf(" ");
            }
        }
    }

    // Ÿ��Ʋ�� �������� ù ��° �ٿ� �ֱ�
    MOVE_CURSOR(startY + 1, startX + 2);  // ù ��° ���� 2��° ĭ���� ����
    printf(" %s ", title);

    // X ��ư (���� 3ĭ ��)
    MOVE_CURSOR(startY, startX + width - 4);
    printf("\033[41m\033[97m X \033[0m");
}

// ���� �Լ�
int main() {
    int screenWidth = 80;
    int screenHeight = 25;

    DrawBG(screenWidth, screenHeight);

    int winWidth = 40;
    int winHeight = 10;
    int winX = (screenWidth - winWidth) / 2;
    int winY = (screenHeight - winHeight) / 2;

    drawConsoleWindow(winX, winY, winWidth, winHeight, "���� ���� ������", 3); // ����� ���

    // �� Ŀ���� �۾�ǥ���� �Ʒ��� �̵���Ŵ
    MOVE_CURSOR(27, 1);
    printf(RESET); // ���� ���µ� �� �� ���ְ�

    return 0;
}

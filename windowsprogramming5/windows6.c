#include <stdio.h>
#include <windows.h>
#include <locale.h>

// �ܼ� Ŀ�� �̵� �Լ�
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ������ �Ӽ� ����ü ����
struct Window {
    int width;
    int height;
    int x;
    int y;
    const char* color;  // ����
};

// ������ ��� �Լ�
void printWindow(struct Window win) {
    // ���� ���� ����
    const char* bgColor = (strcmp(win.color, "red") == 0) ? "\033[41m" : "\033[44m";

    // �׵θ� ���� ���
    printf("\033[37m");

    // ���� ���� ���� �� ���
    for (int i = 0; i < win.height; i++) {
        gotoxy(win.x, win.y + i);
        printf("%s", bgColor);  // ��� ���� ����
        for (int j = 0; j < win.width; j++) printf(" ");
    }

    // �׵θ� �ٽ� ����� (���)
    printf("\033[37m");
    gotoxy(win.x, win.y); printf("��");
    for (int i = 0; i < win.width - 2; i++) printf("��");
    printf("��");

    for (int i = 1; i < win.height - 1; i++) {
        gotoxy(win.x, win.y + i);
        printf("��");
        gotoxy(win.x + win.width - 1, win.y + i);
        printf("��");
    }

    gotoxy(win.x, win.y + win.height - 1);
    printf("��");
    for (int i = 0; i < win.width - 2; i++) printf("��");
    printf("��");

    // "������" ��� (���, �� ��° �� �߾�)
    gotoxy(win.x + win.width / 2 - 2, win.y + 1);
    printf("\033[37m������");

    // **�� ��° �ٿ� "-------" �߰�**
    gotoxy(win.x + 1, win.y + 2);
    for (int i = 0; i < win.width - 2; i++) printf("-");

    // ���� �ʱ�ȭ
    printf("\033[0m");
}

// �ܼ� ������ �ʷϻ����� ����
void setConsoleGreenBackground() {
    printf("\033[42m");  // ��� �ʷϻ� ����
    system("cls");       // ȭ�� Ŭ����
}

int main() {
    // �ѱ� ���� ����
    setlocale(LC_ALL, "");
    SetConsoleOutputCP(65001); // UTF-8 ����

    setConsoleGreenBackground(); // �ܼ� ��� �ʷϻ����� ����

    // ù ��° (������) ������
    struct Window redWindow = { 20, 7, 10, 3, "red" };
    printWindow(redWindow);

    // �� ��° (�Ķ���) ������
    struct Window blueWindow = { 20, 7, 15, 5, "blue" };
    printWindow(blueWindow);

    // **���� �Ʒ� ���� �� �Ϻ� ����**
    gotoxy(1, 30);
    for (int i = 0; i < 80; i++) {  // �ܼ� ������(80)��ŭ �ʷϻ� ���� ���
        printf("\033[42m ");
    }

    // �ʷϻ� ��� �����ϸ鼭 ���� �޽��� ������
    for (int i = 0; i < 5; i++) {
        printf("\n");
    }

    // �� �� ���� �߰��� ���� �� ����
    printf("\n");

    // ���� �ʱ�ȭ
    printf("\033[0m");

    return 0;
}

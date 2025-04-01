#include <stdio.h>
#include <windows.h>  // SetConsoleCursorPosition�� ����ϱ� ���� �ʿ�

// gotoxy �Լ� ����
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;  // 1���� �����ϴ� ��ǥ�� 0���� �����ϴ� ��ǥ�� ��ȯ
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // Ŀ�� �̵�
}

// ���� ��� �Լ�
void printPattern() {
    int width = 15, height = 6;  // ���� ���̿� ���� ���� ����
    int x = 1, y = 1;  // ���� ��ǥ

    // ù ��° ���м� ��� (���η� "-"�� �� ��)
    gotoxy(x, y); // (x, y)�� Ŀ�� �̵�
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' �� ���� �����Ͽ� ���м� ���� Ȯ��
        printf("-");
    }
    y++;  // ���� ������ �̵�

    // �� ��° ���� ���� ���
    gotoxy(x, y); // (x, y)�� Ŀ�� �̵�
    printf("|");
    for (int i = 0; i < width * 2 + 1; i++) {
        printf(" ");
    }
    printf("|");
    y++;  // ���� ������ �̵�

    // �� ��° �ٿ� ���м� ���
    gotoxy(x, y); // (x, y)�� Ŀ�� �̵�
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' �� ���� �����Ͽ� ���м� ���� Ȯ��
        printf("-");
    }
    y++;  // ���� ������ �̵�

    // �� ���� �κ��� ������ �ִ� �� ���
    for (int i = 0; i < height - 3; i++) {  // ���̿��� ���м� 2���� ������ �߰� �κ�
        gotoxy(x, y); // (x, y)�� Ŀ�� �̵�
        printf("|");
        for (int j = 0; j < width * 2 + 1; j++) {  // ���� ���� ��ŭ ���� ���
            printf(" ");
        }
        printf("|");
        y++;  // ���� ������ �̵�
    }

    // ������ ���м� ��� (���η� "-"�� �� ��)
    gotoxy(x, y); // (x, y)�� Ŀ�� �̵�
    for (int i = 0; i < width * 2 + 3; i++) {  // '|' �� ���� �����Ͽ� ���м� ���� Ȯ��
        printf("-");
    }
}

int main() {
    // ������ ������ ���� ���
    printPattern();

    return 0;
}

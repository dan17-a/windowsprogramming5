#include <stdio.h>

// PassOrFail �Լ�: 50�� �̻��̸� 1 ��ȯ, �ƴϸ� 0 ��ȯ
int PassOrFail(int score) {
    if (score >= 50) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int score;

    printf("���� ��� ������ �Է��ϼ���: ");
    scanf_s("%d", &score);

    if (PassOrFail(score)) {
        printf("����� �����ϴ�!\n");
    }
    else {
        printf("�츮�� ���ߴ١�  ������̴١�\n");
    }

    return 0;
}



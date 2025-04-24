#include <stdio.h>

// PassOrFail 함수: 50점 이상이면 1 반환, 아니면 0 반환
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

    printf("예상 평균 점수를 입력하세요: ");
    scanf_s("%d", &score);

    if (PassOrFail(score)) {
        printf("재시험 없습니다!\n");
    }
    else {
        printf("우리는 망했다…  재시험이다…\n");
    }

    return 0;
}



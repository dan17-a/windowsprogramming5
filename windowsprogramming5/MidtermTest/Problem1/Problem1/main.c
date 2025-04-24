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
    scanf("%d", &score);

    if (PassOrFail(score)) {
        printf("재시험 없습니다!\n");          // ✅ 1일 때 출력
    }
    else {
        printf("우리는 망했다…  재시험이다…\n"); // ✅ 0일 때 출력
    }

    return 0;
}
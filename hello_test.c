#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 강화 성공 확률 (예: 70%)
#define SUCCESS_RATE 70

// 강화 실패 시 아이템 파괴 확률 (예: 10%)
#define DESTROY_RATE 10

// 강화에 성공한 경우 상승하는 레벨
#define SUCCESS_LEVEL_UP 1

// 강화에 실패한 경우 감소하는 레벨
#define FAIL_LEVEL_DOWN 1

// 최대 아이템 레벨
#define MAX_LEVEL 20

// 강화 시뮬레이션 함수
void enhanceItem(int *level) {
    // 강화 성공 여부를 랜덤으로 결정
    int success = rand() % 100 < SUCCESS_RATE;

    if (success) {
        // 강화에 성공한 경우
        printf("강화에 성공했습니다!\n");
        (*level) += SUCCESS_LEVEL_UP;
        if (*level > MAX_LEVEL)
            *level = MAX_LEVEL;
    } else {
        // 강화에 실패한 경우
        printf("강화에 실패했습니다...\n");
        // 아이템 파괴 여부를 랜덤으로 결정
        if (rand() % 100 < DESTROY_RATE) {
            printf("아이템이 파괴되었습니다!\n");
            *level = 0; // 아이템 레벨 초기화
        } else {
            (*level) -= FAIL_LEVEL_DOWN;
            if (*level < 0)
                *level = 0;
        }
    }
}

int main() {
    srand(time(NULL)); // 랜덤 시드 초기화

    int itemLevel = 0; // 초기 아이템 레벨

    printf("시작 아이템 레벨: %d\n", itemLevel);

    char enhanceInput;
    do {
        printf("강화를 시도하시겠습니까? (y/n): ");
        scanf(" %c", &enhanceInput);

        if (enhanceInput == 'y' || enhanceInput == 'Y') {
            enhanceItem(&itemLevel);
            printf("현재 아이템 레벨: %d\n", itemLevel);
        }
    } while (enhanceInput == 'y' || enhanceInput == 'Y');

    printf("프로그램을 종료합니다.\n");

    return 0;
}
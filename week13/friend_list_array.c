#include <stdio.h>

#define MAX_FRIENDS 5

typedef char NAME_TYPE[21];
typedef unsigned short int us;

int AddFriend(NAME_TYPE* p_name, us* p_age, float* p_height, float* p_weight, int count)
{
	if (count < MAX_FRIENDS) {
		printf("\n새로운 친구의 정보를 입력하세요.\n");
		printf("1. 이름: >>> ");
		scanf_s("%s", *(p_name + count), sizeof(*(p_name + count)));

		printf("2. 나이: >>> ");
		scanf_s("%hu", p_age + count);

		printf("키: >>> ");
		scanf_s("%f", p_height + count);

		printf("몸무게: >>> ");
		scanf_s("%f", p_weight + count);

		printf("\n입력 완료.\n");

		return 1;
	}
	else {
		printf("최대 인원을 초과하여 입력을 할 수 없다!\n");
		printf("최대 %d명까지만 관리 가능합니다.", MAX_FRIENDS);
		return 0;
	}

}

void ShowFriendList(NAME_TYPE* p_name, us* p_age, float* p_height, float* p_weight, int count) {
	if (count > 0) {
		printf("\n등록된 친구 목록\n");
		printf("======================================================\n");
		for (int i = 0; i < count; i++) {
			printf("%21s, %3hu, %6.2f, %6.2f\n",
				*(p_name + i),
				*(p_age + i),
				*(p_height + i),
				*(p_weight + i));
			printf("======================================================\n");
		}
	}
	else {
		printf("\n 등록된 친구가 없다!\n\n");


	}
}









int main() {
	NAME_TYPE name[MAX_FRIENDS];
	us age[MAX_FRIENDS];
	float height[MAX_FRIENDS];
	float weight[MAX_FRIENDS];
	int count = 0; int menu_num = 0;

	while (1) {
		printf("\t[ 메인 메뉴 ]\n");
		printf("===================\n");
		printf("1. 친구 추가\n");
		printf("2.친구 목록 보기\n");
		printf("3.종료\n");
		printf("===================\n");
		printf("번호 선택 : >>> ");
		scanf_s("%d", &menu_num);
		if (menu_num == 3) break;

		switch (menu_num) {
		case 1:
			if (AddFriend(name, age, height, weight, count)) {
				count++;
			}
			break;
		case 2:
			ShowFriendList(name, age, height, weight, count);
			break;

		default:
			printf("1~3번호만 선택 가능");
		}



	}


	return 0;
}





#include <stdio.h>


/* 구조체 이름. 멤버 이름 */
typedef struct{
	int HP;
	int MP;
	double EXP;
	double speed;
	double power;
	double mental;
	char ChararterName;
} GamePlayer; // 구조체변수 
			  // 어떻게 연산자를 통해 멤버들을 참조할 수 있을까요?
			  // 구조체의 이름은 곧 상수 포인터입니다.  멤버의 이름도 상수 포인터

int main()
{
	int* numPtr1; //단일포인터
	int** numPtr2; //이중포인터
	int num1 = 10;

	numPtr1 = &num1; // num1의 메모리 주소 저장

	numPtr2 = &numPtr1; //numPtr1의 메모리 주소 저장

	printf("%d\n", **numPtr2); // 20: 포인터를 두 번 역참조하여 num1의 메모리 주소에 접근
	printf("\n\n");


	/* */
	GamePlayer* ptr1;
	GamePlayer GamePlayer;
	ptr1 = &GamePlayer;

	//(char)(ptr1->ChararterName, "스카웃");
	ptr1->HP = 5000;
	ptr1->MP = 3000;
	ptr1->EXP = 0;


	printf("캐릭터 이름 : %c\n", ptr1->ChararterName);
	printf("HP: %d\tMP : %d\n", ptr1->HP, ptr1->MP);
	printf("%d\n", ptr1);
	
	


	return 0;

}
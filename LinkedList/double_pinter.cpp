#include <stdio.h>


/* ����ü �̸�. ��� �̸� */
typedef struct{
	int HP;
	int MP;
	double EXP;
	double speed;
	double power;
	double mental;
	char ChararterName;
} GamePlayer; // ����ü���� 
			  // ��� �����ڸ� ���� ������� ������ �� �������?
			  // ����ü�� �̸��� �� ��� �������Դϴ�.  ����� �̸��� ��� ������

int main()
{
	int* numPtr1; //����������
	int** numPtr2; //����������
	int num1 = 10;

	numPtr1 = &num1; // num1�� �޸� �ּ� ����

	numPtr2 = &numPtr1; //numPtr1�� �޸� �ּ� ����

	printf("%d\n", **numPtr2); // 20: �����͸� �� �� �������Ͽ� num1�� �޸� �ּҿ� ����
	printf("\n\n");


	/* */
	GamePlayer* ptr1;
	GamePlayer GamePlayer;
	ptr1 = &GamePlayer;

	//(char)(ptr1->ChararterName, "��ī��");
	ptr1->HP = 5000;
	ptr1->MP = 3000;
	ptr1->EXP = 0;


	printf("ĳ���� �̸� : %c\n", ptr1->ChararterName);
	printf("HP: %d\tMP : %d\n", ptr1->HP, ptr1->MP);
	printf("%d\n", ptr1);
	
	


	return 0;

}
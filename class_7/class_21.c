// ���ڿ� ����� ������ ����� ���� 522p ���� 1
#include <stdio.h>
#include <string.h>
typedef struct person {
	char name[20];
	char num[50];
	char phone[50];
	char food[50];
	char hobby[50];
}Person;

int main() {
	FILE* src = fopen("mystory.txt", "wt");
	Person person;
	
	fgets(person.name, 20, stdin);
	fgets(person.num, 50, stdin);
	fgets(person.phone, 50, stdin);
	// person.phone[strcspn(person.phone, "\n")] = '\0';
	// fgets �� �Է� �Ϸ�
	// ������ �޴��� �Է¸� �޴��� ���ڿ�(fgets �� �о����Ƿ�) �� ������ ����
	// ���๮�ڸ� ã�� �ι��ڷ� ��ü�Ѵ�. (���� 2�� ���� ����)
	
	// src ���� ������ �ּ� �� ���Ͽ� ���� �Է��� �̸�, �ֹι�ȣ, ��ȭ��ȣ��
	// ���Ͽ� �ۼ��Ѵ�.
	fputs(person.name, src);
	fputs(person.num, src);
	fputs(person.phone, src);

	fclose(src);

	// ���� 2. ������ �߰� 
	fopen_s(src, "mystory.txt", "a");
	fgets(person.food, 50, stdin);
	fgets(person.hobby, 50, stdin);
	person.hobby[strcspn(person.hobby, "\n")] = '\0';

	fputs(person.food, src);
	fputs(person.hobby, src);

	fclose(src);

	return 0;
}
// fgets �� �ƴ� scanf �� �̿����� �� ���� �ɹ��� #�� ���� �ְ�
// scanf �� ����� ù��° �ּҷ� �޴´�.
/*
#include <stdio.h>

typedef struct {
  char name[9];
  char jumin[16];
  char phoneno[15];
} Person;

int main(void)
{
  Person me;
  FILE *fp;

  printf("������ �Է��ϼ���.\n");
  me.name[0] = '#'; me.jumin[0] = '#'; me.phoneno[0] = '#';
  printf("�̸� : "), scanf("%s", &(me.name[1]));
  printf("�ֹε�Ϲ�ȣ : "), scanf("%s", &(me.jumin[1]));
  printf("��ȭ��ȣ : "), scanf("%s", &(me.phoneno[1]));

  fp = fopen("mystory.txt", "wt");
  fwrite(&me, sizeof(Person), 1, fp);
  fclose(fp);

  return 0;
}
*/
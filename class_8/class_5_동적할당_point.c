// �������� �Ǵ� ���������� �ذ��� ���� �ʴ� ���
#include <stdio.h>
#include <stdlib.h> // �����Ҵ� ������� �߰�
char name3[30];
// case 1. �Լ����� ���������� �Է¹ް� ��ȯ (stack)
char* ReadUserName() {
	char name[30]; // �Է��� �޴� ���ڿ��� ���������� ����Ǿ���
	printf("whats your name? ");
	gets(name); // �Է��� ���� �� �� ����������
	return name; // �޸𸮿����� �Ҹ�Ǳ� ������ main �Լ������� ������ ���� ����Ѵ�.
}
// case 2. �Լ����� ���������� �Է¹ް� ��ȯ (data)
char* ReadUserName2() {
	printf("name : ");
	gets(name3);
	return name3;
}
// case 3. �Լ����� �����Ҵ� ������ �Է¹ް� ��ȯ ( heap ! )
// => ���ڿ��� ��ȯ�ϴ� �Լ��� �����ϴ� ���� �ذ�
char* MallocUserName() {
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("malloc name : ");
	gets(name);
	return name;
}

int main() {
	char* name1;
	char* name2;
	// case 1. �Լ� �� ���� �Է¹޴� �������� ���ڿ��� �������� ��� (stack)
	name1 = ReadUserName();
	printf("name1: %s\n", name1); // ������ �� ���
	name2 = ReadUserName();
	printf("name2: %s\n", name2); // ������ �� ���
	
	// case 2. �������� ��� (�ϴ� �ذ��� �ǳ� main �Լ��� �ٸ� �������� (data)
	// �����Ѵٸ� ������ name3 �� name4 �� ���� ���� �ȴ�.
	char* name3; 
	char* name4; 
	name3 = ReadUserName2();
	printf("name3: %s\n", name3); // ���� 
	name4 = ReadUserName2();
	printf("name4: %s\n", name4); // ����

	printf("name3: %s\n", name3); // name4 �� ������ ������ ��µ�

	// case 3. �Լ� �� �Է¹޴� ���ڿ��� malloc �����Ҵ����� �ѱ� �������� ��� (heap)
	// �����Ҵ� ������ heap ������ ����ȴ�.
	// heap ������ ��� free �� �������� ������ ���α׷� ���� �Ŀ��� �޸𸮿� ���� �ȴ�.
	// �����쳪 os �� �޸� �ڵ� ����ȭ ���� ������ ������ ���� ���� �����ϴ� ���� ����.
	char* name5;
	char* name6;
	name5 = MallocUserName();
	printf("name5: %s\n", name5); //  ����
	name6 = MallocUserName();
	printf("name6: %s\n", name6); // ����

	printf("name5, name6: %s %s\n", name5, name6); // ����

	return 0;
}

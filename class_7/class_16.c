// ������ enum �� ���ǿ� �ǹ�
#include <stdio.h>
typedef enum syllable { // typedef ������ �߰��� �������� ����
	Do = 1, Re = 2, Mi = 3, Fa = 4, So = 5, La = 6, Ti = 7
} Syllable;

void Sound(Syllable sy) {
	switch (sy)
	{
	case Do:
		puts("���� �Ͼ� ������"); return;
	case Re:
		puts("���� �ձ� ���ڵ�"); return;
	case Mi:
		puts("�̴� �Ķ� �̳���"); return;
	case Fa:
		puts("�Ĵ� ���� �Ķ���"); return;
	case So:
		puts("���� ���� �ֹ��"); return;
	case La:
		puts("��� �������"); return;
	case Ti:
		puts("�ô� ���� �ó���"); return;
	default:
		break;
	}
	puts("�� �Բ� �θ���~ �������� �ֶ�õ� �� ��~ §~");
}

int main() {
	Syllable tone;
	for (tone = Do;tone <= Ti;tone += 1) { // Do, Ti �� ����̹Ƿ� 1�� 7�� ����
		// �� ������ enum �� ������ �� ����� ���� ������ ������
		// ex 1. Do, Re. Mi, ... �� �� 0 ���� �����ؼ� 1�� ������ ������ �����ȴ�.
		// ex 2. Do, Re, Mi=6, Fa, ... �� �� 0 1 6 7 ��, ������ �� ������ 0 ����, ���� ��
		// �� ���ǵ� ������ 1�� ������ ������ �����ȴ�.
		Sound(tone);
	}

	return 0;
}
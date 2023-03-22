#include <stdio.h>
#include <Windows.h>
#define MAX_TERMS 100

// ���� 2 ����ü
struct {
	float coef;
	int expon;
} terms[MAX_TERMS] = { {7,6}, {5,3}, {9,2}, {1,0}, {5,3}, {2,2}, {1,1}, {10,0} };
int avail = 8;

// ���׽� ����
Poly_multi(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	*Cs = avail;

	while (As <= Ae && Bs <= Be) {
		for (int i = Bs; Bs <= Be; i++) {
			terms[*Cs].coef = (terms[As].coef) * (terms[Bs].coef); // ��� ���ϱ�
			terms[*Cs].expon = (terms[As].expon) + (terms[Bs++].expon); // ���� ���ϱ�
			*Cs = *Cs + 1;
		}
		Bs = Ae + 1; // B ������ �ʱ�ȭ
		As++; // ���� �� ���ϱ�
	}
	return 0;
}

// ���� ����ü
struct {
	float an_coef;
	int an_expon;
} answer[MAX_TERMS];

// ���׽� ������ �� ���ϱ�
Poly_add(int Ae, int Be, int* Cs, int* Ce)
{
	*Cs = avail;
	*Ce = *Cs + (Ae + 1) * (Be - Ae);

	while (*Cs <= *Ce) {
		if (terms[*Cs].expon == 0) {
			answer[0].an_coef += terms[*Cs].coef;
			answer[0].an_expon = 0;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 1) {
			answer[1].an_coef += terms[*Cs].coef;
			answer[1].an_expon = 1;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 2) {
			answer[2].an_coef += terms[*Cs].coef;
			answer[2].an_expon = 2;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 3) {
			answer[3].an_coef += terms[*Cs].coef;
			answer[3].an_expon = 3;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 4) {
			answer[4].an_coef += terms[*Cs].coef;
			answer[4].an_expon = 4;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 5) {
			answer[5].an_coef += terms[*Cs].coef;
			answer[5].an_expon = 5;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 6) {
			answer[6].an_coef += terms[*Cs].coef;
			answer[6].an_expon = 6;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 7) {
			answer[7].an_coef += terms[*Cs].coef;
			answer[7].an_expon = 7;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 8) {
			answer[8].an_coef += terms[*Cs].coef;
			answer[8].an_expon = 8;
			*Cs = *Cs + 1;
		}
		else if (terms[*Cs].expon == 9) {
			answer[9].an_coef += terms[*Cs].coef;
			answer[9].an_expon = 9;
			*Cs = *Cs + 1;
		}
	}
	return 0;
}

// ���׽� ���
void print_poly(int s, int e) // s = ������, e = ������ 
{
	for (int i = s; i < e; i++)
		printf("%3.1f x^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1f x^%d\n", terms[e].coef, terms[e].expon);
}

int main(void)
{
	// ���� 2 ���
	int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
	Poly_multi(As, Ae, Bs, Be, &Cs, &Ce);
	Poly_add(Ae, Be, &Cs, &Ce);

	printf("  ");
	print_poly(As, Ae);
	printf(" *");
	print_poly(Bs, Be);
	printf("-----------------------------------\n");

	// ���� 2 �� ���
	for (int num = 9; num > 0; num--)
		printf("%3.1f x^%d + ", answer[num].an_coef, answer[num].an_expon);
	printf("%3.1f x^%d\n", answer[0].an_coef, answer[0].an_expon);

	system("pause");
	return 0;
}
/*
�� 4���� �Է¹ް� 2���� ������ ���ϰ� ���������� ���踦 ���ϴ� ���α׷�
�߰���� ������ó�� plot�Ѵ�.
*/
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

void line(float *a, float *b, float *c, int x1, int y1, int x2, int y2);	
//line�� ���� ���ϰ� ����ϴ� �Լ�
void determine(float a1, float b1, float c1, float a2, float b2, float c2);	
//line�� ���踦 ���ϰ� ����ϴ� �Լ�
float calang(float a1, float b1, float c1, float a2, float b2, float c2);	
//line ������ ���� ����ϴ� �Լ�
void plot(float a1, float b1, float c1, float a2, float b2, float c2);		
//���� ��ó�� ������ plot�ϴ� �Լ�

int main() {
	int x1, y1;					//P1 ��ǥ
	int x2, y2;					//P2 ��ǥ
	int x3, y3;					//P3 ��ǥ
	int x4, y4;					//P4 ��ǥ

	float a1, b1;				//L1�� a, b
	float a2, b2;				//L2�� a, b
	float c1, c2;				//x�� ���

	while (1) {		//P1�� P2�� �ٸ����� ���������� �Է�
		printf("Enter the value x and y of P1: ");
		scanf("%d%d", &x1, &y1);
		printf("Enter the value x and y of P2: ");
		scanf("%d%d", &x2, &y2);
		if ((x1==x2)&&(y1==y2)) {
			printf("P1 and P2 are same point! Enter the value again.\n");
		}
		else {
			break;
		}
	}
	
	while (1) {		//P3�� P4�� �ٸ����� ���������� �Է�
		printf("Enter the value x and y of P3: ");
		scanf("%d%d", &x3, &y3);
		printf("Enter the value x and y of P4: ");
		scanf("%d%d", &x4, &y4);
		if ((x3==x4)&&(y3==y4)) {
			printf("P3 and P4 are same point! Enter the value again.\n");
		}
		else {
			break;
		}
	}

	printf("\n");

	printf("L1 : ");
	line(&a1, &b1, &c1, x1, y1, x2, y2);	//L1 ����� ���
	printf("L2 : ");
	line(&a2, &b2, &c2, x3, y3, x4, y4);	//L2 ����� ���
	determine(a1, b1, c1, a2, b2, c2);	//L1�� L2�� ���豸���� ���
	plot(a1,b1,c1,a2,b2,c2);			
}
void line(float *a, float *b, float *c, int x1, int y1, int x2, int y2) {
	if (y1==y2) {		//x�� ����� 0�϶�
		*a=1;
		*b=-y1;
		*c=0;
		printf("0x + %.2fy + %.2f = 0\n", *a, *b);
	}
	else {
		*a=-((float)x1-(float)x2)/((float)y1-(float)y2);
		*b=-(float)x1+((float)x1-(float)x2)/((float)y1-(float)y2)*(float)y1;
		*c=1;
		printf("x + %.2fy + %.2f = 0\n", *a, *b);
	}
}
void determine(float a1, float b1, float c1, float a2, float b2, float c2) {
	float x, y;			//�������� ��ǥ
	float ang;			//�� ������ ����

	if ((c1==c2)&&(a1==a2)) {	//���Ⱑ ���� ��
		if(b1!=b2) {		//������ ��
			printf("L1 and L2 are Parallel.\n");
		}
		else {			//������ ��
			printf("L1 and L2 are Coincident.\n");
		}
	}
	else {				//���Ⱑ �ٸ���
		if (c1==0) {
			y=-b1;
			x=-a2*y-b2;			
		}
		else if (c2==0) {
			y=-b2;
			x=-a1*y-b1;
		}
		else {
			y=-(b1-b2)/(a1-a2);
			x=-a1*y-b1;
		}

		ang=calang(a1, b1, c1, a2, b2, c2);
		
		if (ang==90) {
			printf("L1 and L2 are perpendicular.\n");
			printf("Intersection Point P(x, y) : %.2f %.2f\n", x, y);
		}
		else {
			printf("L1 and L2 are intersect.\n");
			printf("Intersection Point P(x, y) : %.2f %.2f\n", x, y);
			printf("Degree : %.2f\n", ang);
		}
	}
}

float calang(float a1, float b1, float c1, float a2, float b2, float c2) {
	
	float ang1, ang2;		//�� ������ x��� �̷�� ����
	float ang;			//�� ������ ����

	if(a1==0) {			//a=0�̸� 90��(PI/2) (x��� ������)
		ang1=PI/2;
	}
	else {				//����� x����� ���� tan��
		ang1=atan(-c1/a1);
	}
	if(a2==0) {
		ang2=PI/2;
	}
	else {
		ang2=atan(-c2/a2);
	}

	ang=ang1-ang2;		//�� ������ ������ ������ ������ ����

	if (ang<0) {		//�����̹Ƿ� ���밪�� ���Ѵ�
		ang=-ang;
	}
	if (ang>PI/2) {		//�������� �ٲ۴�
		ang=PI-ang;
	}

	return ang*180/PI;	//rad�� degree�� ��ȯ
}
void plot(float a1, float b1, float c1, float a2, float b2, float c2) {	
//���� ��ó�� ������ plot�ϴ� �Լ�
	int x;
	int y;
	
	for(y=10; y>=-10; y=y-1) {		
		for(x=-10; x<=10; x=x+1) {
			if ((c1*x+a1*y+b1==0)&&(c2*x+a2*y+b2)==0) {
			//������
				printf(" 0");
			}
			else if ((c1*x+a1*y+b1==0)||(c2*x+a2*y+b2==0)) {
			//�������� ��
				printf(" *");
			}
			else if ((x==0)&&(y==0)) {	//����
				printf(" +");
			}
			else if (x==0) {	//y��
				printf(" |");
			}
			else if (y==0) {	//x��
				printf(" -");
			}
			else {			//�����
				printf("  ");
			}
		}
		printf("\n");
	}
}

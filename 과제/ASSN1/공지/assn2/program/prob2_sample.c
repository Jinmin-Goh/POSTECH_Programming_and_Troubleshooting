/*
점 4개를 입력받고 2개의 직선을 구하고 직선끼리의 관계를 구하는 프로그램
추가기능 원점근처를 plot한다.
*/
#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

void line(float *a, float *b, float *c, int x1, int y1, int x2, int y2);	
//line의 식을 구하고 출력하는 함수
void determine(float a1, float b1, float c1, float a2, float b2, float c2);	
//line의 관계를 구하고 출력하는 함수
float calang(float a1, float b1, float c1, float a2, float b2, float c2);	
//line 사이의 각을 계산하는 함수
void plot(float a1, float b1, float c1, float a2, float b2, float c2);		
//원점 근처의 영역을 plot하는 함수

int main() {
	int x1, y1;					//P1 좌표
	int x2, y2;					//P2 좌표
	int x3, y3;					//P3 좌표
	int x4, y4;					//P4 좌표

	float a1, b1;				//L1의 a, b
	float a2, b2;				//L2의 a, b
	float c1, c2;				//x의 계수

	while (1) {		//P1과 P2가 다른값을 가질때까지 입력
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
	
	while (1) {		//P3과 P4가 다른값을 가질때까지 입력
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
	line(&a1, &b1, &c1, x1, y1, x2, y2);	//L1 계산후 출력
	printf("L2 : ");
	line(&a2, &b2, &c2, x3, y3, x4, y4);	//L2 계산후 출력
	determine(a1, b1, c1, a2, b2, c2);	//L1과 L2의 관계구한후 출력
	plot(a1,b1,c1,a2,b2,c2);			
}
void line(float *a, float *b, float *c, int x1, int y1, int x2, int y2) {
	if (y1==y2) {		//x의 계수가 0일때
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
	float x, y;			//교차점의 좌표
	float ang;			//두 직선의 각도

	if ((c1==c2)&&(a1==a2)) {	//기울기가 같을 때
		if(b1!=b2) {		//평행할 때
			printf("L1 and L2 are Parallel.\n");
		}
		else {			//동일할 때
			printf("L1 and L2 are Coincident.\n");
		}
	}
	else {				//기울기가 다를때
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
	
	float ang1, ang2;		//각 직선의 x축과 이루는 각도
	float ang;			//두 직선의 각도

	if(a1==0) {			//a=0이면 90도(PI/2) (x축과 직교함)
		ang1=PI/2;
	}
	else {				//기울기는 x축과의 각의 tan값
		ang1=atan(-c1/a1);
	}
	if(a2==0) {
		ang2=PI/2;
	}
	else {
		ang2=atan(-c2/a2);
	}

	ang=ang1-ang2;		//두 직선의 각도는 각각의 각도의 차이

	if (ang<0) {		//차이이므로 절대값을 취한다
		ang=-ang;
	}
	if (ang>PI/2) {		//예각으로 바꾼다
		ang=PI-ang;
	}

	return ang*180/PI;	//rad를 degree로 변환
}
void plot(float a1, float b1, float c1, float a2, float b2, float c2) {	
//원점 근처의 영역을 plot하는 함수
	int x;
	int y;
	
	for(y=10; y>=-10; y=y-1) {		
		for(x=-10; x<=10; x=x+1) {
			if ((c1*x+a1*y+b1==0)&&(c2*x+a2*y+b2)==0) {
			//교차점
				printf(" 0");
			}
			else if ((c1*x+a1*y+b1==0)||(c2*x+a2*y+b2==0)) {
			//직선위의 점
				printf(" *");
			}
			else if ((x==0)&&(y==0)) {	//원점
				printf(" +");
			}
			else if (x==0) {	//y축
				printf(" |");
			}
			else if (y==0) {	//x축
				printf(" -");
			}
			else {			//빈공간
				printf("  ");
			}
		}
		printf("\n");
	}
}

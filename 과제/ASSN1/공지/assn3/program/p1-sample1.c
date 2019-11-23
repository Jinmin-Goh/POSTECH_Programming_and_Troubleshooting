#include <stdio.h>
#define fflush while(getchar() != '\n')				// 입력 버퍼를 지워주는 함수

void rotate(int size, int scale, int degree);			// 회전 각도에 따라 테이블을 회전시켜 출력해주는 함수
void form(int row, int size, int scale);				// 다이아몬드 꼴 출력시 열을 정렬시켜주는 함수
void adjust(int num, int size, int scale);				// 출력 최대폭에 맞춰 공백을 출력해주는 함수
int absolute(int num);									// 정수형 절대값 함수

int main(){

	int size;		// 테이블의 크기
	int scale;		// 출력되는 수의 최대자리수 
	int degree;		// 회전된 각도, 0 이상 360 미만
	char command;	// 명령어

	command = 'c';

	do{
		if(command == 'N' || command == 'n'){		// 명령어 n, 기본값을 출력
			degree = 0;
		}
		else if(command == 'l' || command == 'L'){	// 명령어 l, 반시계방향으로 45도 회전
			degree += 45;
		}
		else if(command == 'r' || command == 'R'){	// 명령어 r, 시계방향으로 45도 회전
			degree -= 45;
		}
		else if(command == 'c' || command == 'C'){	// 명령어 c, 새로운 size를 입력
			system("clear");
			printf("Enter size: ");
			scanf("%d", &size);
			for(scale=1; scale<=(size*size/10); scale*=10);
			degree = 0;
		}
		if(degree < 0){								// 회전 각도는 0초과 360미만의 값
			degree += 360;
		}
		else if(degree >= 360){						// 회전 각도는 0초과 360미만의 값
			degree -= 360;
		}
		fflush;										// 입력 버퍼를 지움
		system("clear");							// 화면 지우는 함수
		printf("Enter size: %d\n", size);			// 입력된 사이즈의 크기를 표시

		rotate(size, scale, degree);				// 회전된 테이블을 출력


		if(degree%90 == 0){							// 회전각도가 90의 배수일 경우 정사각형 출력
			printf("                                     [□ %3d˚rotated]\n", degree);
		}
		else{										// 회전각도가 45의 홀수 배수인 경우 다이아몬드 출력
			printf("                                     [◇ %3d˚rotated]\n", degree);
		}
		printf("[N] normal, [L] left, [R] right, [C] command, [Q] quit : ");	// 커맨드 리스트 출력
		scanf("%c", &command);													// 커맨드 입력

	}while(command != 'q' && command != 'Q');									// 커맨드가 q(종료)가 아닐때까지 계속 반복

	return 0;																	// 정상 종료
}

void rotate(int size, int scale, int degree){		// 회전 출력 함수

	int row;		// 정사각형 출력시 열, 다이아몬드 출력시 열
	int col;		// 정사각형 출력시 행

	int num;		// 출력되는 숫자
	int unit;		// 출력될 숫자의 남은 개수
	int blank;		// 각 숫자간 간격 조정을 위한 빈칸 출력 단위


	if(degree == 45 || degree == 90){			// 첫 숫자 결정
		num = size;
	}
	else if(degree == 135 || degree == 180){	// 첫 숫자 결정
		num = size*size;
	}
	else if(degree == 225 || degree == 270){	// 첫 숫자 결정
		num = size*size - (size - 1);
	}
	else if(degree == 315 || degree == 0){		// 첫 숫자 결정
		num = 1;
	}

	if(degree == 45 || degree == 135 || degree == 225 || degree == 315){	// 다이아몬드 꼴 출력시

		for(row=1; row<size*2; row++){										// 줄을 늘리며 숫자 출력
			form(row, size, scale);											// 다이아몬드 출력시 열을 맞추기 위한 공백 출력 함수 
			for(unit=size-absolute(size-row); unit>0; unit--){				// 매 출력시 출력될 숫자의 남은 개수를 줄임
				adjust(num, size, scale);									// 최대단위수와 출력폭 맞추기
				printf("%d", num);											// 값 출력
				for(blank=scale; blank>=1; blank/=10){						// 각 숫자 사이 빈칸 출력
					printf(" ");
				}
				if(degree == 45){											// 열 진행시 공식
					num+=(size+1);
				}
				else if(degree == 135){
					num+=(size-1);
				}
				else if(degree == 225){
					num-=(size+1);
				}
				else if(degree == 315){
					num-=(size-1);
				}
			}
			printf("\n");

			if(row<size){													// 행 진행시 공식(위의칸)
				if(degree == 45){
					num-=( (size+1)*row +1);
				}
				else if(degree == 135){
					num-=( (size-1)*(row+1) +1);
				}
				else if(degree == 225){
					num+=( (size+1)*row +1);
				}
				else if(degree == 315){
					num+=( (size-1)*(row+1) +1);
				}
			}
			else{															// 행 진행시 공식(아래칸)
				if(degree == 45){
					num-=( (size+1)*(size*2-row-1) +1);
				}
				else if(degree == 135){
					num-=( (size-1)*(size*2-row) +1);
				}
				else if(degree == 225){
					num+=( (size+1)*(size*2-row-1) +1);
				}
				else if(degree == 315){
					num+=( (size-1)*(size*2-row) +1);
				}
			}
		}
	}
	else if(degree == 90 || degree == 180 || degree == 270 || degree == 0){	// 정사각형 꼴 출력시

		for(col=0; col<size; col++){
			for(row=0; row<size; row++){

				adjust(num, size, scale);									// 최대 단위에 출력폭을 맞춤

				printf("%d", num);											// 값 출력
				for(blank=scale; blank>=1; blank/=10){						// 수 사이 공백 출력
					printf(" ");
				}
				if(degree == 0){											// 열 진행 공식
					num++;
				}
				else if(degree == 90){
					num += size;
				}
				else if(degree == 180){
					num--;
				}
				else if(degree == 270){
					num -= size;
				}
			}
			if(col!=size-1){												// 행 진행 공식
				if(degree == 0){
				}
				else if(degree == 90){
					num -= (size*size+1);
				}
				else if(degree == 180){
				}
				else if(degree == 270){
					num += (size*size+1);
				}
				printf("\n\n");
			}
			else{															// 말단 행
				printf("\n");
			}
		}
	}


}

void adjust(int num, int size, int scale){						// 출력 최대 폭에 맞춰 공백을 출력해주는 함수

	int width;

	for(width=scale; num < width; width/=10){
		printf(" ");
	}
}
void form(int row, int size, int scale){						// 다이아몬드 출력시 열을 맞추기 위해 공백을 출력하는 함수

	int blank;
	int width;

	for(width=scale; width>=10; width/=10){
		for(blank=absolute(size-row); blank>0; blank-=1){
			printf(" ");
		}
	}

	for(blank=absolute(size-row); blank>0; blank-=1){
		printf(" ");
	}
}

int absolute(int num){											// int형 절대값 함수

	if(num<0){
		return -num;
	}
	else{
		return num;
	}
}

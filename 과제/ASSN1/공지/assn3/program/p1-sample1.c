#include <stdio.h>
#define fflush while(getchar() != '\n')				// �Է� ���۸� �����ִ� �Լ�

void rotate(int size, int scale, int degree);			// ȸ�� ������ ���� ���̺��� ȸ������ ������ִ� �Լ�
void form(int row, int size, int scale);				// ���̾Ƹ�� �� ��½� ���� ���Ľ����ִ� �Լ�
void adjust(int num, int size, int scale);				// ��� �ִ����� ���� ������ ������ִ� �Լ�
int absolute(int num);									// ������ ���밪 �Լ�

int main(){

	int size;		// ���̺��� ũ��
	int scale;		// ��µǴ� ���� �ִ��ڸ��� 
	int degree;		// ȸ���� ����, 0 �̻� 360 �̸�
	char command;	// ��ɾ�

	command = 'c';

	do{
		if(command == 'N' || command == 'n'){		// ��ɾ� n, �⺻���� ���
			degree = 0;
		}
		else if(command == 'l' || command == 'L'){	// ��ɾ� l, �ݽð�������� 45�� ȸ��
			degree += 45;
		}
		else if(command == 'r' || command == 'R'){	// ��ɾ� r, �ð�������� 45�� ȸ��
			degree -= 45;
		}
		else if(command == 'c' || command == 'C'){	// ��ɾ� c, ���ο� size�� �Է�
			system("clear");
			printf("Enter size: ");
			scanf("%d", &size);
			for(scale=1; scale<=(size*size/10); scale*=10);
			degree = 0;
		}
		if(degree < 0){								// ȸ�� ������ 0�ʰ� 360�̸��� ��
			degree += 360;
		}
		else if(degree >= 360){						// ȸ�� ������ 0�ʰ� 360�̸��� ��
			degree -= 360;
		}
		fflush;										// �Է� ���۸� ����
		system("clear");							// ȭ�� ����� �Լ�
		printf("Enter size: %d\n", size);			// �Էµ� �������� ũ�⸦ ǥ��

		rotate(size, scale, degree);				// ȸ���� ���̺��� ���


		if(degree%90 == 0){							// ȸ�������� 90�� ����� ��� ���簢�� ���
			printf("                                     [�� %3d��rotated]\n", degree);
		}
		else{										// ȸ�������� 45�� Ȧ�� ����� ��� ���̾Ƹ�� ���
			printf("                                     [�� %3d��rotated]\n", degree);
		}
		printf("[N] normal, [L] left, [R] right, [C] command, [Q] quit : ");	// Ŀ�ǵ� ����Ʈ ���
		scanf("%c", &command);													// Ŀ�ǵ� �Է�

	}while(command != 'q' && command != 'Q');									// Ŀ�ǵ尡 q(����)�� �ƴҶ����� ��� �ݺ�

	return 0;																	// ���� ����
}

void rotate(int size, int scale, int degree){		// ȸ�� ��� �Լ�

	int row;		// ���簢�� ��½� ��, ���̾Ƹ�� ��½� ��
	int col;		// ���簢�� ��½� ��

	int num;		// ��µǴ� ����
	int unit;		// ��µ� ������ ���� ����
	int blank;		// �� ���ڰ� ���� ������ ���� ��ĭ ��� ����


	if(degree == 45 || degree == 90){			// ù ���� ����
		num = size;
	}
	else if(degree == 135 || degree == 180){	// ù ���� ����
		num = size*size;
	}
	else if(degree == 225 || degree == 270){	// ù ���� ����
		num = size*size - (size - 1);
	}
	else if(degree == 315 || degree == 0){		// ù ���� ����
		num = 1;
	}

	if(degree == 45 || degree == 135 || degree == 225 || degree == 315){	// ���̾Ƹ�� �� ��½�

		for(row=1; row<size*2; row++){										// ���� �ø��� ���� ���
			form(row, size, scale);											// ���̾Ƹ�� ��½� ���� ���߱� ���� ���� ��� �Լ� 
			for(unit=size-absolute(size-row); unit>0; unit--){				// �� ��½� ��µ� ������ ���� ������ ����
				adjust(num, size, scale);									// �ִ�������� ����� ���߱�
				printf("%d", num);											// �� ���
				for(blank=scale; blank>=1; blank/=10){						// �� ���� ���� ��ĭ ���
					printf(" ");
				}
				if(degree == 45){											// �� ����� ����
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

			if(row<size){													// �� ����� ����(����ĭ)
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
			else{															// �� ����� ����(�Ʒ�ĭ)
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
	else if(degree == 90 || degree == 180 || degree == 270 || degree == 0){	// ���簢�� �� ��½�

		for(col=0; col<size; col++){
			for(row=0; row<size; row++){

				adjust(num, size, scale);									// �ִ� ������ ������� ����

				printf("%d", num);											// �� ���
				for(blank=scale; blank>=1; blank/=10){						// �� ���� ���� ���
					printf(" ");
				}
				if(degree == 0){											// �� ���� ����
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
			if(col!=size-1){												// �� ���� ����
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
			else{															// ���� ��
				printf("\n");
			}
		}
	}


}

void adjust(int num, int size, int scale){						// ��� �ִ� ���� ���� ������ ������ִ� �Լ�

	int width;

	for(width=scale; num < width; width/=10){
		printf(" ");
	}
}
void form(int row, int size, int scale){						// ���̾Ƹ�� ��½� ���� ���߱� ���� ������ ����ϴ� �Լ�

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

int absolute(int num){											// int�� ���밪 �Լ�

	if(num<0){
		return -num;
	}
	else{
		return num;
	}
}

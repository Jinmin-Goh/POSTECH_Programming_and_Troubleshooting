#include  <stdio.h>

FILE* fopen_polygon();			// �ٰ��� ���� �ִ� ������ �о����
FILE* fopen_test();				// �׽�Ʈ�� ���� �ִ� ������ �о����
FILE* fopen_output();			// ����� ����� ������ �о����
int in_out_check (FILE* polygon_file, double x, double y);	// �������� �ܺ����� �Ǵ��ϴ� �Լ�
void point_write(FILE* output_file, int test_point_index, int in_or_out);	// �׽�Ʈ ����� �����ϴ� �Լ�

int main() {
	FILE *polygon_file;		// �ٰ��� ������ ����������
	FILE *test_file;		// �׽�Ʈ�� ���� ����������
	FILE *output_file;		// ��� ����� ����������
	int flag;
	double x,y;				// �׽�Ʈ�� �� �Ѱ� ���� x, y��ǥ
	int test_point_index;	// ���� �׽�Ʈ�ϴ� ���� ��ȣ
	int in_or_out;			// �������� �ܺ����� �����ϴ� ����
							// 1�̸� ����, 0�̸� �ܺ�. 2�̸� ���Ͽ���

	polygon_file = fopen_polygon();
	test_file = fopen_test();
	output_file = fopen_output();
	if (polygon_file == NULL || test_file == NULL || output_file == NULL)  {
		return 0;	
	} // ���߿� �ϳ��� �����ϸ� ���α׷��� �����Ѵ�.

	printf(">> �۾���...\n");
	flag = fscanf(test_file, "%d%lf%lf",&test_point_index, &x, &y);
	// �׽�Ʈ�� �� �Ѱ��� �о� ���δ�.
	while (flag != EOF) {
		rewind(polygon_file);
		in_or_out = in_out_check(polygon_file, x, y);
		// ���� �������� �ܺ����� üũ�Ѵ�.
		if (in_or_out == 2) {
			printf("!! �ٰ����� ������ ��ǥ�� ����ִ� ���������� �ùٸ��� �ʽ��ϴ� !!\n");
			return 0;
		}
		point_write(output_file, test_point_index, in_or_out);
		// ����/�ܺ� �Ǻ��� ����� ����Ѵ�.
		flag = fscanf(test_file, "%d%lf%lf",&test_point_index, &x, &y);
	}
	// �Ѱ� ���� �޾Ƽ� �׽�Ʈ�ϰ� ���� ���

	fclose(polygon_file);
	fclose(test_file);
	fclose(output_file);	// ������ ��� �ݴ´�.

	printf("!! �۾��Ϸ� !!\n");
}

void point_write(FILE* output_file, int test_point_index, int in_or_out) {
	if (in_or_out == 1) {
		fprintf(output_file, "%d inside\n", test_point_index);
	}
	else {
		fprintf(output_file, "%d outside\n", test_point_index);
	}	// ���ο� �ܺ��� �� �ٸ��� ����ؾ���
}

int in_out_check (FILE* polygon_file, double x, double y) {
	int i, flag;
	int polygon_num;
	long pf_point;
	double x1, y1, x2, y2;

	fscanf(polygon_file,"%d",&polygon_num);	// �ٰ��� ���� ������ �о���δ�.
	flag = fscanf(polygon_file,"%lf%lf",&x1, &y1);	// ó�� ���� �о� ���δ�.
	if (flag == EOF) {
		return 2;
	}
	for (i=1 ; i <= polygon_num ; i++) { // �ٰ��� ���� ���� ��ŭ �ݺ��Ѵ�.
		flag = fscanf(polygon_file,"%lf%lf",&x2, &y2); // ������ ���� �о���δ�.
		if (flag == EOF) {
			return 2;
		}
		if ((x2-x1)*(y-y1)-(x-x1)*(y2-y1) >= 0) {
			return 0;	// �ܺδ� 0 ����
			// singed area ����� ����Ͽ� 0�̻��̸� �����ʿ� �ִ� ���� �ƴϹǷ�
			// �ٷ� 0�� �����Ѵ�.
		}
		else {
		}
		x1 = x2;
		y1 = y2; // ������ ���� ���� for������ ���� ���� �ǹǷ� �ٲ㼭 �����Ѵ�.
	}
	return 1;	// polygon���� ��ü �׽�Ʈ�� ��������Ƿ� inside ����. 1����
}

FILE* fopen_polygon() {
	FILE *polygon_file;

	printf(">>> �ٰ����� ������ ��ǥ : ploygon.dat\n");
	polygon_file = fopen("polygon.dat","r");	// read ���� ����
	if (polygon_file == NULL) {
		printf("!!! polygon.dat ������ �� �� �����ϴ�.\n");
	}	// ���� ������ ���� ��쿡�� NULL�� �����ϹǷ� ������ ����� �ش�.
	return polygon_file;	// �ٰ��� ���� ���������͸� �����Ѵ�.
}

FILE* fopen_test() {
	FILE *test_file;

	printf(">>> �׽�Ʈ�� ������ ��ǥ : indata.dat\n");
	test_file = fopen("indata.dat","r");		// read ���� ����.
	if (test_file == NULL) {
		printf("!!! indata.dat ������ �� �� �����ϴ�.\n");
	}	// ���� ������ ���� ��쿡�� NULL�� �����ϹǷ� ������ ����� �ش�.
	return test_file;	// �׽�Ʈ�� ���� ���������͸� �����Ѵ�.
}

FILE* fopen_output() {
	FILE *output_file;

	printf(">>> �׽�Ʈ ��� : 20071014.dat\n");
	output_file = fopen("20071014.dat","w");	// write ���� ����.
	if (output_file == NULL) {
		printf("!!! 20071014.dat ������ �� �� �����ϴ�.\n");
	}	// ������ �� �� ���� ��쿡�� NULL�� �����ϹǷ� ������ ����� �ش�.
	return output_file;	// �������� ���������͸� �����Ѵ�.
}

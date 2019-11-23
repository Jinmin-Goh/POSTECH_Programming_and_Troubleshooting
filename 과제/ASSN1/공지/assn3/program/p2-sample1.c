#include  <stdio.h>

FILE* fopen_polygon();			// 다각형 점이 있는 파일을 읽어들임
FILE* fopen_test();				// 테스트할 점이 있는 파일을 읽어들임
FILE* fopen_output();			// 결과를 출력할 파일을 읽어들임
int in_out_check (FILE* polygon_file, double x, double y);	// 내부인지 외부인지 판단하는 함수
void point_write(FILE* output_file, int test_point_index, int in_or_out);	// 테스트 결과를 저장하는 함수

int main() {
	FILE *polygon_file;		// 다각형 파일의 파일포인터
	FILE *test_file;		// 테스트할 점의 파일포인터
	FILE *output_file;		// 결과 출력의 파일포인터
	int flag;
	double x,y;				// 테스트할 때 한개 점의 x, y좌표
	int test_point_index;	// 현재 테스트하는 점의 번호
	int in_or_out;			// 내부인지 외부인지 저장하는 변수
							// 1이면 내부, 0이면 외부. 2이면 파일오류

	polygon_file = fopen_polygon();
	test_file = fopen_test();
	output_file = fopen_output();
	if (polygon_file == NULL || test_file == NULL || output_file == NULL)  {
		return 0;	
	} // 셋중에 하나라도 실패하면 프로그램을 종료한다.

	printf(">> 작업중...\n");
	flag = fscanf(test_file, "%d%lf%lf",&test_point_index, &x, &y);
	// 테스트할 점 한개를 읽어 들인다.
	while (flag != EOF) {
		rewind(polygon_file);
		in_or_out = in_out_check(polygon_file, x, y);
		// 점이 내부인지 외부인지 체크한다.
		if (in_or_out == 2) {
			printf("!! 다각형의 꼭지점 좌표가 들어있는 파일형식이 올바르지 않습니다 !!\n");
			return 0;
		}
		point_write(output_file, test_point_index, in_or_out);
		// 내부/외부 판별후 결과를 출력한다.
		flag = fscanf(test_file, "%d%lf%lf",&test_point_index, &x, &y);
	}
	// 한개 점을 받아서 테스트하고 점을 기록

	fclose(polygon_file);
	fclose(test_file);
	fclose(output_file);	// 파일을 모두 닫는다.

	printf("!! 작업완료 !!\n");
}

void point_write(FILE* output_file, int test_point_index, int in_or_out) {
	if (in_or_out == 1) {
		fprintf(output_file, "%d inside\n", test_point_index);
	}
	else {
		fprintf(output_file, "%d outside\n", test_point_index);
	}	// 내부와 외부일 때 다르게 출력해야함
}

int in_out_check (FILE* polygon_file, double x, double y) {
	int i, flag;
	int polygon_num;
	long pf_point;
	double x1, y1, x2, y2;

	fscanf(polygon_file,"%d",&polygon_num);	// 다각형 점의 개수를 읽어들인다.
	flag = fscanf(polygon_file,"%lf%lf",&x1, &y1);	// 처음 점을 읽어 들인다.
	if (flag == EOF) {
		return 2;
	}
	for (i=1 ; i <= polygon_num ; i++) { // 다각형 점의 개수 만큼 반복한다.
		flag = fscanf(polygon_file,"%lf%lf",&x2, &y2); // 다음번 점을 읽어들인다.
		if (flag == EOF) {
			return 2;
		}
		if ((x2-x1)*(y-y1)-(x-x1)*(y2-y1) >= 0) {
			return 0;	// 외부는 0 리턴
			// singed area 방식을 사용하여 0이상이면 오른쪽에 있는 것이 아니므로
			// 바로 0을 리턴한다.
		}
		else {
		}
		x1 = x2;
		y1 = y2; // 다음번 점은 다음 for문에서 이전 점이 되므로 바꿔서 저장한다.
	}
	return 1;	// polygon파일 전체 테스트를 통과했으므로 inside 판정. 1리턴
}

FILE* fopen_polygon() {
	FILE *polygon_file;

	printf(">>> 다각형의 꼭지점 좌표 : ploygon.dat\n");
	polygon_file = fopen("polygon.dat","r");	// read 모드로 연다
	if (polygon_file == NULL) {
		printf("!!! polygon.dat 파일을 열 수 없습니다.\n");
	}	// 만약 파일이 없을 경우에는 NULL을 리턴하므로 오류를 출력해 준다.
	return polygon_file;	// 다각형 점의 파일포인터를 리턴한다.
}

FILE* fopen_test() {
	FILE *test_file;

	printf(">>> 테스트할 점들의 좌표 : indata.dat\n");
	test_file = fopen("indata.dat","r");		// read 모드로 연다.
	if (test_file == NULL) {
		printf("!!! indata.dat 파일을 열 수 없습니다.\n");
	}	// 만약 파일이 없을 경우에는 NULL을 리턴하므로 오류를 출력해 준다.
	return test_file;	// 테스트할 점의 파일포인터를 리턴한다.
}

FILE* fopen_output() {
	FILE *output_file;

	printf(">>> 테스트 결과 : 20071014.dat\n");
	output_file = fopen("20071014.dat","w");	// write 모드로 연다.
	if (output_file == NULL) {
		printf("!!! 20071014.dat 파일을 쓸 수 없습니다.\n");
	}	// 파일을 쓸 수 없는 경우에는 NULL을 리턴하므로 오류를 출력해 준다.
	return output_file;	// 결과출력할 파일포인터를 리턴한다.
}

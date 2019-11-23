#include <stdio.h>         

int N;		//������
char ch;	//����� ����

int point(int x, int y)		//�ʱ� ��ġ�� ���� ���ڸ� ��Ÿ���� �Լ�
{
	return (N*x + y + 1);	//i�� j������ N*(i-1)+j���� ��ȯ
}

void rotation()				//���� ���簢���� ȸ�����Ѽ� ����ϴ� �Լ�
{
	int i, j;
	if(ch=='l' || ch=='L')		//�������� ȸ����Ű�� ���
	{
		for(i=N-1;i>=0;i--)		//���κ� �ﰢ�� ��� ���
		{
			for(j=0;j<i;j++)
			{
				printf(" ");	
			}
			j=0;
			while(1)
			{
				printf("%d ", point(j, j+i));
				if(j+i==N-1)
					break;
				j++;
			}
			printf("\n");
		}
		for(i=1;i<N;i++)		//�Ʒ��κ� �ﰢ�� ��� ���
		{
			for(j=0;j<i;j++)
				printf(" ");
			while(1)
			{
				printf("%d ", point(j, j-i));
				if(j==N-1)
					break;
				j++;
			}
			printf("\n");
		}
	}

	else						//���������� ȸ����Ű�� ���
	{
		for(i=0;i<N;i++)		//���κ� �ﰢ�� ��� ���
		{
			for(j=N-1;j>i;j--)
			{
				printf(" ");
			}
			j=i;
			while(1)
			{
				printf("%d ", point(j, i-j));
				if(j==0)
					break;
				j--;
			}
			printf("\n");
		}
		for(i=1;i<N;i++)		//�Ʒ��κ� �ﰢ�� ��� ���
		{
			for(j=0;j<i;j++)
				printf(" ");
			j=N-1;
			while(1)
			{
				printf("%d ", point(j, N-1+i-j));
				if(j==i)
					break;
				j--;
			}
			printf("\n");
		}
	}
}

int main(void)
{
	int i, j;

	while(1)
	{

		printf("Enter size : ");
		scanf("%d", &N);

		for(i=0;i<N;i++)		//�� ó�� ���簢�� ��� ���
		{
			for(j=0;j<N;j++)
			{
				printf("%d ", point(i, j));
			}
			printf("\n");
		}

		while(1)		//����Ͽ� ���ĺ��� �޵��� while�� ����
		{
			scanf("%c", &ch);
			if( ch=='r' || ch=='R' || ch=='l' || ch=='L' )		//ȸ����Ű�� ���
				rotation();
			else if( ch=='c' || ch=='C' )		//c�� ������ �� ó���� while������ ���ư��� �ٽ� size�� �Է¹޴´�
				break;
			else if( ch=='q' || ch=='Q' )		//q�� ������ ���α׷��� �����Ѵ�
				return 0;
			else if( ch != '\n')				//�̻��� ���ڸ� ������ ���� ó��
				printf("Input error.\n");
		}
	}
}
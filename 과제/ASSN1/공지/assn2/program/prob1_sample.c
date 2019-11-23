#include <stdio.h>
/* define constant for checking celcius and fahrenheit */

#define CEL 1
#define FAH 0

/* function */

/* this function return 1 if temperature is Celsius else 0 */
int check_C(void)
{
	char check_c;

	do{
		printf("Is this a Fahrenheit or Celsius?[F/C] ");
		scanf(" %c",&check_c);

		if (check_c != 'F' && check_c != 'f' && check_c != 'c'&& check_c != 'C')
			printf("Incorrect temperature scale!!!\n");
  	
	}while(check_c != 'F' && check_c != 'f' && check_c != 'c' && check_c != 'C');

	if(check_c == 'c' || check_c == 'C')
		return CEL;
	else
		return FAH; 	
}

/* this function get temperatur value */
/* convert temp to Fahrenheit */
/* and printf fahrenheit value */

void convert_CtoF(double temp)
{
	double F;
	
	F = temp * 1.8 + 32.0;

	printf("\t%.2lf C = %.2lf F\n",temp,F);

	return;
}
/* this function's input is temperature */
/* it convert temp to celsius */
/* and print converted value */
void convert_FtoC(double temp)
{
	double C;

	C = (temp - 32.0) / 1.8;

	printf("\t%.2lf F = %.2lf C\n",temp,C);

	return;

}
/*-----------------------------------------------*/
/* main */
int main()
{
	double temp;
	int C_F; /* C_F = 1 -> Celsius, else Fahrenheit */	
	int i = 0; /* use to determine terminating */

	do{
	/* get temperature */
		printf("Enter the degree you want to convert : ");
		scanf("%lf",&temp);

		C_F = check_C();

		if (C_F == CEL)
			convert_CtoF(temp);
		else
			convert_FtoC(temp);
	
		/* ask kepp going or quit */
		printf("//////////////////////////////////////\n");
		printf("\t1.continue\t2.EXIT : ");
		scanf("%d",&i);
		
	}while(i == 1); 

	
	return 0;
}

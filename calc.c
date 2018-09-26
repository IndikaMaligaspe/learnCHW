#include <stdio.h>

int main(int argc , char *argv){
	double input1 , input2, ans;
        char operator;

	while (1){
		input1, input2,ans = 0;

		printf("enter a number of or CNTR+C to exit : ");
		scanf("%lf", &input1);
		printf("\n");
		
		printf("enter a operator [+ , - , * , / , %] :");
		scanf(" %c", &operator);
		printf("\n");
		
		printf("enter another number : ");
		scanf("%lf", &input2);
		printf("\n");
		
		switch(operator)
		{
			case '+':
				ans = input1 + input2;
				break;
			case '-':
				ans = input1 - input2;
				break;
			case '*':
				ans = input1 * input2;
				break;
			case '/':
				ans = input1 /input2;
			default:
				return 0;
				
		}
		printf("Answer  = %lf  :",ans);		
		printf("\n");
		
	}

}

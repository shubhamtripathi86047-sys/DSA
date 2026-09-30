//WAP to take input from user find factorial number using function.
#include<stdio.h>
int fact(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	return n*fact(n-1); 
}
main()
{
	int n;
	printf("Enter any number:- ");
	scanf("%d",&n);
	int f=fact(n);
	printf("Factorial of given number:- %d",f);
}

//Write a C program to reverse a number without using a loop.
#include<stdio.h>
int rev(int n, int revs)
{
	if(n==0)
	{
		return revs;
	}
	return rev(n/10,revs*10+(n%10));
}
main(){
	int num, revs;
	printf("Enter any number:- ");
	scanf("%d",&num);
	printf("Reverse Number : %d",rev(num, 0));
}

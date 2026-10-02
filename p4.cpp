//WAP to Palindrome a string without built-in function.
#include<stdio.h>
main()
{
	char str[50],rev[50];
	int length=0,k=0,f=0;
	printf("Enter any String:-  ");
	gets(str);
	for(int i=0;str[i]!='\0';i++)
	{
		length++;
	}
	printf("Count string= %d\n",length);
	for(int i=length-1;i>=0;i--)
	{
		rev[k]=str[i];
		k++;
	}
	rev[k]='\0';
	printf("Revese string:-  %s\n",rev);
	for(int i=0;i<length;i++)
	{
		if(rev[i]!=str[i])
		{
		f=1;
		break;
		}
	}
	if(f==0)
	{
		printf("Palindrome string");
	}
	else
	{
		printf("Not Palindrome string");
	}
	
}

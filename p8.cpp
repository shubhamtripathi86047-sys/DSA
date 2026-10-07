#include<stdio.h>
#include<string.h>
main()
{
	char name[50], rev[50];
	printf("Enter name:- ");
	gets(name);
	strcpy(rev, name);
	strrev(rev);
	printf("%s\n",rev);
	if(strcmp(name,rev)==0)
	{
		printf("Palindrome..");
	}
	else{
		printf("Not Palindrome..");
	}
}

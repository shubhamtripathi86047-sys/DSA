//WAP to find string length using fgets function
#include<stdio.h>
#include<string.h>
main()
{
	char str[50];
	fgets(str,sizeof(str),stdin);
	printf("%d",strlen(str));
	
}

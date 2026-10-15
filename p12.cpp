//WAP to find string Anagram using C.
#include<stdio.h>
#include<string.h>
main()
{
	char str1[50],str2[50];
	int i,j,c=0;
	printf("Enter any name:- ");
	gets(str1);
	printf("Enter any name:- ");
	gets(str2);
	if(strlen(str1)!=strlen(str2))
	{
		printf("Not Anagram string..");
	}
	for(i=0; str1[i]!='\0'; i++)
	{
		for(j=0; str2[j]!='\0'; j++)
		{
			if(str1[i] == str2[j])
			{
				c++;
				str2[j] = '*';
				break;
			}
		}
	}
	if(c==strlen(str1))
	{
		printf("Angram..");
	}
	else
	{
		printf("Not Angram..");
	}
	
	
}

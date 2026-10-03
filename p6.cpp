//WAP to count vowels and consonants in a string.
#include<stdio.h>
main()
{
	char str[50];
	printf("Enter any name:- ");
	gets(str);
	int vowel=0, consonants=0;
	for(int i=0; str[i]!='\0'; i++)
	{
		char ch=str[i];
		if(ch=='a' || ch=='A' ||ch=='e' || ch=='E' ||ch=='i' || ch=='I' || ch=='o' || ch=='O' ||ch=='u' || ch=='U')
		{
			vowel++;
		}
		else
		{
			consonants++;
		}
	}
	printf("Vowels:- %d",vowel);
	printf("Consonants:- %d",consonants);
}

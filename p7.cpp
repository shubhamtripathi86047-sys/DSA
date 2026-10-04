//WAP to demonstrate concept of structure.
#include<stdio.h>
#include<stdlib.h>
main()
{
	struct employee{
		//structure Member
		int empid;   
		char empname[50];
		long int salary;
	};
	struct employee e;//structure variable.
	printf("Enter Employee Id:-  ");
	scanf("%d",&e.empid);
	fflush(stdin);
	printf("Enter Employee Name:-  ");
	gets(e.empname);
	printf("Enter Employee Salary:-  ");
	scanf("%ld",&e.salary);
	printf("------------------Employee Details---------------------\n");
	printf("Employee Id:-  %d\n",e.empid);
	printf("Employee Name:-  %s\n",e.empname);
	printf("Employee salary:-  %ld\n",e.salary);
}


//WAP to swap a array element first position to last position.
#include<stdio.h>
main()
{
	int n;
	printf("Enter array size:- ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		printf("Enter element:- ");
		scanf("%d",&arr[i]);
	}
	printf("Replace Number:- \n");

		int temp=arr[0];
		arr[0] = arr[n-1];
		arr[n-1]= temp; 
	
	for(int i=0;i<n;i++){
		printf("Swaped Array is : %d \n",arr[i]);
	}
}

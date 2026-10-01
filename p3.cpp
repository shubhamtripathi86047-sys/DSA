//WAP to sort in arrays.
#include<stdio.h>
main(){
	int n;
	printf("Enter array size:- ");
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n; i++)
	{
		printf("Enter Element:- ");
		scanf("%d",&arr[i]);
	}
	printf("Without sorted array:- \n");
	for(int i = 0; i < n; i++)
	{
	printf("%d ",arr[i]);
}
	for(int i = 0; i < n- 1; i++){
		for(int j = i + 1; j < n; j++){
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("\nsorted array:- \n");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}

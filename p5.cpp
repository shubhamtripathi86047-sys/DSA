#include<stdio.h>
#include<math.h>
main()
{
 int n;
 printf("Enter any number:- ");
 scanf("%d",&n);
 int ar[n][n];
 int sqr = pow(n,n);
 int i,j,k=1;
 for(i=0;i<n;i++){
 	for(j=0;j<n;j++){
 		if(sqr<k){
 			break;
		 }else{
		 	ar[i][j]=k;
		 	k++;
		 }
	 }
 	}
 	printf("Matrix is : \n");
 	for(i=0;i<n;i++){
 	for(j=0;j<n;j++){
 		printf(" %d",ar[i][j]);
	 }
	 printf("\n");
 	}
 	
}

#include<stdio.h>
void main(){
      int limit,i;
      printf("Enter the number of elements:");
      scanf("%d",&limit);
      int ar[limit];
      printf("Enter the elements:");
      for(i=0;i<limit;i++){
      		scanf("%d",&ar[i]);
      }
       printf("The array before  Insertion sorting is :   ");
      for(i=0;i<limit;i++){
      		printf("%d\t",ar[i]);
      }
      int temp,j;
      i=1;
      while(i<limit){
      		j=i;
      		while(ar[j]<ar[j-1] && j>0){
      		temp=ar[j];
      		ar[j]=ar[j-1];
      		ar[j-1]=temp;
      		j--;	
      		}
      	i++;	
      }
      printf("\nThe array after Insertion sorting is   :   ");
      for(i=0;i<limit;i++){
      		printf("%d\t",ar[i]);
      }
      
      printf("\n");
}

#include<stdio.h>
void main(){

int n,i,pos;
printf("Enter the no of nodes:");
scanf("%d",&n);
int t[n];
printf("Enter the elements of Binary tree:");
for(i=1;i<=n;i++)
{
 scanf("%d",&t[i]);
}

char choice='y';
while (choice=='y'){
printf("\nEnter the position of node(except 0):");
scanf("%d",&pos);

if(pos==0)
printf("No element at position o\n");

else{
if(pos/2==0)
printf("\n%d DON'T HAVE A PARENT\n",t[pos]);
else
printf("%d's PARENT IS=%d\n",t[pos],t[pos/2]);
if(2*pos>n)
printf("%d DON'T HAVE A LEFT CHILD\n",t[pos]);
else
printf("%d's LEFT CHILD IS=%d\n",t[pos],t[2*pos]);
if(2*pos+1>n)
printf("%d DON'T HAVE A RIGHT CHILD\n",t[pos]);
else
printf("%d's RIGHT CHILD IS=%d\n",t[pos],t[2*pos+1]);
}
printf("Do you want to continue?(Y/N)");
scanf(" %c",&choice);
printf("\n");
}
}


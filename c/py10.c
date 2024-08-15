#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Exch(int *p,int *q){
int temp=*p;
*p=*q;
*q=temp;
}
void QS(int a[],int low,int high){
if(low>=high)
return;
int key=low,i=low+1,j=high;
while(i<=j){
while(a[i]<=a[key]&&i<=high)
i++;
while(a[j]>a[key]&&j>=low)
j--;
if(i<j)
Exch(&a[i],&a[j]);
}
Exch(&a[j],&a[key]);
QS(a,low,j-1);
QS(a,j+1,high);
}
int main(){
int n,k;
clock_t st,et;
double ts;
printf("\nEnter how many numbers:");
scanf("%d",&n);
if(n<=0){
printf("Invalid input\n");
return 1;
}
int a[n];
printf("\nThe random numbers are:\n");
srand(time(NULL));
for(k=0;k<n;k++){
a[k]=rand();
printf("%d\t",a[k]);
}
st=clock();
QS(a,0,n-1);
et=clock();
ts=(float)(et-st)/CLOCKS_PER_SEC;
printf("\nSorted numbers are:\n");
for(k=0;k<n;k++)
printf("%d\t",a[k]);
printf("\nTime taken is %f\n",ts);
return 0;
}

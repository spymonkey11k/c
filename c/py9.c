#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sel_sort(int arr[],int n)
{
for(int i=0;i<n;i++){
int min=i;
for(int j=i+1;j<n;j++){
if(arr[j]<arr[min]){
min=j;
}
}
int temp=arr[min];
arr[min]=arr[i];
arr[i]=temp;
}
}
int main()
{
int n,a[50000],k;
clock_t st,et;
double ts;
printf("\nEnter how many numbers:");
scanf("%d",&n);
printf("The random numbers are:\n");
for(k=0;k<n;k++){
a[k]=rand();
printf("%d\t",a[k]);
}
st=clock();
sel_sort(a,n);
et=clock();
ts=(double)(et-st)/CLOCKS_PER_SEC;
printf("\nSorted Numbers are:\n");
for(k=0;k<n;k++)
printf("%d\t",a[k]);
printf("\nThe time taken is %e",ts);
}



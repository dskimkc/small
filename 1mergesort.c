#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[1000],int low ,int mid,int high){
    int b[1000],i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high){
        if(a[i]<=a[j]){
            b[k++]=a[i++];}
            else{
                b[k++]=a[j++];}
                }

while (i<=mid)
{
    b[k++]=a[i++];
}
while (j<=high){
    b[k++]=a[j++];}
    for(k=low;k<=high;k++){
        a[k]=b[k];}
}
    
void sort(int a[1000],int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        sort(a,low,mid);
        sort(a,mid+1,high);
        merge(a,low,mid,high);
        }
        }
int main(){
    int a[1000],n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);}
        sort(a,0,n-1);
        printf("Sorted array:");
        for(i=0;i<n;i++){
            printf("%d ",a[i]);}
            return 0;
            }






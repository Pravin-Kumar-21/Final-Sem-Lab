#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[], int low, int high)
{
    int pivot=a[low];
    int start= low;
    int end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot=partition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
int main()
{
    int a[]={5,3,56,34,43,23,54,21,34,56};
    int n=sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);

    }
return 0;
}
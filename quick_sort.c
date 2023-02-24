#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=*a;
}
int partition(int a[],int low ,int high)
{
    int pivot=a[low];
    int start=low;
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
void quicksort(int a[] , int low , int high)
{   if(low<high)
    {
        int pivot=partition(a,low,high);
        quicksort(a,low,pivot-1);
        quicksort(a,pivot+1,high);
    }
}
void print_array(int *arr,int size )
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={21,3,234,4,56,32,67,43,56,52};
    int n=sizeof(arr)/sizeof(arr[0]);
    print_array(arr,n);
    quicksort(arr,0,n-1);
    print_array(arr,n);
return 0;
}
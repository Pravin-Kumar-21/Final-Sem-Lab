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
    int start, end,pivot;
    pivot=a[low];
    start=low;
    end=high;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start < end)
        {
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[low],&a[end]);
    return end;
}
void quick_sort(int a[], int low , int high)
{
    if(low<high)
    {
        int pivot=partition(a, low, high);
        quick_sort(a,low,pivot-1);
        quick_sort(a,pivot+1,high);
    
    }
}

int main()
{
    int a[]={21,221,43,56,12,34,74,223,2,1,43};
    int n=(sizeof(a)/sizeof(a[0]));
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    quick_sort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
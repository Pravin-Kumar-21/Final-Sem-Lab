#include<stdio.h>
#include<stdlib.h>
void mergesort(int a[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid=(low+high)/2;
        mergesort(a,low, mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[], int low, int mid, int high)
{
    int b[100];
    int i=low,j,k;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    for(int s=low;s<=high;s++)
    {
        a[s]=b[s];
    }
}
void print_array(int *a,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",a[i]);

    }
    printf("\n");
}
int main()
{
    int a[]={32,12,21,45,67,45,32,2,23,4,32};
    int n=sizeof(a)/sizeof(a[0]);
    print_array(a, n);
    mergesort(a,0,n);
    print_array(a,n);
return 0;
}
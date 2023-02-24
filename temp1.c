#include<stdio.h>
#include<stdlib.h>
void merge(int [],int, int,int);
void merge_sort(int a[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[],int low, int mid,int high)
{
    int i,j,k,b[100];
    i=low;
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
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=b[i];
    }   
}
void print_array(int *arr,int size)
{
    for(int i=0;i<size;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}
int main()
{
    int a[]={1,21,2,94,32,86,11,47,6};
    print_array(a,9);
    merge_sort(a,0,9);
    print_array(a,9);

    return 0;
}
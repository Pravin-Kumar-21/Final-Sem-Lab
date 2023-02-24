#include<stdio.h>
void merge(int A[],int low, int mid, int high)
{
    int b[100];
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            b[k]=A[i];
            i++;
            k++;
        }
        else
        {
            b[k]=A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        b[k]=A[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        b[k]=A[j];
        j++;
        k++;
    }
    for(int s=low;s<=high;s++)
    {
        A[s]=b[s];
    }
}
void merge_sort(int A[],int low ,int high)
{
    int mid;
    if(low < high)
    {
        mid=(low+high)/2;
        merge_sort(A,low,mid);
        merge_sort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
void Print_Array(int *A, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d\t",A[i]);
    }
    printf("\n");
}
int main()
{
    int A[]={9,1,4,14,8,7,5,6};
    Print_Array(A,8);
    merge_sort(A,0,8);
    Print_Array(A,8);
return 0;
}
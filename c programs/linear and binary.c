#include<stdio.h>
void linearsearch(int a[],int n, int e);
void binarysearch(int a[],int n, int e);
int i,j,n,e,choice;
int a[100];
void main()
{
    printf("enter size of the array :");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        printf("enter element %d: ",i);
        scanf("%d",&a[i]);
    }
    printf("enter the element you want to search : ");
    scanf("%d",&e);
    printf("1.linear search 2.binary search : ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        linearsearch(a,n,e);
        break;
    case 2:
        binarysearch(a,n,e);
        break;
    default:
        printf("invalid choice");
        break;
    }
    
}
void linearsearch(int a[],int n ,int e)
{
    for(i=0;i<n;i++)
    {
        if (a[i]==e)
        {
            printf("%d is found at %d",e,i);
            break;
        }
        
    }
    if(i==n)
    {
        printf("not found");
    }
    

}
void binarysearch(int a[],int n, int e)
{
    for (i = 0; i < n - 1; i++)
    {        
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;

            }
    }
    printf("sorted array :\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    

    int low=0,high=n-1,mid=(low+high)/2,flag=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(e==a[mid])
        {
            flag=1;
            break;
        }
        else if(e<a[mid])
        {
            high=mid-1;
        }
        else
        low=mid+1;
    }
    if(flag==0)
    printf("not found");
    else
    printf("%d is found and  %d ",e,mid);
}
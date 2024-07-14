#include<stdio.h>
int transpose_matrix(int t1[10][3]);
int sparse_addition(int a[10][10],int t1[10][3]);
int main()
{
    int a[10][10],t1[10][3],r,c,i,j,count=0,k=1,z,choice;
    printf("Enter the number of rows for matrix A: ");
    scanf("%d",&r);
    printf("Enter the number of columns for matrix A: ");
    scanf("%d",&c);
    printf("Enter the elements for the matrix A:");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe given matrix A is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]!=0)
            {
                t1[k][0]=i;
                t1[k][1]=j;
                t1[k][2]=a[i][j];
                k++;
                count++;
            }
        }
    }
    t1[0][0]=r;
    t1[0][1]=c;
    t1[0][2]=count;
    if(count<=((r*c)/2))
    {
        printf("\nThe given matrix is sparse matrix\n");
        printf("\nThe tuple matrix for matrix is A:\n");
        for(i=0;i<k;i++)
        {
            printf("\t%d\t%d\t%d",t1[i][0],t1[i][1],t1[i][2]);
            printf("\n");
        }
        printf("\n1.To find the transpose tuple matrix of the above given matrix");
        printf("\n2.To add another matrix with the given matrix and to display the tuple matrix of the sum");
        printf("\nPlease enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                {
                    transpose_matrix(t1);
                    break;
                }
            case 2:
                {
                    sparse_addition(a,t1);
                    break;
                }
        }

    }
    else
    {
        printf("\nThe given matrix is not sparse matrix");
    }
    return 0;
}

int transpose_matrix(int t1[10][3])
{
    int i,k,s[10][3],x=1;
    for(i=0;i<t1[0][1];i++)
    {
        for(k=1;k<=t1[0][2];k++)
        {
            if(t1[k][1]==i)
            {
               s[x][0]=t1[k][1];
               s[x][1]=t1[k][0];
               s[x][2]=t1[k][2];
               x++;
            }
        }
    }
    s[0][0]=t1[0][1];
    s[0][1]=t1[0][0];
    s[0][2]=t1[0][2];
    printf("\nThe transpose tuple matrix is:\n");
    for(i=0;i<=s[0][2];i++)
    {
        printf("\t%d\t%d\t%d",s[i][0],s[i][1],s[i][2]);
        printf("\n");
    }
    return 0;
}
int sparse_addition(int a[10][10],int t1[10][3])
{
    int r,c,count,i,j,t2[10][3],b[10][10],k=1,t3[10][3],x=1;
    printf("\nEnter the number of rows for the matrix B: ");
    scanf("%d",&r);
    printf("Enter the number of columns for the matrix B: ");
    scanf("%d",&c);
    printf("Enter the elements for matrix B:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    printf("\nThe given matrix B is:\n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("\t%d",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(b[i][j]!=0)
            {
                t2[k][0]=i;
                t2[k][1]=j;
                t2[k][2]=b[i][j];
                k++;
                count++;
            }
        }
    }
    t2[0][0]=r;
    t2[0][1]=c;
    t2[0][2]=count;
    if(count<=((r*c)/2))
    {
        printf("\nThe given matrix is sparse matrix");
        printf("\nThe tuple matrix for matrix is B:\n");
        for(i=0;i<k;i++)
        {
            printf("\t%d\t%d\t%d",t2[i][0],t2[i][1],t2[i][2]);
            printf("\n");
        }
        if(r==t1[0][0] && c==t2[0][1])
        {
            printf("\nThe matrices A and B can be added.");
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    if(a[i][j]!=0 && b[i][j]!=0)
                    {
                        t3[x][0] = i;
                        t3[x][1] = j;
                        t3[x][2] = a[i][j]+ b[i][j];
                        x++;
                    }
                    else if(a[i][j]!=0)
                    {
                        t3[x][0] = i;
                        t3[x][1] = j;
                        t3[x][2] = a[i][j];
                        x++;
                    }
                    else if(b[i][j]!=0)
                        {
                            t3[x][0] = i;
                            t3[x][1] = j;
                            t3[x][2] = t3[i][j];
                            x++;
                        }
                }
            }

            t3[0][0]=r;
            t3[0][1]=c;
            t3[0][2]=x-1;
            printf("\nThe tuple matrix representing the sum of Matrix A and Matrix B is:\n");
            for(i=0;i<x;i++)
            {
                printf("\t%d\t%d\t%d",t3[i][0],t3[i][1],t3[i][2]);
                printf("\n");
            }
        }

        else
        {
            printf("\nThe matrices A and B cannot be added");
        }
    }
    else
    {
        printf("\nThe given matrix is not sparse matrix");
        printf("\nThe matrices A and B cannot be added");
    }

    return 0;
}

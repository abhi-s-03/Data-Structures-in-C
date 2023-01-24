#include <stdio.h>
#include <stdlib.h>
void display(int a[10][3])
{
    int i;
    for (i = 0; i <= a[0][2]; i++)
    {
        printf("%d\t%d\t%d",a[i][0],a[i][1],a[i][2]);
        printf("\n");    
    }   
}    
void add(int t1[10][3],int t2[10][3],int t3[20][3])
{
    int i,j,k=1;
    if(t1[0][0]!=t2[0][0] || t1[0][1]!=t2[0][1])
    {
        printf("Addition not possible");
        exit(0);
    }
    t3[0][0]=t1[0][0];
    t3[0][1]=t1[0][1];
    i=j=1;
    while(i<=t1[0][2] && j<=t2[0][2])
    {
        if(t1[i][0]<t2[j][0])
        {
            t3[k][0]=t1[i][0];
            t3[k][1]=t1[i][1];
            t3[k][2]=t1[i][2];
            k++;
            i++;
        }
        else if(t1[i][0]>t2[j][0])
        {
            t3[k][0]=t2[j][0];
            t3[k][1]=t2[j][1];
            t3[k][2]=t2[j][2];
            k++;
            j++;
        }
        else
        {
            if(t1[i][1]<t2[j][1])
            {
                t3[k][0]=t1[i][0];
                t3[k][1]=t1[i][1];
                t3[k][2]=t1[i][2];
                k++;
                i++;
            }
            else if(t1[i][1]>t2[j][1])
            {
                t3[k][0]=t2[j][0];
                t3[k][1]=t2[j][1];
                t3[k][2]=t2[j][2];
                k++;
                j++;
            }
            else
            {
                t3[k][0]=t1[i][0];
                t3[k][1]=t1[i][1];
                t3[k][2]=t1[i][2]+t2[j][2];
                k++;
                i++;
                j++;
            }
        }
    }
    while(i<=t1[0][2])
    {
        t3[k][0]=t1[i][0];
        t3[k][1]=t1[i][1];
        t3[k][2]=t1[i][2];
        k++;
        i++;
    }
    while(j<=t2[0][2])
    {
        t3[k][0]=t2[j][0];
        t3[k][1]=t2[j][1];
        t3[k][2]=t2[j][2];
        k++;
        j++;
    }
    t3[0][2]=k-1;
}                
void transpose(int t[10][3],int tt[10][3])
{
    int i,j,l=1;
    tt[0][0]=t[0][1];
    tt[0][1]=t[0][0];
    tt[0][2]=t[0][2];
    for(i=0;i<t[0][1];i++)
    {
        for(j=1;j<=t[0][2];j++)
        {
            if(t[j][1]==i)
            {
                tt[l][0]=t[j][1];
                tt[l][1]=t[j][0];
                tt[l][2]=t[j][2];
                l++;
            }
        }
    }
}
void tuple(int a[10][10],int t1[10][3],int m,int n)
{
    int l=1,i,j;
    t1[0][0]=m;
    t1[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                t1[l][0]=i;
                t1[l][1]=j;
                t1[l][2]=a[i][j];
                l++;
            }
        }
    }
    t1[0][2]=l-1;
}
void main()
{
    int a[10][10],b[10][10],t1[10][3],t2[10][3],tt1[10][3],tt2[10][3],t3[20][3],i,j,m1,n1,m2,n2;
    printf("Enter the order of matrix 1: ");
    scanf("%d%d", &m1,&n1);
    printf("Enter the elements of matrix: ");
    for (i = 0; i < m1; i++)
        for (j = 0; j < n1; j++)
            scanf("%d", &a[i][j]);
    printf("Enter the order of matrix 2: ");
    scanf("%d%d", &m2,&n2);
    printf("Enter the elements of matrix: ");
    for (i = 0; i < m2; i++)
        for (j = 0; j < n2; j++)
            scanf("%d",&b[i][j]);
    tuple(a,t1,m1,n1);
    tuple(b,t2,m2,n2);
    printf("The sparse matrix 1 is:\n");
    display(t1);
    printf("The sparse matrix 2 is:\n");
    display(t2);
    transpose(t1,tt1);
    transpose(t2,tt2);
    printf("The transpose of sparse matrix 1 is:\n");
    display(tt1);
    printf("The transpose of sparse matrix 2 is:\n");
    display(tt2);
    add(t1,t2,t3);
    printf("The sum of sparse matrix 1 and sparse matrix 2 is:\n");
    display(t3);
}

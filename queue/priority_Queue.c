#define n 5
#include<stdio.h>
int front[n]={-1,-1,-1,-1,-1},rear[n]={-1,-1,-1,-1,-1},pq[n][n],np;
void P_Enqueue(int item,int p)
{
    if (front[p]==(rear[p]+1)%n)
    {
        printf("Queue is full");
    }
    else  
    {
        rear[p]=(rear[p]+1)%n;
        pq[p][rear[p]]=item;
    }
    if (front[p]==-1)
    {
        front[p]=0;
    }
}
void P_Dequeue()
{
    int i=0,item;
    while(front[i]==-1 && i<np)
        i++;
    if (i==np)
    {
        printf("Queue is empty");
    }
    else
    {
        item=pq[i][front[i]];
        printf("Dequeud item is %d\n",item);
        if (front[i]==rear[i])
        {
            front[i]=-1;
            rear[i]=-1;
        }
        else
        {
            front[i]=(front[i]+1)%n;
        }
    }
} 
void display()
{
    int i=0,j;
    while(i<np)
    {
        if (front[i]==-1)
        {
            printf("\nPriority level %d is empty\n",i);
        }
        else
        {
            for (j=front[i];(j%n)!=rear[i];j++)
            {
                printf("%d\t",pq[i][j%n]);
            }
            printf("%d\n",pq[i][rear[i]]);
            
        }
        i++;
    }    
}  
int main()
{
    int ch,item,x,c=1,p;
    printf("Enter no of prority levels:");
    scanf("%d",&np);
    while(c==1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the no of elements to be inserted:");
                scanf("%d",&x);
                for(int i=0;i<x;i++)
                {
                    printf("Enter the element:");
                    scanf("%d",&item);
                    printf("Enter priority:");
                    scanf("%d",&p);
                    P_Enqueue(item,p);
                }
                display();
                break;
            case 2:
                printf("Enter the no of elements to be deleted:");
                scanf("%d",&x);
                for(int i=0;i<x;i++)
                {
                    P_Dequeue();
                }
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                c=0;
                break;
            default:
                printf("Wrong choice");
        } 
    }    
} 

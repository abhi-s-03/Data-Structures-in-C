#define n 10
#include<stdio.h>
int front=-1,rear=-1,q[n];
void Enqueue(int item)
{
    if (rear==n-1)
    {
        printf("Queue is full");
    }
    else
    {
        if (front==-1)
        {
            front=0;
        }
        rear=rear+1;
        q[rear]=item;
    }
}
void Dequeue()
{
    if (front==-1)
    {
        printf("Queue is empty");
    }
    else
    {        
        printf("Deleted element is %d\n",q[front]);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=front+1;
        }
    }
} 
void display()
{
    int i;
    if (front==-1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("Queue elements are:");
        for (i=front;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }
    }
}  
int main()
{
    int ch,item,x,c=1;;
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
                    Enqueue(item);
                }
                display();
                break;
            case 2:
                printf("Enter the no of elements to be deleted:");
                scanf("%d",&x);
                for(int i=0;i<x;i++)
                {
                    Dequeue();
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

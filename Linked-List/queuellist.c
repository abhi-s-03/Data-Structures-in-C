#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head,*new,*front=NULL,*rear=NULL;

void display()
{
    if (front!=NULL)
    {
        while(front!=NULL)
        {
            printf("%d\t",front->data);
            front=front->link;
        }
        front=head->link;
    }
    else
        printf("Queue Empty");    
}

void Enqueue(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    if (front==NULL)
    {
        head->link=new;
        front=new;
        rear=new;
    }
    else
    {
        rear->link=new;
        rear=new;
    }
}

void Dequeue()
{
    if(front==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        head->link=front->link;
        printf("Deleted element is %d",front->data);
        free(front);
        front=head->link;
    }
}
void main()
{
    int c=1,ch,x;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=-1;
    head->link=NULL;
    while(c==1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
            {
                
                printf("Enter the element:");
                scanf("%d",&x);
                Enqueue(x);
                break;
            }
            case 2:
            {
                Dequeue();
                break;
            }   
            
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                c=0;
                front=head;
                while(front!=NULL)
                {
                    new=front->link;
                    free(front);
                    front=new;
                }
                break;
            }
            default:
            {
                printf("Invalid choice");
            }
            
        } 
    }    
} 
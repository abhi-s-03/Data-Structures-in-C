#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head,*new,*top=NULL;

void display()
{
    if (top!=NULL)
    {
        while(top!=NULL)
        {
            printf("%d\t",top->data);
            top=top->link;
        }
        top=head->link;
    }
    else
        printf("Stack Empty");    
}

void push(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=top;
    top=new;
    head->link=top;
}

void pop()
{
    if(head->link==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        head->link=top->link;
        printf("Deleted element is %d",top->data);
        free(top);
        top=head->link;
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
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
            {
                
                printf("Enter the element:");
                scanf("%d",&x);
                push(x);
                break;
            }
            case 2:
            {
                pop();
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
                top=head;
                while(top!=NULL)
                {
                    new=top->link;
                    free(top);
                    top=new;
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
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*head,*ptr,*new,*temp;

void display()
{
    ptr=head->link;
    if (ptr!=NULL)
    {
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
    }
    else
        printf("Empty");    
}
void insert_front(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=head->link;
    head->link=new;
}
void insert_end(int x)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
       ptr=ptr->link;
    }
    ptr->link=new;
}
void insert_pos(int x,int key)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->link=NULL;
    ptr=head;
    while(ptr->data!=key && ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    new->link=ptr->link;
    ptr->link=new;
}
void delete_front()
{
    ptr=head;
    if(head->link==NULL)
    {
        printf("List is empty");
    }
    else
    {
        ptr=ptr->link;
        head->link=ptr->link;
        free(ptr);
    }
}
void delete_end()
{
    ptr=head;
    if (head->link!=NULL)
    {
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        free(ptr->link);
        ptr->link=NULL;
    }
    else
    {
        printf("List is empty");
    }
}
void delete_pos(int key)
{
    ptr=head;
    if(head->link!=NULL)
    {
        while(ptr->link->data!=key && ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        if(ptr->link==NULL)
        {
            printf("Element not found");
        }
        else
        {
            temp=ptr->link;
            ptr->link=temp->link;
            free(temp);
        }
    }
    else
        printf("List is empty");
}
void main()
{
    int c=1,ch,x,key;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=-1;
    head->link=NULL;
    while(c==1)
    {
        printf("\n1.Insert at front\n2.Insert at end\n3.Insert at position\n4.Delete at front\n5.Delete at end\n6.Delete at position\n7.Display\n8.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1:
            {
                
                printf("Enter the element:");
                scanf("%d",&x);
                insert_front(x);
                break;
            }
            case 2:
            {
                
                printf("Enter the element:");
                scanf("%d",&x);
                insert_end(x);
                break;
            }   
            case 3:
            {
                
                printf("Enter the element:");
                scanf("%d",&x);
                printf("Enter the key:");
                scanf("%d",&key);
                insert_pos(x,key);
                break;
            }
            case 4:
            {
                delete_front();
                break;
            }
            case 5:
            {
                delete_end();
                break;
            }
            case 6:
            {
                
                printf("Enter the key:");
                scanf("%d",&key);
                delete_pos(key);
                break;
            }
            case 7:
            {
                display();
                break;
            }
            case 8:
            {
                c=0;
                ptr=head;
                while(ptr!=NULL)
                {
                    temp=ptr->link;
                    free(ptr);
                    ptr=temp;
                }
                break;
            }
            default: printf("Invalid choice");
            
        } 
    }    
} 

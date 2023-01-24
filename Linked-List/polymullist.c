#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *link;
}*head1,*head2,*head3,*ptr1,*ptr2,*ptr3,*new,*temp;
void main()
{
    int n1,n2,i,coeff,exp,c=0;
    head1=(struct node*)malloc(sizeof(struct node));
    head2=(struct node*)malloc(sizeof(struct node));
    head3=(struct node*)malloc(sizeof(struct node));
    head1->link=NULL;
    head2->link=NULL;
    head3->link=NULL;
    printf("Enter the number of terms in first polynomial:");
    scanf("%d",&n1);
    printf("Enter first polynomial:");
    for(i=0;i<n1;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%dx^%d+",&new->coeff,&new->exp);
        if (head1->link==NULL)
        {
            head1->link=new;
            ptr1=new;
        }
        else
        {
            ptr1->link=new;
            ptr1=new;
        }
        
    }
    ptr1->link=NULL;
    printf("Enter the number of terms in second polynomial:");
    scanf("%d",&n2);
    printf("Enter second polynomial:");
    for(i=0;i<n2;i++)
    {
        
        new=(struct node*)malloc(sizeof(struct node));
        scanf("%dx^%d+",&new->coeff,&new->exp);
        if (head2->link==NULL)
        {
            head2->link=new;
            ptr2=new;
        }
        else
        {
            ptr2->link=new;
            ptr2=new;
        }
    }
    ptr2->link=NULL;
    ptr1=head1->link;
    while(ptr1!=NULL)
    {
        ptr2=head2->link;
        while(ptr2!=NULL)
        {
            
            coeff=ptr1->coeff*ptr2->coeff;
            exp=ptr1->exp+ptr2->exp;
            c=0;
            ptr3=head3->link;
            while(ptr3!=NULL)
            {
                if (ptr3->exp==exp)
                {
                    ptr3->coeff+=coeff;
                    c=1;
                    break;
                }
                temp=ptr3;
                ptr3=ptr3->link;  
            }
            if (c==0)
            {
                new=(struct node*)malloc(sizeof(struct node));
                new->coeff=coeff;
                new->exp=exp;
                new->link=NULL;
                if (head3->link==NULL)
                    head3->link=new;
                else
                    temp->link=new;
            }
            ptr2=ptr2->link;
            
        }
        ptr1=ptr1->link;
    }
    ptr1=head1->link;
    free(head1);
    printf("Polynomial 1:");
    while(ptr1!=NULL)
    {
        if (ptr1->coeff!=0)
        {
            printf("%dx^%d",ptr1->coeff,ptr1->exp);
        }
        if(ptr1->link!=NULL && ptr1->link->coeff>0)
            printf("+");
        new=ptr1;    
        ptr1=ptr1->link;
        free(new);
    }
    ptr2=head2->link;
    free(head2);
    printf("\nPolynomial 2: ");
    while(ptr2!=NULL)
    {
        if (ptr2->coeff!=0)
        {
            printf("%dx^%d",ptr2->coeff,ptr2->exp);
        }
        if(ptr2->link!=NULL && ptr2->link->coeff>0)
            printf("+");
        new=ptr2;    
        ptr2=ptr2->link;
        free(new);
    }    
    ptr3=head3->link;
    free(head3);
    printf("\nThe polynomial after multiplication is ");
    while(ptr3!=NULL)
    {
        if (ptr3->coeff!=0)
        {
            printf("%dx^%d",ptr3->coeff,ptr3->exp);
        }
        if(ptr3->link!=NULL && ptr3->link->coeff>0)
            printf("+");
        new=ptr3;    
        ptr3=ptr3->link;
        free(new);
    }
}

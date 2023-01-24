#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coeff;
    int expx;
    int expy;
    struct node *link;
}*head1,*head2,*head3,*ptr1,*ptr2,*ptr3,*new;

void checky()
{
    if(ptr1->expy>ptr2->expy)
    {
        ptr3->coeff=ptr1->coeff;
        ptr3->expx=ptr1->expx;
        ptr3->expy=ptr1->expy;
        ptr1=ptr1->link;

    }
    else if( ptr1->expy<ptr2->expy)
    {
        ptr3->coeff=ptr2->coeff;
        ptr3->expx=ptr2->expx;
        ptr3->expy=ptr2->expy;
        ptr2=ptr2->link;
    }
    else
    {
        ptr3->coeff=ptr1->coeff+ptr2->coeff;
        ptr3->expx=ptr1->expx;
        ptr3->expy=ptr1->expy;
        ptr1=ptr1->link;
        ptr2=ptr2->link;
    }
}
void main()
{
    int n1,n2,i;
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
        scanf("%dx^%dy^%d+",&new->coeff,&new->expx,&new->expy);
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
        scanf("%dx^%dy^%d+",&new->coeff,&new->expx,&new->expy);
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
    ptr2=head2->link;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        if (head3->link==NULL)
        {
            head3->link=new;
            ptr3=new;
        }
        else
        {
            ptr3->link=new;
            ptr3=new;
        }
        if(ptr1->expx>ptr2->expx)
        {
            checky();
        }
        else if( ptr1->expx<ptr2->expx )
        {
            checky();
        }
        else
        {
            checky();
        }
    }
    while(ptr1!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        if (head3->link==NULL)
        {
            head3->link=new;
            ptr3=new;
        }
        else
        {
            ptr3->link=new;
            ptr3=new;
        }
        ptr3->coeff=ptr1->coeff;
        ptr3->expx=ptr1->expx;
        ptr3->expy=ptr1->expy;
        ptr1=ptr1->link;

    }
    while(ptr2!=NULL)
    {
        new=(struct node*)malloc(sizeof(struct node));
        if (head3->link==NULL)
        {
            head3->link=new;
            ptr3=new;
        }
        else
        {
            ptr3->link=new;
            ptr3=new;
        }
        ptr3->coeff=ptr2->coeff;
        ptr3->expx=ptr2->expx;
        ptr3->expy=ptr2->expy;
        ptr2=ptr2->link;
    }
    ptr3->link=NULL;
    ptr1=head1->link;
    free(head1);
    printf("Polynomial 1:");
    while(ptr1!=NULL)
    {
        if (ptr1->coeff!=0)
        {
            printf("%dx^%dy^%d",ptr1->coeff,ptr1->expx,ptr1->expy);
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
            printf("%dx^%dy^%d",ptr2->coeff,ptr2->expx,ptr2->expy);
        }
        if(ptr2->link!=NULL && ptr2->link->coeff>0)
            printf("+");
        new=ptr2;    
        ptr2=ptr2->link;
        free(new);
    }    
    ptr3=head3->link;
    free(head3);
    printf("\nThe polynomial after addition is ");
    while(ptr3!=NULL)
    {
        if (ptr3->coeff!=0)
        {
            printf("%dx^%dy^%d",ptr3->coeff,ptr3->expx,ptr3->expy);
        }
        if(ptr3->link!=NULL && ptr3->link->coeff>0)
            printf("+");
        new=ptr3;    
        ptr3=ptr3->link;
        free(new);
    }
}

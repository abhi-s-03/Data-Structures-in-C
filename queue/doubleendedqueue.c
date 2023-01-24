# define MAX 3
# include <stdio.h>
int dequeue_arr[MAX];
int front = -1, rear=-1;
void InsertAtFront (int data)
{
    if (front ==(rear +1)%MAX)
    {
        printf("\n Queue is full");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = MAX - 1 ;
    else 
        front = front-1;
    dequeue_arr[front] = data ;

}
void InsertAtRear( int data )
{   
    if (front ==(rear +1)%MAX)
    {
        printf("\n Queue is full");
        return;
    }
    if (rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX-1)
        rear = 0;
    else
        rear = rear+1;
    dequeue_arr[rear] = data ;
}
void DeleteAtFront()
{
    if (front == -1)
    {
        printf("\n Queue is empty");
        return ;
    }
    int data = dequeue_arr[front];
    printf("\n Element deleted from the queue is  %d", data);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX -1)
        front = 0;
    else
        front = front+1;
}
void DeleteAtRear()
{
    if (front == -1)
    {
        printf("\n Queue is empty");
        return ;
    }
    int data = dequeue_arr[rear];
    printf("\n Element deleted from the queue is  %d", data);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = MAX-1;
    else
        rear = rear-1;
}
void display()
{
   if (front == -1)
    {
        printf("\n Queue is Empty");
        return;
    }
    printf("\n Elements in Dequeue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",dequeue_arr[i]);
    }
    else
    {
        for (int i = front; i < MAX; i++)
            printf("%d ", dequeue_arr[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", dequeue_arr[i]);
    }
}
void main()
{
    int choice, data;
    char ans;
    do
    {
        printf("\n 1. Insert an element to the front of the queue ");
        printf("\n 2. Insert an element to the rear of the queue ");
        printf("\n 3. Delete an element from the front of the queue ");
        printf("\n 4. Delete an element from the rear of the queue ");
        printf("\n Enter a choice:");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1 : printf("\n Enter the element to be inserted to front of the queue : ");
                     scanf("%d",&data);
                     InsertAtFront(data);
                     display();
                     break;
            case 2 : printf("\n Enter the element to be inserted to rear of the queue : ");
                     scanf("%d",&data);
                     InsertAtRear(data);
                     display();
                     break;
            case 3 : DeleteAtFront();
                     display();
                     break;
            case 4 : DeleteAtRear();
                     display();
                     break;
            default: printf("\n Invalid choice");
        }
        printf("\n Do you want to repeat? (Enter Y/N) : ");
        scanf(" %c",&ans);
    } while ( ans=='y'|| ans=='Y');
}
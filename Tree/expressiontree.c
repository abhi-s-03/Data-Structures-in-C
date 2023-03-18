#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
} *root, *new, *nd[20], *q[20];

char op[20];
int top_op = -1, top_nd = -1, front = -1, rear = -1;

void push_op(char x)
{
    op[++top_op] = x;
}

void push_nd(struct node *x)
{
    nd[++top_nd] = x;
}

char pop_op()
{
    return op[top_op--];
}

struct node *pop_nd()
{
    return nd[top_nd--];
}

void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%c ", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%c ", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%c ", ptr->data);
    }
}

int pr(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else
        return 0;
}

int main()
{
    char exp[50];
    printf("Enter the expression: ");
    scanf("%s", exp);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push_op(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (op[top_op] != '(')
            {
                new = (struct node *)malloc(sizeof(struct node));
                new->data = pop_op();
                new->rchild = pop_nd();
                new->lchild = pop_nd();
                push_nd(new);
            }
            pop_op();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            while ((top_op != -1 && op[top_op] != '(') && ((exp[i] != '^' && pr(op[top_op]) >= pr(exp[i])) || (exp[i] == '^' && pr(op[top_op]) > pr(exp[i]))))
            {
                new = (struct node *)malloc(sizeof(struct node));
                new->data = pop_op();
                new->rchild = pop_nd();
                new->lchild = pop_nd();
                push_nd(new);
            }
            push_op(exp[i]);
        }
        else
        {
            new = (struct node *)malloc(sizeof(struct node));
            new->data = exp[i];
            new->lchild = NULL;
            new->rchild = NULL;
            push_nd(new);
        }
    }
    while (top_op != -1)
    {
        new = (struct node *)malloc(sizeof(struct node));
        new->data = pop_op();
        new->rchild = pop_nd();
        new->lchild = pop_nd();
        push_nd(new);
    }
    root = pop_nd();
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    return 0;
}

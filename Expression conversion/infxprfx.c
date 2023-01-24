#include <stdio.h>
#include<string.h>
char prefix[50],infix[50];
int top = -1,stack[50]; 
void push(int elem)
{ 
    stack[++top] = elem;
}
int pop() 
{ 
    return (stack[top--]);
}
int pr(char elem)
{
    switch (elem) 
    {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
void infix_to_prefix() 
{
    char ch,ele;
    int i=0,k=0;
    ch = infix[i++];
    push('(');
    while (ch !='\0') 
    {
        if (ch == '(')
            push(ch);
        else if (ch>='0'&& ch<='9')
            prefix[k++] = ch;
        else if (ch == ')')
        {
            while (stack[top] != '(')
                prefix[k++] = pop(); 
            ele=pop();    
        } 
        else
        { 
            while (pr(stack[top]) >= pr(ch)&& top!=-1)
                prefix[k++] = pop();
            push(ch);
        }
        ch = infix[i++];
    }
    while (stack[top]!='(') 
        prefix[k++] = pop();
    prefix[k] = '\0'; 
}
void reverse(char a[])
{
    int i,j;
    char temp;
    for (i=0,j=strlen(a)-1;i<j;i++,j--)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
void brackets()
{
    int i = 0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
        i++;
    }
}
int main() 
{ 
    printf("\nInput the infix expression: ");
    scanf("%s", infix);
    reverse(infix);    
    brackets();
    infix_to_prefix();
    reverse(prefix);
    printf("\nPrefix Expression: %s", prefix);
}
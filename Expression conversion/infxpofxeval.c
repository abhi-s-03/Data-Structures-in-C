#include <stdio.h>
#include<math.h>
char postfix[50],infix[50];
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

void infix_to_postfix() 
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
			postfix[k++] = ch;
		else if (ch == ')')
		{
			while (stack[top] != '(')
				postfix[k++] = pop(); 
			ele=pop();	
		} 
		else
		{ 
			if (ch!='^')
			{
				while (pr(stack[top]) >= pr(ch)&& top!=-1)
					postfix[k++] = pop();
				push(ch);
			}	
			else
				push(ch);
		}
		ch = infix[i++];
	}
	while (stack[top]!='(') 
		postfix[k++] = pop();
	postfix[k] = '\0'; 
}

int eval_postfix()
{
    char ch;
    int i = 0, op1, op2,t;
    ch = postfix[i++];
    while(ch!= 0)
	{
        if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {        
            op2 = pop()-0;
            op1 = pop()-0;
            switch(ch)
            {
                case '+' :t=op1+op2;
                break;
                case '-' :t=op1-op2;
				break;
                case '*' :t=op1*op2;
                break;
                case '/' :t=op1/op2;
                break;
				case '^' :t=pow(op1,op2);
				break;
            }
			push(t);
		
        }
        else
        {
          ch=ch-'0';
          push(ch);
		}
        ch = postfix[i++];
    }
    return stack[top];
}

int main() 
{ 
	printf("\nInput the infix expression: ");
	scanf("%s", infix);	
	infix_to_postfix();
	printf("\nGiven Infix Expression: %s \nPostfix Expression: %s", infix, postfix);
	top = -1;
	printf("\nResult of evaluation of postfix expression : %d", eval_postfix(postfix));
}
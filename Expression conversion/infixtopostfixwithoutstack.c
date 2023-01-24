#include <stdio.h>
#include<string.h>
char Array[50],s[30];
char ch,temp;
int c=0,f[5],b[5];
void swap(char Arr[],int a,int b)
{
    temp=Arr[a];
    Arr[a]=Arr[b];
    Arr[b]=temp;
}
void infix_to_postfix(char Arr[])
{
    int j,c=0;
    for (int i=strlen(Arr)-1;i>=0;i--)
    {
        if (Arr[i]==')')
            {
                c++;
                while(c>0)
                {    
                    i--;
                    if (Arr[i]==')')
                        c++;
                    else if (Arr[i]=='(')
                        c--;
                }  
                      
            }   
        if (Arr[i]=='^')
        {
            ch=Arr[i+1];
            j=i+1;
            while(ch!='+'&& ch!='-'&& ch!='*'&& ch!='/'&& ch!='\0')
            {
                if (ch=='(')
                {
                    c=0;
                    do
                    {
                        if (ch=='(')
                            c++;
                        else if (ch==')')
                            c--;
                        swap(Arr,j-1,j);
                        j++;
                        ch=Arr[j];
                    }
                    while(c>0);
                }    
                else
                {    
                    swap(Arr,j-1,j);
                    j++;
                    ch=Arr[j];
                }    
            }
            
        }
    }
    c=0;
    for(int i=0;i<strlen(Arr)-1;i++)
    {
        if (Arr[i]=='(')
            {
                c++;
                while(c>0)
                {
                    i++;
                    if (Arr[i]=='(')
                        c++;
                    else if (Arr[i]==')')
                        c--;
                }        
            } 
        if(Arr[i]=='*'||Arr[i]=='/')
        {
            ch=Arr[i+1];
            j=i+1;
            while(ch!='+'&& ch!='-'&& ch!='*'&& ch!='/'&& ch!='\0')
            {
                if (ch=='(')
                {
                    c=0;
                    do
                    {
                        if (ch=='(')
                            c++;
                        else if (ch==')')
                            c--;
                        swap(Arr,j-1,j);
                        j++;
                        ch=Arr[j];
                    }
                    while(c>0);
                }
                else
                {
                    swap(Arr,j-1,j);
                    j++;
                    ch=Arr[j];
                }   
            }
            i=j-1;
        }
    }
    c=0;
    for(int i=0;i<strlen(Arr)-1;i++)
    {
        if (Arr[i]=='(')
            {
                c++;
                while(c>0)
                {
                    i++;
                    if (Arr[i]=='(')
                        c++;
                    else if (Arr[i]==')')
                        c--;
                }
            }     
        if(Arr[i]=='+'||Arr[i]=='-')
        {
            ch=Arr[i+1];
            j=i+1;
            while(ch!='+'&& ch!='-'&& ch!='\0')
            {
                if (ch=='(')
                {    
                    c=0;
                    do
                    {
                        if (ch=='(')
                            c++;
                        else if (ch==')')
                            c--;
                        swap(Arr,j-1,j);
                        j++;
                        ch=Arr[j];
                    }
                    while(c>0);
                }
                else
                {    
                    swap(Arr,j-1,j);
                    j++;
                    ch=Arr[j];
                }   
            }
            i=j-1;
        }
    }
}
int main() 
{ 
    int c=0,A[10],t=0;
    printf("\nInput the infix expression: ");
    scanf("%s",Array); 
    for(int i=0;i<strlen(Array);i++)
    {
        if(Array[i]=='(')
            A[c++]=i;
        else if(Array[i]==')')
        {
            t=0;
            for(int k=A[c-1]+1;k<i;k++)
                s[t++]=Array[k];
            s[t]='\0';
            infix_to_postfix(s); 
            t=0;
            for(int k=A[c-1]+1;k<i;k++)
                Array[k]=s[t++];    
            c--;    
        }
    } 
    infix_to_postfix(Array);
    for(int i=0;i<strlen(Array);i++)
        if (Array[i]!='(' && Array[i]!=')')
            printf("%c",Array[i]);
}    

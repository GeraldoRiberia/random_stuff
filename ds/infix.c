#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stk[100];
int top=-1;
void push(char element)
{
    stk[++top]=element;
}
char pop()
{

    return (stk[top--]);
    
}
int pr(char symbol)
{
    if(symbol=='^')
    {
    return(3);
    }
    else if(symbol=='*' || symbol=='/')
    {
    return(2);
    }
    else if(symbol=='+' || symbol=='-')
    {
    return(1);
    }
    else
    {
    return(0);
    }

}
void main()
{
    char infix[80],postfix[80];
    char ch,element;
    int i=0,k=0;
    printf("enter the infix");
    scanf("%s",infix);
    strcat(infix,")\0");
    push('(');
    while((ch=(infix[i++]))!='\0' && top != -1)
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            postfix[k++]=ch;
        }
        else if(ch==')')
        {
            while((stk[top])!='(')
                postfix[k++]=pop();
            pop();
        }
        else
        {
            while((pr(stk[top]))>=pr(ch))
            {
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(top!= -1)
    {
        postfix[k++]=pop();
    }
    printf("%s",postfix);
}
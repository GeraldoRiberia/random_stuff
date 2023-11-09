#include<stdio.h>
#include<string.h>
#include<ctype.h>
char post[100],stk[100],inf[100],sb;
int top =-1,p=0;
int pre(char ch){
    if(ch == '^')
    {
        return 3;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }else if( ch == '+' || ch == '-')
    {
        return 1;
    }else{
        return 0;
    }
}

char pop()
{
    if(top == -1)
    {
        return 1;
    }else{
    return (stk[top--]);
    }
}
void push(char ch){
    stk[top++] = ch;
}

void main()
{
    printf("Enter expression");
    gets(inf);
    push('(');
    strcat(inf,')');
    for(int i =0;(sb=inf[i])!= '\0';i++)
    {
        if(sb == '(')
        {
            push(sb);
        }else if(isalnum(sb)){
            strcat(post,sb);
        }
        else if(sb == ')'){
            while(stk[top]!='(')
            {
                strcat(post,pop());
            }
        }
       else{
            while((stk[top] >= pre(sb))){
                strcat(post,pop());
            }
        push(sb);
        }
    }
    printf("Postfix : %s",post);
}
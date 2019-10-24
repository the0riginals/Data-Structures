/*  
Add a function to calculate rank of the expression
to verify if the expression is valid or invlaid
 */


#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100


char stack[MAX];
int top = -1;


void push(char stack[], char val)
{
    if(top == MAX-1)
    {
        printf("\n!! Stack Overflow !!");
    } 
    else
    {
        stack[++top] = val;
    }
}


char pop(char stack[])
{
    char val = ' ';
    if(top == -1)
    {
        printf("\n!! Stack Underflow !!");
    }
    else
    {
        val = stack[top--];
    }
    return val;
}

int getPriority(char op)
{
    if(isalpha(op)|| isdigit(op))
        return 3;
    else if(op == '*' || op == '/' || op =='%')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
}   

void infixToPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    strcpy(target, "");
    push(stack, '(');
    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(stack, '(');
            i++;
        }
        else if(source[i] == ')')
        {
            while(stack[top] != '(')
            {
                target[j] = pop(stack);
                j++;
            }
            pop(stack);
            i++;
        }
        else
        {
            while(getPriority(stack[top]) > getPriority(source[i]))
            {
                target[j] = pop(stack);
                j++;
            }
            push(stack, source[i]);
            i++;
        }
    }
    while(stack[top] != '(')
    {
        target[j++] = pop(stack); 
    }
    target[j] = '\0'; 
}

int main()
{
    char infix[100], postfix[100];
    printf("\nEnter any infix expression : ");
    gets(infix);
    strcpy(postfix, "");
    infixToPostfix(infix, postfix);
    puts(postfix);
    return 0;
}
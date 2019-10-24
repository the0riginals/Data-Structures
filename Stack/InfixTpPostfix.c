#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char stack[], char val)
{
    if(top == MAX -1)
        printf("\n!! Stack Overflow !!");
    else
    {
        stack[++top] = val;
    }
}

char pop(char stack[])
{
    if (top == -1)
        printf("\n!! Stack Underflow !!");
    else
    {
        return stack[top--];
    }
}

int precedence(char op)
{
    if (isdigit(op) || isalpha(op))
        return 3;
    else if(op == '%' || op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
}

void main()
{
    char infix[100], postfix[100];
    printf("\nEnter any infix expression : ");
    gets(infix);
    strcpy(postfix, "");
    int i = 0, j = 0;
    while(infix[i] != '\0')
    {
        while(precedence(stack[top])>= precedence(infix[i]))
        {
            postfix[j] = pop(stack);
            j++;
        }
        push(stack, infix[i]);
        i++;
    }
    while(top != -1)
    {
        postfix[j] = pop(stack);
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix Equivalent : ");
    puts(postfix);
}
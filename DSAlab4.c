/*A Program in C for converting an Infix Expression to Postfix Expression. 
The below program support for both parenthesized and free parenthesized expressions with the 
operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.*/
#include <stdio.h>
#include <ctype.h>

#define SIZE 20

char s[SIZE];
int top = -1;

void push(char elem)
{
    s[++top] = elem;
}

char pop()
{
    return s[top--];
}

int precedence(char elem)
{
    switch (elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/':
    case '%': return 3;
    case '^':
    case '$': return 4;
    }
    return 0;
}

int main()
{
    char infix[50], postfix[50], ch;
    int i = 0, k = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            pop();
        }
        else
        {
            while (precedence(s[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '#')
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

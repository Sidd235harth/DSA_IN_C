/*Develop a Program in C for the following Stack Applications 
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^ 
*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int compute(char symbol, int op1, int op2)
{
    switch (symbol)
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    case '%': return op1 % op2;
    case '$':
    case '^': return pow(op1, op2);
    }
    return 0;
}

int main()
{
    int s[20], top = -1, op1, op2, res;
    char postfix[20], symbol;
    int i;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        symbol = postfix[i];

        if (isdigit(symbol))
            s[++top] = symbol - '0';
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }

    printf("Result = %d\n", s[top]);
    return 0;
}


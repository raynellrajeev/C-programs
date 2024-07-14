#include <stdio.h>

char A[20], P[20], S[20];
int S1[20], top = -1, top1 = -1;

int precedence(char c) 
{
    switch (c) 
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
        default:
            break;
    }
}

void postfix() 
{
    char x, y;
    int i = 0, j = 0;
    while (A[i] != '\0') 
    {
        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '0' && A[i] <= '9')) 
        {
            P[j++] = A[i];
        } 
        else if (A[i] == '(') 
        {
            S[++top] = A[i];
        } 
        else if (A[i] == ')') 
        {
          
            while (S[top] != '(')
            {
                P[j++] = S[top--];
            }
            top--;
        } 
        else 
        {
            x = A[i];
            y = S[top];
            if (top == -1 || y == '(' || precedence(x) > precedence(y))
                S[++top] = x;
            else 
            {
                while (top != -1 && y != '(' && precedence(x) <= precedence(y)) 
                {
                    P[j++] = S[top--];
                    y = S[top];
                }
                S[++top] = x;
            }
        }
        i++;
    }
    while (top != -1) 
    {
        P[j++] = S[top--];
    }
    P[j] = '\0';
    printf("Postfix Expression is %s", P);
}

void main() {
    printf("Enter Infix expression: ");
    scanf("%s", A);
    postfix();
}

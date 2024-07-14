#include<stdio.h>

int array[20],front=-1;

void push(int x)
{
    front++;
    array[front]=x;
    printf("%d pushed\n",x);
    
}

void pop()
{
    if(front==-1)
    {
        printf("Stack Underflow");
        return;
    }
    printf("%d popped from stack\n",array[front]);
    front--;
    
}

void peek()
{
    if(front==-1)
    {
        printf("Stack Underflow");
        return;
    }
    printf("%d peeked from stack\n",array[front]);
}

void display()
{
    if(front==-1)
    {
        printf("Stack Underflow");
        return;
    }
    for(int i=front;i>=0;i--)
    {
        printf("\n%d",array[i]);
    }
}


void main() 
{   
    int choice;
    printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
    scanf("%d", &choice);
    while(choice!=5)
    {
        switch(choice)
        {
            case 1:
            {
                printf("Enter the element to be pushed: ");
                int x;
                scanf("%d", &x);
                push(x);
                printf("\nstack:");
                display();
                break;

            }
            case 2:
            {
                pop();
                printf("\nstack:");
                display();
                break;

            }
            case 3:
            {
                peek();
                break;


            }
            case 4:
            {
                printf("\nstack:");
                display();
                break;
            }
            default:
            {
                printf("Invalid choice");
                break;
            }
            

        }
        printf("\n\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        scanf("%d", &choice);
        
    }

}


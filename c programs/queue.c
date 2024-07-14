#include<stdio.h>
#include <stdlib.h>
int size , q[20], i, choice , front=-1,rear=-1,element;

int push()
{ 
    
    if (rear==size-1)
    {
        printf("overflow");

    }
    else
    {
        printf("enter element to push :");
        scanf("%d",&element);
        if (front==-1)
        {
            front=0;
        }
        rear++;
        q[rear]=element;
        printf("%d pushed. \n",q[rear]);
    }
}

int pop()
{
    if (front==-1)
    {
        printf("underflow");

    }
    else
    {   
        printf("%d popped. ",q[front]);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
        
    }
}

int peek()
{
    if (front==-1 && rear==-1)
    {
        printf("empty");
    }
    else
    {
        printf("%d",q[rear]);
    }
}

int display()
{   
    if (front==-1 && rear==-1)
    {
        printf("empty");
    }
    else
    {
        for ( i = front; i <= rear; i++)
        {
            printf("\n%d",q[i]);
        }
        
    }
    
}

int clear()
{
    front=-1;
    rear=-1;
    printf("cleared");
}

int main()
{
    printf("enter size of the array :");
    scanf("%d",&size);
    
    while(1)
    {
        printf("\n1.push 2.pop 3.peek 4.display 5.clear 6.exit :\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {   
                push();
                break;
            }
            case 2:
            {    
                pop();
                break;
            }
            case 3:
            {    
                peek();
                break;
            }
            case 4:
            {    
                display();
                break;
            }
            case 5:
            {    
                clear();
                break;
            }
            case 6:
            {    
                exit(0);
                break;
            }
            
            default:
            {
                printf("invalid choice");
                break;
            }
        }
        
    }
    return 0;
}

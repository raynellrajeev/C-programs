#include<stdio.h>
#include <stdlib.h>
int size , q[20], i, choice , front=-1,rear=-1,element;

int insertb()
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

int insertf()
{ 
    
    if (front==0)
    {
        printf("overflow");

    }
    else
    {
        printf("enter element to push :");
        scanf("%d",&element);
        
        front--;
        q[front]=element;
        printf("%d pushed. \n",q[front]);
    }
}
int popf()
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
int popb()
{
    if (rear==-1)
    {
        printf("underflow");

    }
    else
    {   
        printf("%d popped. ",q[rear]);
        if (front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            rear--;
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
        printf("\n\n1.insert from front 2.insert at back 3.pop from front 4.pop from back 5.peek 6.display 7.clear 8.exit:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
            {   
                insertf();
                break;
            }
            case 2:
            {    
                insertb();
                break;
            }
            case 3:
            {    
                popf();
                break;
            }
            case 4:
            {    
                popb();
                break;
            }
            case 5:
            {    
                peek();
                break;
            }
            case 6:
            {    
                display();
                break;
            }
            
            case 7:
            {
                clear();
                break;
            }
            case 8:
            {
                exit(0);
                break;
            }
            default:
            {
                printf("\ninvalid input ");
                break;
            }
        }
        
    }
    return 0;
}
 
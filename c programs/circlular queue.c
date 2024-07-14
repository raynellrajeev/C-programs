#include<stdio.h>

int circularqueue[20],front=-1,rear=-1,choice=0,element,size;


void enqueue(int value,int size)
{
    if(((rear+1)%size)==front)
    {
        printf("queue is full\n");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        circularqueue[rear]=value;
    }
    else
    {
        rear=((rear+1)%size);
        circularqueue[rear]=value;
    }

}

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("underflow");
    }
    else if(front==rear)
    {
        printf("%d dequeued. ", circularqueue[front]);
        front=rear=-1;
    }
    else 
    {
        printf("%d dequeued. ", circularqueue[front]);
        front=((front+1)%size);
    }

}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("empty");
    }
    else
    {
        if(front<=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d",circularqueue[i]);
            }
        }
        else
        {
            for(int i=front;i<=size-1;i++)
            {
                printf("%d",circularqueue[i]);
            }
            for(int i=0;i<=rear;i++)
            {
                printf("%d",circularqueue[i]);
            }
        }
    }
}

void main()
{   
    printf("enter size of circular queue");
    scanf("%d",&size);
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.Exit\n");
    scanf("%d",&choice);
    while(choice!=4)
    {
        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be inserted:");
                scanf("%d",&element);
                enqueue(element,size);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
        }
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.Exit\n");
        scanf("%d",&choice);
        
    }
}

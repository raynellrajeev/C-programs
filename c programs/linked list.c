#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head1=NULL , *head2=NULL;

struct node *createlist(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

void display(struct node *p)
{
    if(p==NULL)
    {
        printf("\nslist: empty\n");
        return;
    }
    ptr=p;
    while(ptr!=NULL)
    {
        printf("\n%d"ptr->data,"\n");
        ptr=ptr->link;
    }
}

struct node * insert(struct node *p)
{
    int choice=0;
    printf("\n1.insert at beginning\n2.insert at end\n3.insert at a specific position\n");
    scanf("%d",&choice);
    printf("\nenter data\n");
    scanf("%d",&data);
    if(p==NULL)
    {
        p=createlist(data);

    }
    else
    {
        switch (choice)
        {
        case 1:
            p=insertbeg(p,data)
            break;
        case 2:
            p=insertend(p,data)
            break;
        case 3:
            p=insertatpos(p,data)
            break;

        default:
            printf("invalid input");
            break;
        }

    }
    
}

struct node *insertbeg(struct node *p,int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    return temp;
}

struct node *insertend(struct node *p,int data)
{
    struct node *temp, *ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    ptr=p;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    ptr->link=temp;
    temp->link=NULL;

}

struct node *insertatpos(struct node* p,int data)
{
    struct node *temp, *ptr;
    int pos,c=1;
    printf("\nenter position\n");
    scanf("%d",&pos);
    temp=p;
    ptr=(struct node *)malloc(sizeof(struct node));
    while (temp->link!=NULL)

    {
        c++;
        if(c==pos)
            break;
        temp=temp->link;
    }
    new->link=temp->link;
    temp->link=ptr;
    ptr->data=data;
}

struct node* delete(struct node *p)
{
    int choice=0,data;
    struct node *ptr,*prev;
    printf("\n1.delete at beginning\n2.delete at end\n3.delete at a specific position\n");
    scanf("%d",&choice);
    if(p==NULL)
    {
        printf("empty");

    }
    else
    {
        switch (choice)
        {
        case 1:
            p=p->link;
            break;
        case 2:
            prev=p;
            ptr=p;
            while(ptr!=NULL)
            {
                prev=ptr;
                ptr=ptr->link;
            }
            prev->link=NULL;
            break;
        case 3:
            display(p);
            int pos,c=1;
            struct node* temp;
            printf("enter position\n");
            scanf("%d",&pos);
            temp=p;
            while (temp->link!=NULL)

            {
                c++;
                if(c==pos)
                    break;
                
            }
            
            break;

        default:
            printf("invalid input");
            break;
        }

    }
}

void main()
{
    int choice, i=0;
    printf("\n1.insert\n2.delete\n3.display\n4.search\n5.merge\n6.exit");
    scanf("%d",&choice);
    while (1)
    {
        switch(choice) 
        {
            case 1:
                head1= insert(head1);
                display(head1);
                break;
            case 2:
                head1= delete(head1);
                display(head1);
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                merge();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("invalid choice");
        }
    }
    
    
}
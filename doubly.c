#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head,*tail,*newnode;

void create()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insert_beg()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}

void insert_end()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    tail->next=newnode;
    newnode->prev=tail;
}

void insert_pos()
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    int pos,i=1;
    printf("enter the position");
    scanf("%d",&pos);
    if(pos==1)
    {
        insert_beg();
    }
    else{
       temp=head;
       while(i<pos-1)
       {
           temp=temp->next;
           i++;
       }
       newnode->prev=temp;
       newnode->next=temp->next;
       temp->next=newnode;
       newnode->next->prev=newnode;

    }

}

void delete_beg()
{
    if(head==0)
    {
        printf("list is empty");
    }
    else{
        struct node *temp;
        temp=head;
        head=head->next;
        head->prev=0;
        free(temp);
    }
}

void delete_end()
{
    struct node *temp;
    temp=tail;
    tail=tail->prev;
    tail->next=0;
    free(temp);
}

void delete_pos()
{
    int pos,i=1;
    printf("enter the position");
    scanf("%d",&pos);
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("list is empty");
    }
    else if(pos==1)
    {
        delete_beg();
    }
    else{
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}

void no_of_nodes()
{
    int count=1;
    struct node *temp;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
        count++;
    }
    printf("%d Nodes are there in the list\n",count);
}

void reverse()
{
    struct node *current,*nextnode;
    current=head;
    while(current!=0)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}

int main()
{
    int ch,q;
    printf("Doubly Linked List\n");
    printf(" 1.create\n 2.counts of the nodes\n 3.Insert at Beginning\n 4.Insert at End\n 5.Insert at Particular Position\n 6.Delete at Beginning\n 7.Delete at End\n 8.Delete at Particular Position\n 9.Reverse\n");
    do
    {
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        create();
        break;
    case 2:
        no_of_nodes();
        break;
    case 3:
        insert_beg();
        break;
    case 4:
        insert_end();
        break;
    case 5:
        insert_pos();
        break;
    case 6:
        delete_beg();
        break;
    case 7:
        delete_end();
        break;
    case 8:
        delete_pos();
        break;
    case 9:
        reverse();
        break;
    default :
        break;
    }
    printf("press '1' to continue / Press '0' to Exit:");
    scanf("%d",&q);
    }while(q==1);

    //To display the elements in the nodes
    if(head==0)
    {
        printf("The List is Empty\n");
    }
     tail=head;
    while(tail!=0)
    {
        printf("%d->",tail->data);
        tail=tail->next;
    }
    return 0;
}

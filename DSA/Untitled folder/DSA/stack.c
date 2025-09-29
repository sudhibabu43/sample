#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;        
};
struct node *top=NULL;

void pop()
{
    if(top==NULL)
        printf("\nStack is empty!!");
     else
     {
      struct node *temp=top;
        top=temp->next;  
        printf("\nDeleted");
        free(temp);
     }
}

void push(int value)
{
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    if(top==NULL)
        newNode->next=NULL;
    else
        newNode->next=top;

    top=newNode;

}

void search(int value)
{   
    int flag=0;
    if(top==NULL)
        printf("Stack is empty");
    else
    {
        struct node *temp=top;
        while(temp->next!=NULL)
        {
            if(temp->data==value)
            {   
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==1)
            printf("Element is found");
        else
            printf("Element is not found");
    }
}

void display()
{
    if(top==NULL)
        printf("Stack is empty!!");
    else
    {
        struct node *temp=top;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
   
}

int main()
{
    int choice,value;

    while(1)
    {
        printf("\n\tMENU\t\n");
        printf("\n 1.Insertion\n 2.deletion\n 3.display\n 4.Search\n 5.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value :");
                    scanf("%d",&value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3:display();
                    break;
            case 4: printf("Enter the element :");
                    scanf("%d",&value);
                    search(value);
                    break;
            case 5: return 0;

            default: printf("Wrong choice!!");
                        break;
        }
    }
}

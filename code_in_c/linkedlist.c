#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last =NULL;
void insert_at_beginning(int element)
{
    struct SLL *NewNode;
    NewNode =(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data= element;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=last=NewNode;
       printf("%d WAS INSERTED AS THE FIRST NODE\n", first->data);
    }
    else
    {
        NewNode->next=first;
        first=NewNode;
        printf("%d WAS INSERTED AT BEGINNING\n",first->data);
    }

}
void insert_at_end(int element)
{
    struct SLL *NewNode;
    NewNode =(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data= element;
    NewNode->next=NULL;
    if(first==NULL)
    {
        first=last=NewNode;
    }
    else
    {
        last->next=NewNode;
        last=NewNode;
        
        printf("%d WAS INSERTED AT END\n",last->data);
    }

}
void insert_at_specificposition(int element,int pos)
{
    int i;
    struct SLL *NewNode,*temp;
    NewNode =(struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data= element;
    NewNode->next=NULL;
    if(pos<=0)
    {
        printf("Invalid Position\n");
    }
   else if(pos==1){
    insert_at_beginning(element);
   }
   else
   {
        temp=first;
        for ( i = 1; (i<pos-1) && (temp->next!=NULL) ; i++)
        {
            temp=temp->next;
        }
        if(temp==last){
            insert_at_end(element);

        }
        else
        {
            NewNode->next=temp->next;
            temp->next=NewNode;
            printf("%d is inserted at %d\n",NewNode->data,pos);

        }

    
   }

   }
   void deletion_from_the_beginning()
{
    struct SLL *NewNode,*temp;
    if (first==NULL)
    {
        printf("List is Empty\n");
    }
    else if(first->next==NULL)
    {
        temp=first;
        first=last=NULL;
        printf("%d is going to be deleted\n",temp->data);
        free(temp);
        
    }
    else
    {
        temp=first;
        first=first->next;
        
        printf("%d is going to be deleted\n",temp->data);
        free(temp);
    }

}
 void deletion_from_the_end()
{
    struct SLL *NewNode,*temp;
    if (first==NULL)
    {
        printf("List is Empty\n");
    }
    else if(first->next==NULL)
    {
        temp=first;
        first=last=NULL;
        printf("%d is going to be deleted\n",temp->data);
        free(temp);
        
    }
    else
    {
        temp=first;
        while (temp->next!=last)
        {
            temp=temp->next;
        }
        last=temp;
        temp=temp->next;
        printf("%d is going to be deleted\n",temp->data);
        free(temp);
        last->next=NULL;
        

}
  


}
void deletion_specific_position(int pos)
{
    int i;
    struct SLL *NewNode,*temp,*tempp;
    if (pos<=0 || first==NULL)
    {
        printf("Invalid Deletion");
    }
    else if (pos==1)
    {
        deletion_from_the_beginning();
    }
    else
    {
        temp=first;
        for (i=1;(i<pos-1) && (temp->next!=last);i++)
        {
            temp=temp->next;

        }
        if (temp->next==last)
        {
            deletion_from_the_end();
        }
        else{
            tempp=temp->next;
            temp->next=tempp->next;
            free(tempp);
        }
        
    }

    
    
}


void display()
{
    struct SLL *temp;
    if(first==NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        temp=first;
        while(temp!=NULL)
        {
            printf("%d ->",temp->data);
            temp=temp->next;
        }
          printf("NULL\n");
    }
}
int main()
{
     insert_at_end(5);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
   
  
    display();











    return 0;

}
#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    struct node* next;
}listnode;

/* Function to reverse the linked list */

/* Function to push a node */
void push(listnode** head_ref, int new_data)
{
    /* allocate node */
   listnode* new_node =
            (listnode*) malloc(sizeof(listnode));

    /* put in the data  */
    new_node->val  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList( listnode *head)
{
     listnode *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->val);
        temp = temp->next;
    }
}
void printBound(listnode *head,listnode *end)
{   if(head==end&&head!=NULL)
        printf("%d",head->val);
        if(head==NULL)
        perror("error empty linked list");
    listnode * temp=head;
    while(temp->next!=end)
    {printf("%d ",temp->val);
        temp=temp->next;
        }
        printf("%d ",temp->val);
    temp=temp->next;
      printf("%d ",temp->val);


}
listnode * swapNode(listnode * head,listnode * prevFirst,listnode * prevSecond)
{              if(prevFirst==NULL && prevSecond->next->next==NULL)      // if we want to swap first and last element
                {
                        listnode * second=prevSecond->next;
                        listnode * tempHead=head->next;
                        prevSecond->next=head;
                        head->next=NULL;
                        prevFirst=second;
                        second->next=tempHead;
                        return prevFirst;


                }

            if(prevFirst==NULL)         // to insert the second node to start of list
            {listnode * temp=NULL;      // if linked list has only 2 elements
                if(prevSecond->next!=NULL)
                 temp=prevSecond->next->next;

                listnode * temphead=head;
                head=prevSecond->next;
                head->next=temphead;
                prevSecond->next=temp;
                return head;
            }
           /* if(prevSecond->next==NULL)      //to insert first node to end of the list
            {   if(prevFirst==head)
                {
                listnode * temp=head->next;


                }

                listnode * temp=prevFirst->next;
                prevFirst->next=prevFirst->next->next;
                prevSecond->next=temp;
                temp->next=NULL;
                return head;

            }*/
            //if both previous pointers are adjacent to each others
            if(prevFirst->next==prevSecond)
            {   listnode * second=prevSecond->next;
            listnode * first=prevFirst->next;
                listnode * temp=prevSecond->next->next;
                prevFirst->next=second;
                second->next=prevSecond;
                prevSecond->next=first;
                first->next=temp;
                return head;



            }
            listnode * second=prevSecond->next;
            listnode * first=prevFirst->next;
            prevSecond->next=first;
            listnode * temp=first->next;
            first->next=second->next;
            prevFirst->next=second;
            second->next=temp;
            return head;




}
//warning moveToEnd gives error if only one element is there
void moveToEnd(listnode ** head,listnode **end,listnode * p,listnode *n) //n is the node to be moved to end and p is the previous node to the node to be moved
{       if(n==(*end))
        return;                 //node to be moved already at end
        if(*head==*end)
        return ;
        if(p==NULL&&n->next==NULL)
        return ; //handles if there is only one node
        if(p==NULL)     //previous is null it means n is presend node
        {
            listnode * temp=n->next;        //also handles automatically if only two nodes are there
         //   printf("%d temp0",temp->val);

            (*end)->next=n;
            n->next=NULL;


           (*end)=(*end)->next;

             // printf("%d *end",(*end)->val);
            *head=temp;
            return;
        }
        else
        {

            p->next=n->next;
            n->next=NULL;
            (*end)->next=n;
            (*end)=n;

        }

}

void insertPivot(listnode * head,listnode * end,listnode ** newHead,listnode **newEnd)
{       *newHead=head;
            *newEnd=end;
            listnode * pivot=end;
    if(head==end)
    {
            *newHead=head;
            *newEnd=end;
            return;
    }
    listnode * temp=head;
    listnode * prev=NULL;
    *newHead=head;
    int flag=0;
    while(head->val>=pivot->val)
    {       flag=1;
            moveToEnd(&head,&end,NULL,head);

    }
 //printBound(head,end);
    if((head->next==*newHead||head==*newHead||head->next==pivot)&&flag) //we have done inserting pivot
    {    *newHead=head;
        *newEnd=end;

        return;
    }


       prev=NULL;
    temp=head;
    while(temp->next!=*newEnd)
    {
        if(temp->val>=pivot->val)
       {//printf("%d in loop\n",temp->val);
       moveToEnd(&head,&end,prev,temp);
        prev=NULL;
        temp=head;
        }
        else{
        prev=temp;
        temp=temp->next;
         //printf("%d %d\n",temp->val,prev->val);
        }

   }

   if(temp->next==*newEnd)
   {          while(prev->next!=temp)
   prev=prev->next;
            if(temp->val>=pivot->val)
            {
                    moveToEnd(&head,&end,prev,temp);
            }


   }

 //printf("%d %d %d %d\n",head->val,end->val,(*newHead)->val,(*newEnd)->val);
 *newHead=head;
            *newEnd=end;
}
void quickSortList(listnode * head,listnode * end,listnode **newHead,listnode **newEnd)
{
        if(head==end)
        {
            *newHead=head;
            *newEnd=end;
            return;
        }
        if(head->next==end)
        {
            if(head->val>=end->val)


        }


}
int main()
{

 /* Start with the empty list */

    // push(&head, 100);
    // push(&head, 6);
    // push(&head, 3);
    // push(&head, 2);
    // push(&head, 1);
    struct node * head2=NULL;
    push(&head2,5);
     push(&head2, 4);
     push(&head2, 4);
     push(&head2, 2);
     push(&head2, 2);
    push(&head2, 1);
     //printList(head);
     //cout<<endl;
     printList(head2);
     cout<<endl;

   //  reverse(&head);
   //head=insertInSorted(head,head2);
  // head=mergeInSorted(head,head2);
     printf("\n Reversed Linked list \n");
    // head2=swapNode(head2,head2->next->next->next,head2);
    listnode * end=head2;
    while(end->next!=NULL)
    end=end->next;

   //moveToEnd(&head2,&end,NULL,head2);
    // printList(head2);
    insertPivot(head2,end,&head2,&end);
     printBound(head2,end);
                printf("\n");


    // getchar();

}


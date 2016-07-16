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
listnode * maxNode(listnode * head,listnode ** previous)      //pass end as null in order to traverse whole linked list
{

        listnode * temp=(listnode *)malloc(sizeof(listnode));
        temp->val=INT_MIN;
        temp->next=NULL;
        listnode * itr=head;
        listnode * prev=NULL;
        while(itr->next!=NULL)
        {
                if(itr->val>=temp->val)
                   {    (*previous)=prev;
                    temp=itr;
                   }
                    prev=itr;
                itr=itr->next;
        }
        if(itr->val>=temp->val)
                   {    (*previous)=prev;
                    temp=itr;
                   }
      /*  prev=itr;
        itr=itr->next;
        if(itr->val>=temp->val)
        {            (*previous)=prev;
                  temp=itr;
                return temp;

        }*/
        return temp;

}
listnode * findEnd(listnode *head)
{
    listnode * tmp=head;
    while(tmp->next!=NULL)
    tmp=tmp->next;
    return tmp;

}
listnode * detach(listnode **head,listnode * prevMax,listnode *Max)
{       listnode * node=Max;
        if(prevMax==NULL)
          {  (*head)=(*head)->next;
                return node;
            }
          node=Max;
          prevMax->next=Max->next;
          return node;

}
void detachAndAttachAtBegin(listnode ** sorted,listnode **head ,listnode *prevMax,listnode *Max)
{
            listnode * node=detach(head,prevMax,Max);
            if((*sorted)==NULL)
            {
                (*sorted)=node;
                node->next=NULL;
            }
            else
            {
                node->next=(*sorted);
                (*sorted)=node;
            }

}
listnode * insertionSort(listnode * head)
{
        if(head->next==NULL||head==NULL)
            return head;

        listnode * sorted=NULL;

        listnode * prevMax=NULL;
        listnode *Max=NULL;

        while(head->next!=NULL)
        {
            prevMax=NULL;
        Max=maxNode(head,&prevMax);
        detachAndAttachAtBegin(&sorted,&head,prevMax,Max);

        }
        head->next=sorted;
        sorted=head;

        return sorted;
}
int main()
{
        listnode * head=NULL;
        push(&head,13);
        push(&head,50);
        push(&head,7);
        push(&head,60);
        push(&head,4);
        push(&head,10);

        listnode *end=findEnd(head);
        listnode * prevMax=NULL;
        listnode * max=maxNode(head,&prevMax);
        head=insertionSort(head);
        printf("sorte linked list->");
        printList(head);

}

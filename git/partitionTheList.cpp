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
int main()
{

 /* Start with the empty list */
    struct node* head = NULL;

    // push(&head, 100);
    // push(&head, 6);
    // push(&head, 3);
    // push(&head, 2);
    // push(&head, 1);
    struct node * head2=NULL;
    push(&head2,100);
     push(&head2, 10);
     push(&head2, 6);
     push(&head2, 5);
     push(&head2, 4);
    push(&head2, 1);
     //printList(head);
     //cout<<endl;
     printList(head2);
     cout<<endl;

   //  reverse(&head);
   //head=insertInSorted(head,head2);
  // head=mergeInSorted(head,head2);
     printf("\n Reversed Linked list \n");
     head2=swapNode(head2,head2->next->next->next,head2);
     printList(head2);
    // getchar();

}


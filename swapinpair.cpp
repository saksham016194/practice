#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    struct node* next;
}listnode;

/* Function to reverse the linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->val  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->val);
        temp = temp->next;
    }
}
listnode * swapNodes(listnode *head,listnode * prev,listnode * first,listnode * second)
{
            if(prev==NULL)
            {
                first->next=second->next;
                second->next=first;
                return second;

            }

            first->next=second->next;
            prev->next=second;
            second->next=first;
            return head;




}
listnode * swapInPairs(listnode * head)
{
if(head==NULL||head->next==NULL)
return head;
listnode *firstptr=head;
listnode * secondptr=head->next;
listnode *tmp=head;
listnode * prev=NULL;
while(tmp->next)
{       firstptr=tmp;
        secondptr=tmp->next;
        head=swapNodes(head,prev,firstptr,secondptr);
        prev=firstptr;
        tmp=tmp->next;
       // cout<<endl;
       // printList(head);
        if(tmp==NULL)
        break;
}
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
    // push(&head2, 10);
   //  push(&head2, 6);
     //push(&head2, 5);
   //  push(&head2, 4);
    push(&head2, 1);
     //printList(head);
     //cout<<endl;
     printList(head2);
     cout<<endl;

   //  reverse(&head);
   //head=insertInSorted(head,head2);
  // head=mergeInSorted(head,head2);
     printf("\n Reversed Linked list \n");
     head2=swapInPairs(head2);
     printList(head2);
    // getchar();

}

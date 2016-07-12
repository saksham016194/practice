#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<iostream>
/* Link list node */
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
listnode * insertInSorted(listnode * head,listnode * element)
{

                if(element->val<=head->val)
                {
                    element->next=head;
                    return element;
                }
                listnode * tmp=head;
                listnode * prevtmp=NULL;
                while(element->val>tmp->val&&tmp->next)
                {
                    prevtmp=tmp;
                    tmp=tmp->next;
                }
                if(element->val<=tmp->val)
                {

                        prevtmp->next=element;
                        element->next=tmp;
                        return head;
                }
                if(tmp->next==NULL)
                {

                    tmp->next=element;
                    element->next=NULL;
                    return head;

                }

}
/* Driver program to test above function*/
listnode * mergeInSorted(listnode * first,listnode * second)
{

        listnode * dummynode=(listnode *)(malloc(sizeof(listnode)));
        dummynode->val=-1;
        dummynode->next=NULL;
        if(first==NULL)
        return second;
        if(second==NULL)
        return first;
        listnode * third=dummynode;
        if(first->next==NULL)
        {
            third=insertInSorted(second,first);     //if one of the list has only one elemment;

            return third->next;

        }
        if(second->next==NULL)
        {
            third=insertInSorted(first,second);
            return third->next;

        }
        if(!(first->next&&second->next)) //if both list have one element
        {
            if(first->val<=second->val)
            {first->next=second;
                return first;
                }
                else
                second->next=first;
                return second;

        }
        while(1)
        {

                if(first->val<=second->val)
                {
                    dummynode->next=first;
                     dummynode=dummynode->next;
                    if(first->next!=NULL)
                    {first=first->next;
                   // cout<<"first->"<<first->val<<endl;
                    }
                    else
                    break;

                }
                else
                {
                    dummynode->next=second;
                     dummynode=dummynode->next;
                     if(second->next!=NULL)
                    { second=second->next;
                    //  cout<<"second->"<<second->val<<endl;
                      }
                     else
                     break;


                }


        }
        if(first->next==NULL&&second->next==NULL)
        {
                if(first->val<=second->val)
              {  dummynode->next=first;
                    dummynode=dummynode->next;
                    dummynode->next=second;
                    return third->next;
                }
                else
                {
                dummynode->next=second;
                      dummynode=dummynode->next;
                    dummynode->next=first;
                    return third->next;
                }

        }
        if(first->next!=NULL)
        {
            dummynode->next=first->next;
                                                                    //attach rest of first
            dummynode=dummynode->next;
            //third=insertInSorted(third,second);
        }
        if(second->next!=NULL)
        {
            dummynode->next=second->next;
            dummynode=dummynode->next;                  //attach rest of second list
           // third= insertInSorted(third,first);
        }
        return third->next;

}
using namespace std;
#include<iostream>
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
   // push(&head2,100);
     push(&head2, 10);
     push(&head2, 6);
     push(&head2, 5);
     push(&head2, 4);
    push(&head2, 1);
     printList(head);
     cout<<endl;
     printList(head2);
     cout<<endl;

   //  reverse(&head);
   //head=insertInSorted(head,head2);
   head=mergeInSorted(head,head2);
     printf("\n Reversed Linked list \n");
     printList(head);
    // getchar();
}

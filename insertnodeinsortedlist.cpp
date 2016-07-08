#include<stdio.h>
#include<stdlib.h>

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
listnode * mergeSortedLists(listnode * first,listnode * second)
{

            if(first==NULL)
            return second;
            if(second==NULL)
            return first;
            if(first->next==NULL)
            {
                second=insertInSorted(second,first);
                return second;
            }
            if(second->next==NULL)
            {
                first=insertInSorted(first,second);
                return first;
            }
            listnode * firstp=first;
            listnode * secondp=second;
            listnode * thirdp=NULL;
            listnode * third=NULL;

            if(firstp->val<=secondp->val)
            {
                    thirdp=firstp;

            }
            else
            thirdp=secondp;
              //     printf("%d %d %d",third->val,first->val,second->val);
    // fflush(stdout);
            while(firstp->next&&secondp->next)
            {
                    if(firstp->val<=secondp->val)
                    {
                            third=first;
                            firstp=firstp->next;
                            third=third->next;
                            third->next=NULL;

                    }
                    else
                    {
                            third=secondp;
                            secondp=secondp->next;
                            third=third->next;
                            third->next=NULL;
                    }



            }
            if(!(firstp->next&&secondp->next))
            {

                if(firstp->val<=secondp->val)
                third->next=firstp;
                third=third->next;
                third->next=secondp;
                return thirdp;

            }
            if(firstp->next==NULL)
            {

                    if(firstp->val<=secondp->val)
                    {
                        third->next=firstp;
                        third=third->next;
                          while(second->next)
                        {
                                third->next=second;
                                second=second->next;
                                third=third->next;


                        }
                        third->next=second;
                        return thirdp;

                    }
                    else
                    {
                        while(firstp->val>secondp->val&&secondp->next)
                        {
                                third->next=secondp;
                                third=third->next;
                                secondp=secondp->next;

                        }
                        third->next=firstp;
                        third=third->next;
                        while(second->next)
                        {
                                third->next=second;
                                second=second->next;
                                third=third->next;


                        }
                        third->next=second;
                        return thirdp;

                    }

            }
              if(secondp->next==NULL)
            {

                    if(secondp->val<=firstp->val)
                    {
                        third->next=secondp;
                        third=third->next;
                          while(first->next)
                        {
                                third->next=first;
                                first=first->next;
                                third=third->next;


                        }
                        third->next=first;
                        return thirdp;

                    }
                    else
                    {
                        while(secondp->val>firstp->val&&firstp->next)
                        {
                                third->next=firstp;
                                third=third->next;
                                firstp=firstp->next;

                        }
                        third->next=secondp;
                        third=third->next;
                        while(first->next)
                        {
                                third->next=first;
                                first=first->next;
                                third=third->next;


                        }
                        third->next=first;
                        return thirdp;

                    }

            }


}
using namespace std;
#include<iostream>
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;

     push(&head, 10);
     push(&head, 6);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);
    struct node * head2=NULL;
  //  push(&head2,8);
    push(&head2, 7);
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
   head=mergeSortedLists(head,head2);
     printf("\n Reversed Linked list \n");
     printList(head);
    // getchar();
}

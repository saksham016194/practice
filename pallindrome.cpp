#include<bits/stdc++.h>
using namespace std;
typedef struct node
{
    int val;
    struct node* next;
}listnode;
 listnode * reverse(listnode * head)
 {
     listnode * temp=NULL;
     listnode * nextNode=NULL;
     while(head){

         nextNode=head->next;
         head->next=temp;
         temp=head;
         head=nextNode;
     }
     return temp;

 }
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
 void printList(listnode *head)
{
 listnode *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->val);
        temp = temp->next;
    }
}
listnode * findMidNode(listnode *head)
{

    listnode * ptr1x,*ptr2x;
    ptr1x=ptr2x=head;
    int i=0;
    while(ptr1x->next!=NULL)
    {
        if(i==0){
            ptr1x=ptr1x->next;
            i=1;
        }
        else if(i==1){
            ptr1x=ptr1x->next;
            ptr2x=ptr2x->next;
            i=0;
        }
    }
    listnode * mid=ptr2x->next;
    ptr2x->next=NULL;
    return mid;
}
int checkPallindrome(listnode * head)
{           if(head->next==NULL||head==NULL)
            return 1;
            listnode * mid=findMidNode(head);
            mid=reverse(mid);
            listnode * temp=head;
            listnode * temp2=mid;
            while(temp->next&&temp2->next)
            {
                    if(temp->val==temp2->val)
                    {
                        temp=temp->next;
                        temp2=temp2->next;

                    }
                    else
                    return 0;

            }
            if(temp->val==temp2->val)
            return 1;
            else
            return 0;


}
int main()
{

 /* Start with the empty list */
    struct node* head = NULL;

     //push(&head, 100);
     push(&head, 2);
    // push(&head, 3);
   //  push(&head, 3);
     //push(&head, 100);

     cout<<checkPallindrome(head);
}

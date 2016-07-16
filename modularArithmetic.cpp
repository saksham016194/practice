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

listnode * modularKthnode(listnode *head,int k)
{

    int i=1;
    listnode * answer=NULL;
    for(;head!=NULL;head=head->next)
    {

            if(i%k==0)
            answer=head;
            i++;

    }
    return answer;

}


int main()
{
        listnode * head=NULL;
        int i=0;
        for(i=27;i>0;i--)
        push(&head,i);
        printf("list is->\n");
        printList(head);
        listnode * answer=modularKthnode(head,8);

        printf("\nanswer=%d",answer->val);



}



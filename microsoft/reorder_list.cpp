//Given a singly linked list: A0→A1→…→An-1→An,
//reorder it to: A0→An→A1→An-1→A2→An-2→…
//Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/

void reverse(Node**head){
    Node*prev=NULL,*curr=NULL,*next=NULL;
    curr=*head;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
    return ;
}
void reorderList(Node* head) 
{
    if(head==NULL||head->next==NULL)
    return;
    Node* slow=head,*fast=head,*prev=NULL;
    while(fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL)
            fast=fast->next;
    }
    Node*temp=prev->next;
    prev->next=NULL;
    Node*head2;
    reverse(&temp);
    
    Node*curr1=head,*curr2=temp;
    Node*next1,*next2;
    //prev=head2;
    // head=slow;
    Node*s=(struct Node*)malloc(sizeof(Node));
    s->data=-1;
    s->next=NULL;
    Node*temp2=s;
    while(curr1!=NULL||curr2!=NULL){
        if(curr1){
            next1=curr1->next;
            s->next=curr1;
            s=s->next;
            //curr1->next=curr2;
            curr1=next1;
        }
        if(curr2){
            next2=curr2->next;
            s->next=curr2;
            s=s->next;
            //curr2->next=curr1;
            curr2=next2;
        }
    }
    head=temp->next;
    //cout<<curr2->data;
    // Your code here
}

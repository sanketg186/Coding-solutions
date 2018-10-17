
//Arrange consonants and vowel
//Given a singly linked list of size N containing only English Alphabets, your task is to complete the function arrangeC&V(), 
//that arranges the consonants and vowel nodes of the list it in such a way that all the vowels nodes come before the 
//consonants while maintaining the order of their arrival.

bool isvowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
        return true;
    return false;
}
struct Node* arrange(Node *head)
{
    queue<Node*>q;
    Node* prev=NULL,*cur=head;
    Node*start=head;
    if(head->next==NULL)
    return head;
    while(cur!=NULL){
        if(isvowel(cur->data)){
            if(prev==NULL){
                q.push(cur);
                cur=cur->next;
                start=start->next;
            }
            else{
                q.push(cur);
                prev->next=cur->next;
                cur=cur->next;
            }
        }
        else{
            prev=cur;
            cur=cur->next;
        }
    }
     Node* n=(Node*)malloc(sizeof(struct Node));
     n->data='1';
     n->next=NULL;
     Node*temp=n;
     while(!q.empty()){
         n->next=q.front();
         q.pop();
         n=n->next;
     }
     n->next=start;
    head=temp->next;
    return head;
   //Code here
}

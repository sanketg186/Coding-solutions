//Delete N nodes after M nodes of a linked list


void linkdelete(struct node  *head, int M, int N)
{
    struct node* strt=head;
    struct node*end=NULL;
    while(strt!=NULL){
    int i=M-1;
    while(i--&&strt!=NULL){
        strt=strt->next;
    }
    if(strt!=NULL)
    end=strt->next;
    i=N;
    while(i--&&end!=NULL){
        end=end->next;
    }
    if(strt!=NULL){
    strt->next=end;
    strt=end;
    }
    }
//Add code here   
}

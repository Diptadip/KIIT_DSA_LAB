struct Node* merge(struct Node* p, struct Node* q)
{
    struct Node* ptr=NULL;
    int k=1;
    while(p && q){
        if(k%2==0){
            insert(&ptr,q->data);
            q=q->next;
        }
        else{
            insert(&ptr,p->data);
            p=p->next;
        }
    }
    if(p){
        while(p){
            insert(&ptr,p->data);
            p=p->next;
        }
    }
    if(q){
        while(q){
            insert(&ptr,q->data);
            q=q->next;
        }
    }
    return ptr;
}
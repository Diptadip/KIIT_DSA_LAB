struct Node* divideAndRule(struct Node** Head)
{
    struct Node* p=(*head);
    struct Node* prime=NULL;
    struct Node* last_prime=NULL;
    struct Node* compo=NULL;

    while(p){
        if(isPrime(p->data)){
            insert(&prime,p->data);
        }
        else{
            insert(&compo,p->data);
        }
        p=p->next;
    }
    p=prime;
    while(p){
        last_prime=p;
        p=p->next;
    }
    last_prime->next=compo;
    return prime;
}
#include<stdio.h>
#include<stdlib.h>

#define m 11
void setDefault(int* hash){
    for(int i=0;i<m;i++){
        hash[i]=-1;
    }
}
void insert(int* hash,int element){
    int key=element%m;
    if(hash[key]==-1){
        hash[key] = element;
        printf("%d inserted at key = %d\n", element,key);
    }
    else
    {   
        printf("Collision : key %d has element %d already!\n",key,hash[key]);
        printf("Unable to insert %d\n",element);
    }
}
void search(int*hash, int element){
    int key=element%m;
    if(hash[key]==element){
        printf("Element %d present at key %d\n",element,key);
    }
    else{
        printf("Element %d not present\n");
    }
}
void delete(int*hash,int element){
    int key=element%m;
    if(hash[key]==element){
        hash[key]=-1;
        printf("Element %d deleted from key %d\n",element,key);
    }
    else{
        printf("Element %d not present\n",element);
    }
}
void print(int*hash){
    printf("printing hash table\n");
    printf("Key   ");
    for(int i=0;i<m;i++){
        printf("%3d",i);
    }
    printf("\nValue ");
    for(int i=0;i<m;i++){
        printf("%3d",hash[i]);
    }
    printf("\n");
}
int main(){
    int n,value,ch,*hash;
    hash=(int*)malloc(m*sizeof(int));
    setDefault(hash);
    printf("How many element to be entered: ");
    scanf("%d",&n);
    printf("Enter %d integers one by one...\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insert(hash,value);
    }
    do{
        printf("1.Insert\n2.Search\n3.Delete\n4.Print\n5.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insert(hash,value);
                break;
            case 2:
                printf("Enter value to search for: ");
                scanf("%d",&value);
                search(hash,value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete(hash,value);
                break;
            case 4:
                print(hash);
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong input !! try again\n");
        }
    }while (1);    
}
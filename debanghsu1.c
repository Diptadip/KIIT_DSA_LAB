#include <stdio.h>
#include <stdlib.h>
struct Poly
	{
		int coef;
		int exp;
		struct Poly *next;
	};
struct Poly *create(int e,int c)
	{
		struct Poly *n;
		n=(struct Poly*)malloc(sizeof(struct Poly));
		n->coef=c;
		n->exp=e;
		n->next=NULL;
		return n;
	}
struct Poly *insert(struct Poly *start,struct Poly *n)
	{	
		struct Poly *prev,*ptr;
		for(ptr=start;ptr!=NULL && ptr->exp>n->exp;prev=ptr,ptr=ptr->next);
		if(ptr==start)
			{
				n->next=start;
				start=n;
			}
		else
			{
				prev->next=n;
				n->next=ptr;
			}	
		return start;		
	}
void display(struct Poly *start)
	{
		struct Poly *i;
		for(i=start;i->next!=NULL;i=i->next)
			{
				printf("%dx^%d+",i->coef,i->exp);
			}
		printf("%dx^%d",i->coef,i->exp);	
	}
struct Poly *sum(struct Poly *start1,struct Poly *start2)
	{
		struct Poly *temp,*n,*start3=NULL;
		while(start1!=NULL && start2!=NULL)
			{
				if(start1->exp>start2->exp)
					{
						int c=start1->coef;
						int e=start1->exp;
						temp=create(e,c);
						start3=insert(start3,temp);
						start1=start1->next;
					}
				else if(start1->exp<start2->exp)
					{
						int c=start2->coef;
						int e=start2->exp;
						temp=create(e,c);
						start3=insert(start3,temp);
						start2=start2->next;
					}
				else
					{
						int c=start2->coef+start1->coef;
						int e=start1->exp;
						temp=create(e,c);
						start3=insert(start3,temp);
						start1=start1->next;
						start2=start2->next;	
					}		
			}
		while(start1!=NULL)
			{
				int c=start1->coef;
				int e=start1->exp;
				temp=create(e,c);
				start3=insert(start1,temp);
				start1=start1->next;
			}
		while(start2!=NULL)
			{
				int c=start2->coef;
				int e=start2->exp;
				temp=create(e,c);
				start3=insert(start2,temp);
				start2=start2->next;
			}			
		return start3;	
	}
void main()
	{
		struct Poly *start1=NULL,*start2=NULL,*start3,*n;
		int i;	
		for(i=1;i<=3;i++)
			{
				n=create(2*i,3*i);
				start1=insert(start1,n);
			}
		printf("First Expression:\n");	
		display(start1);		
		for(i=1;i<=3;i++)
			{
				n=create(2*i,3*i);
				start2=insert(start2,n);
			}
		printf("\nSecond Expression:\n");	
		display(start2);
		start3=sum(start1,start2);	
		printf("\nAfter adding them:\n");
		display(start3);
			
	}
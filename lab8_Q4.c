#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int same(char a,char b)
    {
    if(a=='['&& b==']')
        return 1;
    if(a=='{'&& b=='}')
        return 1;
    if(a=='('&& b==')')
        return 1;
    return 0;
}
int check(char *a)
    {
    char stack[10],top=-1;
        for(int j=0;j<strlen(a);j++)
            {
         if(a[j]=='['||a[j]=='{'||a[j]=='(')
              stack[++top]=a[j]; 
           if(a[j]==']'||a[j]=='}'||a[j]==')')
               {
               if(top==-1)
                   {
               return 0;
               }
               else
                   {
                   if(!same(stack[top--],a[j]))
                       {
               return 0;
               }
           }
        } 
}
    if(top!=-1)
                {
               return 0;
            }
    return 1;
}
int main() {
    char a[10];
    printf("Enter string: ");
    scanf("%s",&a);
    if(check(a)){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
    return 0;
}
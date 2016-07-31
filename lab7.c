/* 
  To implement link list as stack
  Date : 07/31/2016
  Author : Rachana Banjade*/
 
 
 #include<stdio.h>
 #include<stdlib.h>
 #include<malloc.h>
 
 struct node{
     int info;
     struct node *next;
 };
 
 typedef struct node *nodeptr;
 
 nodeptr getnode();
 void insertatfront(nodeptr*,int);
 int removefromfront(nodeptr *);
 void freenode(nodeptr);
 void displaylist(nodeptr);
 
 int main()
 {
     nodeptr p;
     p=NULL;
     insertatfront(&p,20);
      displaylist(p);
     insertatfront(&p,10);
     insertatfront(&p,12);    
     displaylist(p);
    removefromfront(&p);
	displaylist(p);
    removefromfront(&p);    
    displaylist(p);
    removefromfront(&p);
 	displaylist(p);
 	removefromfront(&p);
 }
 
 nodeptr getnode()
 {
     return (nodeptr)malloc(sizeof(nodeptr));
 }
 void freenode(nodeptr p)
 {
     free(p);
 }
 void insertatfront(nodeptr* p,int x)
 {
     nodeptr q;
    q= getnode();
     q->info =x;
    q->next = *p;
     *p=q;
     
 }
 void displaylist(nodeptr p)
 {
     nodeptr ptr= p;
     while(ptr!=NULL)
  {
       printf("%d\n",ptr->info);
       ptr = ptr->next;
  }
    
 }
 
 int removefromfront(nodeptr *p)
 {
 	
 	int x;
 	if(*p == NULL)
 	{
 		printf("\n List Underflow \n");
 		exit(0);
 	}else
 	{
 		nodeptr ptr;
 		ptr=*p;
 		*p=ptr->next;
 		x= ptr->info;
 		free(ptr);
 		return x;
 	}	
 }

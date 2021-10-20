#include<stdio.h>
#include<conio.h>
struct node
{
 int data;
 struct node *next;
};
void insert_b();
void insert_l();
void insert_pos();
void delete_b();
void delete_l();
void delete_pos();
void display();
struct node *start,*newnode,*A,*temp;
int count;
void main()
{
int ch;
clrscr();

 printf("\n1 for insert a node at beginning");
 printf("\n2 for insert a node at last");
 printf("\n3 for insert a node at specific postion");
 printf("\n4 for delete a node at beginning");
 printf("\n5 for delete a node at last");
 printf("\n6 for insert a data at specific postition");
 printf("\n7 for displays the link list");
 printf("\n8 for exit");
 while(1)
 {
 printf("\nenter your choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 insert_b();
 break;
 case 2:
 insert_l();
 break;
 case 3:
 insert_pos();
 break;
 case 4:
 delete_b();
 break;
 case 5:
 delete_l();
 break;
 case 6:
 delete_pos();
 break;
 case 7:
 display();
 break;
 case 8:
 exit();
 default :
 printf("please enter a valid choice");
 }
}
}
void insert_b()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the sdata part");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(start==NULL)
{
start=newnode;
}
else
{
newnode->next=start;
start=newnode;
}
}
void insert_l()
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the data part");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(start==NULL)
{
start=newnode;
}
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
}
void insert_pos()
{
 int pos,i=1;
 newnode=(struct node*)malloc(sizeof(struct node));
 printf("enter the data part");
 scanf("%d",&newnode->data);
 newnode->next=NULL;
 printf("enter a postion after which you want to insert a node");
 scanf("%d",&pos);
 temp=start;
 while(i<pos)
 {
 temp=temp->next;
 i++;
 }
 newnode->next=temp->next;
 temp->next=newnode;
 }
 void delete_b()
 {
 if(start==NULL)
 {
 printf("linklist is empty");
 }
 else
 {
 temp=start;
 start=temp->next;
 printf("deleted element is=%d",temp->data);
 free(temp);
 }
 }
 void delete_l()
 {
 struct node *prenode;
 if(start==NULL)
 {
 printf("linlist is empty");
 }
 else
 {
 temp=start;
 while(temp->next!=NULL)
 {
 prenode=temp;
 temp=temp->next;
 }
 if(start==temp)
 {
 start=NULL;
 }
 else
 {
 prenode->next=temp->next;
 printf("deleted element is=%d",temp->data);
 }
 free(temp);
 }
 }
 void delete_pos()
 {
 struct node *prenode;
 int i=1,pos;
 printf("enter postion number where you want to delete");
 scanf("%d",&pos);
 temp= start;
 while(i<pos)
 {
  prenode=temp;
  temp=temp->next;
  i++;
 }
  prenode->next=temp->next;
  printf("the deleted element is=%d",temp->data);
  free(temp);
}
void display()
{
A=start;
if(start==NULL)
printf("linklist is empty");
while(A!=NULL)
{
 printf("%d<-",A->data);
 A=A->next;
}
}
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
void traversal(struct node*head){
struct node *temp=head;
if(head==NULL){
    printf("The list is empty");
    return;
}
while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
}
printf("NULL");
}
struct node*insert_at_beginning(struct node*head,int v){
struct node*n=malloc(sizeof(struct node));
n->data=v;
n->next=head;
head=n;
return head;
}
struct node*insert_at_end(struct node*head,int v){
struct node*n=malloc(sizeof(struct node));
struct node*p=head;
n->data=v;
n->next=NULL;
if(head==NULL){
return n;
}
else{
while(p->next!=NULL){
    p=p->next;
}
p->next=n;
}
return head;
}
struct node*create(struct node*head){
    int n,i,v;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    printf("Enter data:");
    scanf("%d",&v);
    head=insert_at_end(head,v);
}
return head;
}
struct node*insert_at_any_position(struct node*head,int v,int pos){
    struct node*n=malloc(sizeof(struct node));
    struct node *p=head;
    int i=1;
while(i<pos-1){
    p=p->next;
    i++;
}
n->data=v;
n->next=p->next;
p->next=n;
return head;
}

int main(){
    int v;
    struct node*head=NULL;
    printf("Enter the number:");
    scanf("%d",&v);
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    head=create(head);
    printf("\nLinked list:\n");
    traversal(head);
    head=insert_at_beginning(head,v);
    printf("\nLinked list after insertion at beginning:\n");
    traversal(head);
    head=insert_at_end(head,v);
    printf("\nLinked list after insertion at end:\n");
    traversal(head);
    head=insert_at_any_position(head,v,pos);
    printf("\nLinked list after insertion at any position:\n");
    traversal(head);
    return 0;
}
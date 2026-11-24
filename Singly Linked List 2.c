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
struct node*deletion_at_beginning(struct node*head){
    struct node*p=head;
    head=head->next;
    free(p);
    return head;
}
struct node*deletion_at_end(struct node*head){
    struct node*q;
    struct node*p=head;
    while(p->next!=0){
    q=p;
    p=p->next;
    }
    q->next=NULL;
    free(p);
    return head;
}
struct node*delete_at_any_position(struct node*head,int pos){
    struct node*p=head;
    struct node*nextnode;
    int i=1;
    while(i<pos-1){
        p=p->next;
    i++;
    }
    nextnode=p->next;
    p->next=nextnode->next;
    free(nextnode);
    return head;
}
int main(){
struct node*head=NULL;
int pos;
printf("Enter position:");
scanf("%d",&pos);
head=create(head);
printf("\nLinked List:\n");
traversal(head);
head=deletion_at_beginning(head);
printf("\nLinked List after deletion at beginning:\n");
traversal(head);
head=deletion_at_end(head);
printf("\nLinked List after deletion at end:\n");
traversal(head);
head=delete_at_any_position(head,pos);
printf("\nLinked List after deletion at any position:\n");
traversal(head);
return 0;
}
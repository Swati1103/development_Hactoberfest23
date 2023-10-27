#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
  struct  node *head,*tail;

void CreateList(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=0;
    newnode->next=0;
    newnode->data=data;
    if(head==0){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void InsertAtBeg(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=0;
    newnode->data=data;
    newnode->next=head;
    head->prev=newnode; 
    head=newnode;
}

void InsertAtEnd(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=0;
    tail=newnode;
}

void InsertAtPosition(int data){
    struct node *temp;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int position=4,i=1;
    temp=head;
    while(i<position-1){
        temp=temp->next;
        i++;
    } 
    newnode->data=data;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next->prev=newnode;
}

void DeleteFromBeg(){
    struct node *temp;
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);
}

void DeleteFromEnd(){
  struct node *temp;
  temp=tail;
  tail=tail->prev;
  tail->next=0;
  free(temp);
}

void DeleteFromPosition(){
    int position=3,i=1;
    struct node *temp;
    temp=head;
    while(i<position){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void ReverseList(){
    struct node *currentnode,*nextnode;
    currentnode=head;
    while(currentnode!=0){
       nextnode=currentnode->next;
       currentnode->next=currentnode->prev;
       currentnode->prev=nextnode;
       currentnode=nextnode;
    }
    currentnode=tail;
    tail=head;
     head=currentnode;
}

void printList(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
   CreateList(3265456);
   CreateList(6536);
   CreateList(110);
   CreateList(6326889);
   CreateList(241);
   CreateList(25);
   CreateList(5112211);
   InsertAtBeg(1234);
   InsertAtBeg(4567);
   InsertAtEnd(89);
   InsertAtEnd(6789);
   InsertAtPosition(987654);
   DeleteFromBeg();
   DeleteFromEnd();
   DeleteFromPosition();
   ReverseList();
   printList();
}

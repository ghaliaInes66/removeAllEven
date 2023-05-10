#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void add_node(node **head,int val){
       	node *p=(node*)malloc(sizeof(node));
		p->data=val;
		p->next=NULL;
		if(*head==NULL)
		{
			*head=p;}
		else{
			node *q=*head;
			while(q->next!=NULL){
				q=q->next;
			}
			q->next=p;
		}	
}

void display_list(node *head){
	if(head==NULL){
		printf("list is empty");
	}
	else{
		node *p=head;
		while(p!=NULL)
		{
			printf("\n%i\n",p->data);
			p=p->next;
		}
		}
}

int length(node **head){
	if(*head==NULL){
		printf("list is empty");
		return 0;
	}
	else{
		node *p=*head;int count=0;
		while(p!=NULL){
			p=p->next;
			count++;
		}
		return count;
	}
}



void deletepos(node **head,int pos){
   if(pos<1||pos>length(&*head)) printf("INVALID POSITION ");
   else{
    if(*head==NULL) printf("empty linked list");
    else if(pos==1){
      node *p=*head;
      *head=p->next;
      free(p);
    }
    else{
      node *r=*head;int i;
      for(i=1;i<pos-1;i++){
        r=r->next;
      }
      node *p=r->next;
      r->next=p->next;
      free(p);
    }
   }
}

void removeeven(node **head,int pos){
  if(pos>length(&*head)){
   return;
  }
  else{
    node*r=*head;int i;
    for(i=1;i<pos;i++){
      r=r->next;
    }
    if(r->data%2==0){
      deletepos(&*head,pos);
      removeeven(&*head,pos);
    }
    else
  removeeven(&*head,pos+1);
  }
}



int main(){
  node *head=NULL;
 add_node(&head,2);
 add_node(&head,1);
 add_node(&head,1);
 display_list(head);
 printf("////");
 removeeven(&head,1);
 display_list(head);
}
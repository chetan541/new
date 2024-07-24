
#include <stdio.h>
#include <stdlib.h>


struct node {
  int value;
  struct node *next;
};


void print(struct node *p,int n) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
   int search(struct node *p){
    int count=1;
    while(p->next!=NULL){
    if(p->value==n){



    }

   }
}

int main() {
    int n;struct node *arr;
    int size;
    int flag=0;
    printf("enter the size\n");
    scanf("%d",&size);
  
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  struct node *four = NULL;
struct node *five = NULL;


  arr = (struct node *)malloc(size*sizeof(struct node));
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  four = malloc(sizeof(struct node));
  five = malloc(sizeof(struct node));

  
  arr[0].value=2;
  arr[1].value = 6;
  arr[2].value = 1;
arr[3].value = 5;
arr[4].value=9;



  arr[0].next = &arr[1];
  arr[1].next = &arr[2];
  arr[3].next = &arr[4];
  arr[4].next = &arr[5];
  arr[5].next = NULL;
  printf("enter 1 for search 2 for delete 3 for insertion");
  int key;
  one->value = 2;
  two->value = 6;
  three->value = 1;
  four->value=5;
  five->value=3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = four;
  four->next=five;
  five->next=NULL;



  
  head = one;
  if(key==1){
  printf("enter a element\n");
  scanf("%d",&n);
  while(arr[i].next!=NULL{
    if(arr[i].value==n){
        printf("the number is at %d position",i+1);
        flag=1;
        break;
    }

  }
  if(flag==0){
    printf("not found");
  }
  }
  if(key==2){
    printf("enter a element to delete");
    scanf("%d",&n);
    for(int i=0;i<size;i++){
    if(arr[i].value==n){
        arr[i-1].next=&arr[i+1];
        flag=1;
  }

}

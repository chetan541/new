


#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};


struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}


struct node *insert(struct node *node, int key) {

  if (node == NULL) return newNode(key);


  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
void display(struct node *root,int k) {
  if (root != NULL){
    display(root->left, k);

    
    printf("%d -> ", root->key);
    if(root->key<k){
        sum += root->key;
    }

    
    display(root->right, k);
  }
}
  struct node *minValueNode(struct node *node) {
  struct node *current = node;


  while (current && current->left != NULL)
    current = current->left;

  return current;
}
int sum(struct node *root,int k){
    if(root && k>root->key){
    while(root && k<root->key){
        root=root->right;

    }
    }

    
    
    if(root!=NULL){
        
            
          return root->key+ sum(root->left,k)+sum(root->right,k);

        

    }
    else {return 0;}
}


int main(){
    struct node *root=NULL;
    root = insert(root,8);
    insert(root,4);
    insert(root,10);
    insert(root,3);
    insert(root,6);
  
    int d,k;
    
    printf("enter a number k\n");
    scanf("%d",&k);
      display(root,);
    d=sum(root,k);


    printf("\n sum is %d",d);

}
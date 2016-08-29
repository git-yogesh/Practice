#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

struct node* newNode(int data) {
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
}

int main() {
    struct node* root = newNode(5);
    struct node* temp;
    int n=0;
    cin>>n;
    for(int i=0; i<n; i++) {
      cin>>t;
      temp = newNode(t);
      temp->next
    }
}

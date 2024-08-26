#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1=nullptr, Node* back1=nullptr){
         data = data1;
         next = next1;
         back = back1;
    }
};

Node* converttodLL(vector<int> &arr){
    int n = arr.size();

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<n;i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev =  temp;
    }
    return head;
}

Node* removeHead(Node* head){
    if(head == NULL and head->next ==  NULL) return NULL;

    Node* prev = head;
    head =  head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}


Node* removelastnode(Node* head){
    if(head == NULL and head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back =  NULL;
    prev->next = NULL;
    delete tail;

    return head;
}

Node* removefromKposition(Node* head, int k){

    if(head == NULL and k == 1) return NULL;

    Node* temp = head;
    int count = 0;

    while(temp->next != NULL){
        temp = temp->next;
        count++;
        if(count == k-1){

         Node* prev = temp->back;
         prev->next = prev->next->next;
         temp->back  =  temp->back->back;
         delete temp;
         break;
        }
    }
    return head;

}


int main(){
   vector<int> arr = {2,15,6,3,4,23};

   Node* head = converttodLL(arr);
   head = removeHead(head);
   head = removelastnode(head);
  head = removefromKposition(head,2);

   Node* temp =  head;

   while(temp != NULL){
       cout<<temp->data<<" ";
       temp = temp->next;
   }

}
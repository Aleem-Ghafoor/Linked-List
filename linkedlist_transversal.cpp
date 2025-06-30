#include<iostream>
using namespace std;

struct Node{
    int n;
    Node* next;
};

void insertdata(Node* &head, int n){

       Node* newhead = new Node();
       
        newhead->n = n;
        newhead->next = NULL;

       if(head == NULL){
            head = newhead;
       }
       else{
            
        Node* temp = head; 
            
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newhead;
       }
}

// search perticular value
/*
void search(Node* &head, int n){

    Node* temp = head;

    while(temp != NULL){
        if(temp->n == n){
            cout << "The number is found: " << temp->n;
            return;
        }
        temp = temp->next;
    }
        cout << "Not found!";
}*/

//find length

/*void length(Node* &head){
      int a = 0;
      Node* temp = head;

      while(temp != NULL){
          a++;
          temp = temp->next;
      }
      cout << "\n\nThe length is: " << a;
}*/

//update head

/* void change_head(Node* &head, Node* &newhead){
    int n;

    cout << "\nEnter the value: ";
    cin >> newhead->n;

    newhead->next = head->next;

    while(head != NULL){
        Node* temp = head;
        head = head->next;
        delete temp;

    }
} */

// delete list

void del(Node* &head){
    int n;

        cout << "\nEnter the number to remove list: ";
        cin >> n;

        Node* temp = head;
        Node* perv = NULL;

        while(temp != NULL){

            if(temp->n == n){
                
                if(temp == head){
                    head = head->next;
                    delete temp;
                }
                else{
                    perv->next = temp->next;
                    delete temp;
                }

                cout << "Delete successful!";
                return;
            }
            perv = temp;
            temp = temp->next;

        }
}

int main(){
    int n;
    Node* head = NULL;
    Node* newhead = new Node();
    
    for(int i = 0; i < 3; i++){
         cout << "\nEnter the n: ";
         cin >> n;

         insertdata(head, n);
    }

    del(head);

//Update head 

   // change_head(head, newhead);

// length

    //length(head);

// search single linked list

    /*cout << "Enter the number you want to search: ";
    cin >> n;
    search(head, n);*/

// print new head

    /* Node* temp = newhead;
       while(temp != NULL){
       cout << "\nThe n is: " << temp->n;
       temp = temp->next;
       }*/

//print data

     Node* temp = head;
       while(temp != NULL){
       cout << "\nThe n is: " << temp->n;
       temp = temp->next;
       } 
    
    return 0;
}
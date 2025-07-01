#include<iostream>
#include<string>
using namespace std;

class Node{

    private:

        string name;
        int age;
        Node* next;
        Node* prev;

    public:

// insert data        
        void insertdata(Node* &head, string name, int age){
             
            Node* newhead = new Node();
            
            newhead->name = name;
            newhead->age = age;
            
            if(head == NULL)
                head =  newhead;
            else{

                Node* temp = head;

                while(temp->next != NULL)
                   temp = temp->next;

                newhead->prev = temp;
                temp->next = newhead;

            }
        }

//Replace the node
        void replace_node(Node* &head, Node* &newhead){
                
            string name;

                cout << "Enter the name to find node: ";
                cin >> name;

            Node* temp = head;
                while(temp != NULL){

                        if(temp->name == name){

                            Node* newnode = new Node;

                            cout << "Enter the name: ";
                            cin >> newnode->name;
                            cout << "Enter the age: ";
                            cin >> newnode->age;

                            newnode->next = temp->next;
                            newnode->prev = temp->prev;

                            if (temp->prev != NULL)
                                temp->prev->next = newnode;
                            else
                                head = newnode; 

                            if (temp->next != NULL)
                                temp->next->prev = newnode;

                            delete temp;
                                cout << "\nNode replaced successfully.\n";
                            return;
                        }
                    temp = temp->next;
                }

            cout << "Node not found!\n";
        }
        
//find the oldest person        
        void oldest_person(Node* head){

            int max, a = 0;

            max = head->age;

            Node* temp = head;
            Node* t = head;
            temp = temp->next;

            while(temp != NULL){

                if(max < temp->age){

                    max = temp->age;
                    t = temp;
                }

                temp = temp->next;
            }
            a++;

            display_next(t, a);
        }

//find the youngest person        
        void younest_person(Node* head){

            int min, a = 0;

            min = head->age;

            Node* temp = head;
            Node* t = head;
            temp = temp->next;

            while(temp != NULL){

                if(min > temp->age){

                    min = temp->age;
                    t = temp;
                }
                temp = temp->next;
            } 
            a++;

            display_next(t, a);

        }

// display forword        
        void display_next(Node* &head, int a){

          if(a > 0){
               cout << "\nThe name is: " << head->name;
               cout << "\nThe age is: " << head->age << endl;
          }  
          else{
            Node* temp = head;

            cout << "\nForword\n";

            while(temp != NULL){
                
                cout << "\n<---------------- " << ++a << " ----------------->";
                cout << "\nThe name is: " << temp->name;
                cout << "\nThe age is: " << temp->age << endl;

                temp = temp->next;
            }
           }
        }

//display previously        
        void display_prev(Node* &head, int a){
            
            Node* temp = head;
            
            while(temp->next !=NULL)  temp = temp->next;

            cout << "\nReverse\n";

            while(temp != NULL){
                
                cout << "\n<---------------- " << ++a << " ----------------->";
                cout << "\nThe name is: " << temp->name;
                cout << "\nThe age is: " << temp->age << endl;

                temp = temp->prev;
            }
        }

        void list(){
            cout << "\n-------------Chose from following-------------\n";
            cout << "\n1-Change node";
            cout << "\n2-Display forword";
            cout << "\n3-Display backword";
            cout << "\n4-Find oldest person";
            cout << "\n5-Find younest person";
            cout << "\n6-Exit";
            cout << "\n\nEnter you choice: ";
        }
};
int main(){

    string name;
    int age, a = 0, choice;
    Node* head = NULL;
    Node* newhead = new Node();

    cout << "\nPress -1 in age to stop!\n";

    while(true){ 

            cout << "\n---------------------/-----------------\n";
            cout << ++a << "-Enter your age: ";
            cin >>age;  
            if( age == -1) break;

            cout << "Enter your name: ";
            cin >>name;  
            
           head->insertdata(head, name, age);
    }

do{
    while(true){

        head->list();
        
        cin >> choice;
        if(choice > 0 && choice < 7) break;
        else cout << "\nInvalid number\n";
    }

        a = 0;
    switch(choice){

        case 1:

           head->replace_node(head, newhead);

        break;

        case 2:
                a = 0;
                head->display_next(head, a);
        break;

        case 3:
                a = 0;
                head->display_prev(head, a);
        break;

        case 4:
                head->oldest_person(head);
        break;

        case 5:
                head->younest_person(head);
        break;

        case 6:
        break;
        
        default:
            cout << "\nInvalid number\n";
    }
}while(choice != 6);
}